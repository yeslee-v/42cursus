FROM debian:buster

RUN	apt-get -y install php7.3-fpm \
	php-mysql \
	wget

RUN	wget https://wordpress.org/latest.tar.gz; \
	tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz

RUN	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz; \
	tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz

COPY /srcs/requirements/nginx/wordpress/conf/wp-config.php ./tmp/
COPY /srcs/requirements/nginx/wordpress/conf/config.inc.php ./tmp/

ENTRYPOINT ["bash", "run.sh"]
