mysql < /var/www/html/phpmyadmin/sql/create_tables.sql -u root
mysqladmin -u root -p password

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root
echo "GRANT ALL PRIVILAGES ON wordpress.* TO 'yeslee'@'%' IDENTIFIED BY '0406' WITH GRANT OPTION;" | mysql -u root
echo "FLUSH PRIVILAGES" | mysql -u root
