#!/bin/bash

#chmod 775 /run.sh
#chown -R www-data:www-data /var/www/
#chmod -R 775 /var/www/

#service nginx start

#ssl
openssl req -x509 -newkey rsa:4096 -nodes -sha256 -keyout ft_server.key -out ft_server.crt -days 365 -subj "/C=KR/ST=SEOUL/L=SEOUL/O=42/OU=gam/CN=localhost"

mkdir /etc/nginx/ssl
mv ft_server.key /etc/nginx/ssl/
mv ft_server.crt /etc/nginx/ssl/
mv /tmp/default /etc/nginx/sites-available/default
chmod 600 /etc/nginx/ssl/*

# phpMyAdmin
mv phpMyAdmin-5.0.2-all-languages phpmyadmin/
mv phpmyadmin/ /var/www/html/
mv /tmp/config.inc.php /var/www/html/phpmyadmin/

# wordpress
mv wordpress/ /var/www/html/
mv ./tmp/wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

# create DB table for wordpress
service mysql start

echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
		| mysql -u root --skip-password
#echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '0406' WITH GRANT OPTION;" \
#		| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '0406';" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;" \
		| mysql -u root --skip-password
echo "USE wordpress;" | mysql -u root --skip-password

service mysql restart

#mysql < /var/www/html/phpmyadmin/sql/create-tables.sql

service nginx start
service php7.3-fpm start
#service php7.3-fpm status

bash
