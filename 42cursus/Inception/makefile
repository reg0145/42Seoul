DOCKER_COMPOSE_YML		= srcs/docker-compose.yml
DOCKER_COMPOSE_DIR		= ~/.docker/cli-plugins
DOCKER_DATA_DIR			= $(HOME)/data

DOMAIN				= "127.0.0.1 donghyuk.42.fr"

INSTALL_DOCKER			= /usr/bin/docker
INSTALL_DOCKER_COMPOSE	= $(DOCKER_COMPOSE_DIR)/docker-compose

all : run

run : $(DOCKER_DATA_DIR) $(DOMAIN) 
	docker-compose -f $(DOCKER_COMPOSE_YML) build --no-cache
	docker-compose -f $(DOCKER_COMPOSE_YML) up -d
up : 
	docker-compose -f $(DOCKER_COMPOSE_YML) up -d

$(DOCKER_DATA_DIR) :
	mkdir -p $(DOCKER_DATA_DIR)/DB
	mkdir -p $(DOCKER_DATA_DIR)/WordPress

$(DOMAIN) :
	@if [ ! "$$(sudo grep $(DOMAIN) /etc/hosts)" ]; then sudo sh -c 'echo $(DOMAIN) >> /etc/hosts'; fi

clean :
	docker-compose -f $(DOCKER_COMPOSE_YML) down
	docker volume rm `docker volume ls -q`
	docker system prune -a
	rm -rf $(DOCKER_DATA_DIR)

fclean : clean
	sed -i s/$(DOMAIN)//g /etc/hosts

.PHONY: all run clean fclean
