#!/bin/sh

if [ -d "/run/mysqld" ]; then
	echo "[i] mysqld already present, skipping creation"
	chown -R mysql:mysql /run/mysqld
else
	echo "[i] mysqld not found, creating...."
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "[i] mysql_install_db..."
	mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null

	MYSQL_DATABASE=${MYSQL_DATABASE:-""}
	MYSQL_USER=${MYSQL_USER:-""}
	MYSQL_USER_PASSWORD=${MYSQL_USER_PASSWORD:-""}

	tfile=`mktemp`
	if [ ! -f "$tfile" ]; then
	    return 1
	fi

	cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES ;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION ;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION ;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MYSQL_ROOT_PASSWORD}') ;
DROP DATABASE IF EXISTS test ;
FLUSH PRIVILEGES ;
EOF

	if [ "$MYSQL_DATABASE" != "" ]; then
		echo "[i] Creating database: $MYSQL_DATABASE"
		echo "[i] with character set: 'utf8' and collation: 'utf8_general_ci'"
		echo "CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET utf8 COLLATE utf8_general_ci;" >> $tfile
	fi

	if [ "$MYSQL_USER" != "" ] && [ "$MYSQL_USER_PASSWORD" != "" ]; then
		echo "[i] Creating user: $MYSQL_USER with password $MYSQL_USER_PASSWORD"
		echo "GRANT ALL ON \`$MYSQL_DATABASE\`.* to '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_USER_PASSWORD';" >> $tfile
	fi

	/usr/bin/mysqld --user=mysql --bootstrap < $tfile
	rm -f $tfile
fi

exec /usr/bin/mysqld --user=mysql $@
