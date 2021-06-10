mv wordpress/ /var/www/html/
mv ./tmp/wp-config.php /var/www/html/wordpress/
chown -R www-data:www-data /var/www/html/wordpress

# run in background
php-fpm7.3 -F -R
