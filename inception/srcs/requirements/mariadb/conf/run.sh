#! /bin/bash
service mysql start

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root
echo "CREATE USER IF NOT EXISTS 'yeslee'@'%' IDENTIFIED BY '1234';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'yeslee'@'%' IDENTIFIED BY '1234' WITH GRANT OPTION;" | mysql -u root
echo "FLUSH PRIVILEGES" | mysql -u root

sleep 2

#killall mysqld mysqld_safe

#if [[ $(ps -aux | grep mysqld | wc -l) -gt 0 ]]; then
#	killall -9 mysqld mysqld_safe
#fi
kill -9 `ps -ef | grep mysql | awk '{print $2}'`
sleep 2
# run in background
/usr/bin/mysqld_safe --user=root --datadir=/var/lib/mysql/ --general-log-file=/dev/stderr
