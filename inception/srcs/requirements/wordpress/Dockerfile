FROM debian:buster

MAINTAINER yeslee "yeslee@student.42seoul.kr"

RUN	apt-get update && apt-get -y upgrade; \
	apt-get -y install php-fpm \
	php-mysql \
	wget \
	vim

RUN	wget https://wordpress.org/latest.tar.gz; \
	tar -xvf latest.tar.gz

COPY ./conf/run.sh ./
COPY ./conf/wp-config.php ./var/www/html/wordrpess/wp-config-sample.php
COPY ./conf/www.conf ./etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/php-fpm.conf ./etc/php/7.3/fpm/php-fpm.conf

EXPOSE	9000

ENTRYPOINT ["bash", "run.sh"]
