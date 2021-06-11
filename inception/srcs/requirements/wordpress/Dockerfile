FROM debian:buster

RUN	apt-get update && apt-get -y upgrade; \
	apt-get -y install php7.3-fpm \
	php7.3-mysql \
	wget \
	vim

#RUN	wget https://wordpress.org/latest.tar.gz; \
#   tar -xvf https://wordpress.org/latest.tar.gz

COPY ./conf/run.sh ./
COPY ./conf/www.conf ./etc/php/7.3/fpm/pool.d/www.conf
COPY ./conf/php-fpm.conf ./etc/php/7.3/fpm/php-fpm.conf
COPY ./conf/wordpress/ /var/www/wordpress
EXPOSE	9000

ENTRYPOINT ["bash", "run.sh"]
