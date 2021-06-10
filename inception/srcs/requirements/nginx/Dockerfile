FROM	debian:buster

MAINTAINER yeslee "yeslee@student.42seoul.kr"

RUN		apt-get update && apt-get -y upgrade; \
		apt-get -y install nginx \
		openssl \
		vim

# 인증서 설정
RUN	openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Yongin/O=42seoul/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

COPY	default ./tmp/
COPY	conf/nginx.conf ./tmp/

RUN		mv localhost.dev.crt etc/ssl/certs
RUN		mv localhost.dev.key etc/ssl/private

# 파일 소유자 권한 부여
RUN chown -R www-data:www-data /etc/nginx

ENTRYPOINT ["nginx", "-g", "daemon off;"]

# nginx에서는 .sh만들지 않고 바로 띄운다 >> ENTRYPOINT ["bash", "entrypoint.sh"]

#nginx -g "daemon off"
#php7.3-fpm --nodaemonize
#/var/lib/mysql/mysqld_safe --data_dir=var/lib/mysql 
