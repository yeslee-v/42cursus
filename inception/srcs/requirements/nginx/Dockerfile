FROM	debian:buster

MAINTAINER yeslee "yeslee@student.42seoul.kr"

RUN		apt-get update && apt-get -y upgrade; \
		apt-get -y install nginx \
		openssl \
		vim

RUN	openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Yongin/O=42seoul/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

COPY	default ./etc/nginx/sites-available/default

RUN		mv localhost.dev.crt etc/ssl/certs
RUN		mv localhost.dev.key etc/ssl/private

RUN chown -R www-data:www-data /etc/nginx

ENTRYPOINT ["nginx", "-g", "daemon off;"]
