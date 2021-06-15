all:
	mkdir ~/volume-test/db
	mkdir ~/volume-test/wp
	cd srcs/
	docker-compose up -d --build

down:
	docker-compose down --rmi all

clean:
	docker rm -f $(docker ps -aq)

re: clean
	docker-compose up -d --build
