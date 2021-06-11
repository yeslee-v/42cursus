mv wordpress/ /var/www/html/
mv ./tmp/wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

# run in background
service php7.3-fpm start
service php7.3-fpm stop

/usr/sbin/php-fpm7.3 -F
