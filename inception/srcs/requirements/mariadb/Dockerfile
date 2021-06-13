FROM	debian:buster

RUN		apt-get update && apt-get -y upgrade; \
		apt-get -y install mariadb-server procps\
		vim

RUN mkdir -p /run/mysql

COPY	./conf/run.sh ./
COPY	./conf/50-server.cnf ./etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE	3306

ENTRYPOINT	["bash", "run.sh"]
