CMD = cd ./srcs && docker-compose
MKDIR = sudo mkdir
RMDIR = sudo rm -r

all: up

ready:
	@$(MKDIR) ~/data
	@$(MKDIR) ~/data/wp
	@$(MKDIR) ~/data/db
	@sudo chmod 777 /etc/hosts
	@echo "0.0.0.0 yeslee.42.fr" >> /etc/hosts

up:
	@$(CMD) up -d --build

down:
	@$(CMD) down

clean:
	@$(CMD) down --rmi all
	@$(RMDIR) ~/data
	@$(RMDIR) ~/data/wp
	@$(RMDIR) ~/data/db

fclean: clean
		@./srcs
		@docker system prune --volumes --force --all

re: fclean all

.PHONY: ready up down clean fclean re
