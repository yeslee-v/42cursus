#!/bin/bash
mkdir /etc/nginx/ssl
mv ft_server.key /etc/nginx/ssl/
mv ft_server.crt /etc/nginx/ssl/
chmod 600 /etc/nginx/ssl/*

# echo '<?php phpinfo(); ?>' > /var/www/html/phpinfo.php
mv /wordpress/ /var/www/html/
mv wp-config.php var/www/html/wordpress
chown www-data:www-data /var/www/html/wordpress

service mysql start

mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv /phpmyadmin/ /var/www/html/
mv config.inc.php /var/www/html/phpmyadmin/
#mysql < /var/www/html/phpmyadmin/sql/create-tables.sql

echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
		| mysql -u root --skip-password
echo "CREATE USER 'root'@'%' IDENTIFIED BY 'yeslee';" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;" \
		| mysql -u root --skip-password

service nginx start
service php7.3-fpm start
service php7.3-fpm status
bash
#rm run.sh
