FROM debian:buster

RUN	apt-get update && apt-get -y upgrade; \
	apt-get -y install php7.3-fpm \
	php7.3.mysql \
	wget \
	vim

RUN	wget https://wordpress.org/latest.tar.gz

COPY conf/wp-config.php ./tmp/

ENTRYPOINT ["bash", "run.sh"]
