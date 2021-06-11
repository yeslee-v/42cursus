all:
	docker-compose up -d --build

down:
	docker-compose down --rmi all

clean:
	docker rm -f $(docker ps -aq)

re: clean
	docker-compose up -d --build
