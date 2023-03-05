FROM alpine:3.17.2

# apk install
ENV MARIADB_VER="10.6.12-r0"

RUN apk update
RUN apk add --no-cache mariadb=${MARIADB_VER} mariadb-client=${MARIADB_VER} mariadb-server-utils=${MARIADB_VER}

# mariadb
RUN sed -i 's/skip-networking/#skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i 's/#bind-address=0.0.0.0/bind-address=0.0.0.0/g' /etc/my.cnf.d/mariadb-server.cnf

# script
COPY conf/entrypoint.sh /scripts/entrypoint.sh
RUN chmod -R 755 /scripts

EXPOSE 3306

ENTRYPOINT ["/scripts/entrypoint.sh"]
