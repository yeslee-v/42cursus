M_CMD = sudo mkdir -p
R_CMD = sudo rm -r
T_CMD = cd ./srcs && docker-compose
all: ready up

ready:
	sudo chmod 777 /var/run/docker.sock
	sudo chmod 777 /etc/hosts
	$(M_CMD) /home/yeslee/data
	$(M_CMD) /home/yeslee/data/wp
	$(M_CMD) /home/yeslee/data/db
	echo "0.0.0.0 yeslee.42.fr" >> /etc/hosts

up:
	$(T_CMD) up -d --build

down:
	cd ./srcs; \
	docker-compose down

clean:
	cd ./srcs; \
	docker-compose down --rmi all
	$(R_CMD) /home/yeslee/data

fclean: clean
	docker system prune --volumes --force --all

re: fclean all

.PHONY: ready up down clean fclean re
