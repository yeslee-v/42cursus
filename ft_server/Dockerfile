FROM	debian:buster

LABEL	maintainer="yeslee@student.42seoul.kr"	

RUN		apt-get update;\
		apt-get upgrade -y;\
		apt-get install -y nginx\
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

RUN		openssl req -x509 -newkey rsa:4096 -nodes -sha256 -keyout ft_server.key -out ft_server.crt -days 365 -subj "/C=KR/ST=SEOUL/L=SEOUL/O=42/OU=yeslee/CN=localhost"

COPY	/srcs/run.sh /
COPY	/srcs/default /
COPY	/srcs/config.inc.php /
COPY	/srcs/wp-config.php /

CMD		bash run.sh

EXPOSE	80 443
