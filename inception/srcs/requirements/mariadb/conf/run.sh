#! /bin/bash

bash mysql_cmd.sh

service mysql start
mysql -u root -p$MYSQL_ROOT_PASSWORD < mysql_cmd.sql
#sleep 2

#killall mysqld mysqld_safe

#if [[ $(ps -aux | grep mysqld | wc -l) -gt 0 ]]; then
#	killall -9 mysqld mysqld_safe
#fi

kill -9 `ps -ef | grep mysqld | awk '{print $2}'`

sleep 2

#run in background
/usr/bin/mysqld_safe --user=root --datadir=/var/lib/mysql/ --general-log-file=/dev/stderr
