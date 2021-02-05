FROM	debian:buster

#LABEL	maintainer="yeslee@student.42seoul.kr"

RUN		apt-get update && apt-get -y upgrade; \
		apt-get -y install nginx \
		openssl \
		vim \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		wget

RUN		wget https://wordpress.org/latest.tar.gz; \
		tar -xvf latest.tar.gz

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
		tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=gam/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

COPY	/srcs/run.sh ./
COPY	/srcs/default ./tmp
COPY	/srcs/config.inc.php ./tmp
COPY	/srcs/wp-config.php ./tmp

EXPOSE	80 443

CMD		bash run.sh
