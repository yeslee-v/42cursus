FROM	debian:buster

LABEL	maintainer="yeslee@student.42seoul.kr"	

RUN		apt-get update && apt-get install -y \
		nginx\
		openssl\
		vim\
		php-fpm\
		mariadb-server\
		php-mysql\
		php-mbstring\
		wget

RUN		wget https://wordpress.org/latest.tar.gz;\
		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz;\
		tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz;\
		tar -xvf latest.tar.gz

COPY	/srcs/run.sh /
COPY	/srcs/default /
COPY	/srcs/config.inc.php /
COPY	/srcs/wp-config.php /

EXPOSE	80 443

CMD		bash run.sh
