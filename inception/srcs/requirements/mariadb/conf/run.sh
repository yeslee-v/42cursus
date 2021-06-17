#! /bin/bash

bash mysql_cmd.sh

service mysql start
mysql -u root -p$MYSQL_ROOT_PASSWORD < mysql_cmd.sql

kill -9 `ps -ef | grep mysqld | awk '{print $2}'`

sleep 2

#run in background
/usr/bin/mysqld_safe --user=root --datadir=/var/lib/mysql/ --general-log-file=/dev/stderr
