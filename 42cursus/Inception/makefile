DOMAIN					= "127.0.0.1 donghyuk.42.fr"
DOCKER_COMPOSE_YML		= srcs/docker-compose.yml
DOCKER_COMPOSE_DIR		= ~/.docker/cli-plugins
DOCKER_DATA_DIR			= $(HOME)/data

INSTALL_DOCKER			= /usr/bin/docker
INSTALL_DOCKER_COMPOSE	= $(DOCKER_COMPOSE_DIR)/docker-compose


all : run

run : $(INSTALL_DOCKER) $(INSTALL_DOCKER_COMPOSE) $(DOCKER_DATA_DIR) $(SET_HOSTS)
	sudo docker compose -f $(DOCKER_COMPOSE_YML) build --no-cache
	sudo docker compose -f $(DOCKER_COMPOSE_YML) up -d

$(INSTALL_DOCKER) :
	sudo apt install -y docker.io

$(INSTALL_DOCKER_COMPOSE) :
	mkdir -p $(DOCKER_COMPOSE_DIR)
	curl -SL https://github.com/docker/compose/releases/download/v2.3.3/docker-compose-linux-x86_64 -o $(INSTALL_DOCKER_COMPOSE)
	chmod +x $(INSTALL_DOCKER_COMPOSE)

$(DOCKER_DATA_DIR) :
	mkdir -p $(DOCKER_DATA_DIR)/DB
	mkdir -p $(DOCKER_DATA_DIR)/WordPress

$(SET_HOSTS) :
	if [ ! sudo grep -q $(DOMAIN)]; then
		echo $(DOMAIN) >> /etc/hosts
	fi
clean :
	sudo docker compose -f $(DOCKER_COMPOSE_YML) down
	sudo docker volume prune
	sudo rm -rf $(DOCKER_DATA_DIR)

fclean : clean
	sudo apt remove -y docker.io
	sudo rm -rf $(INSTALL_DOCKER_COMPOSE)
	sudo sed -i s/$(DOMAIN)//g /etc/hosts