mv phpMyAdmin-5.0.2-all-languages phpmyadmin/
mv phpmyadmin/ /var/www/html/
mv /tmp/config.inc.php /var/www/html/phpmyadmin/

mv wordpress/ /var/www/html/
mv ./tmp/wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress
