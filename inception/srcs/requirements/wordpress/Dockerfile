FROM debian:buster

MAINTAINER yeslee "yeslee@student.42seoul.kr"

RUN	apt-get update && apt-get -y upgrade; \
	apt-get -y install php-fpm \
	php-mysqli \
	mariadb-client \
	wget \
	vim \
	curl

RUN	wget https://wordpress.org/latest.tar.gz; \
	tar -xvf latest.tar.gz

RUN mkdir -p /var/www/html; \
	mkdir -p /run/php

RUN mv wordpress /var/www/html

COPY ./conf/run.sh ./
COPY ./conf/wp-config.php /var/www/html/wordpress/wp-config.php
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
RUN chown -R www-data:www-data /var/www

EXPOSE	9000

ENTRYPOINT ["bash", "run.sh"]
