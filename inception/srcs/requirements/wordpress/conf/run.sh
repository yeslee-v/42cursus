mv wordpress/ /var/www/html/
chown -R www-data:www-data /var/www/html/

# run in background
service php7.3-fpm start
service php7.3-fpm stop

/usr/sbin/php-fpm7.3 -F
