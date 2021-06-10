FROM	debian:buster

RUN		apt-get update && apt-get -y upgrade; \
		apt-get -y install mariadb-server \
		vim
COPY	./conf/run.sh ./

EXPOSE	3306

ENTRYPOINT	["bash", "run.sh"]
