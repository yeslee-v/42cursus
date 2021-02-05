chmod 755 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/

mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
mv /tmp/default /etc/nginx/sites-available/default
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

mv phpMyAdmin-5.0.2-all-languages phpmyadmin/
mv phpmyadmin/ /var/www/html/
mv /tmp/config.inc.php /var/www/html/phpmyadmin/

#mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password

mv wordpress/ /var/www/html/
mv /tmp/wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

service mysql start

echo	"CREATE DATABASE IF NOT EXISTS wordpress;" \
		| mysql -u root --skip-password
echo	"GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '0406' WITH GRANT OPTION;" \
		| mysql -u root --skip-password
#echo	"FLUSH PRIVILEGES" | mysql -u root --skip-password

#service mysql restart

service nginx start
service php7.3-fpm start

bash
