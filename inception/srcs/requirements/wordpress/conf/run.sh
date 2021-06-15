#! /bin/bash
cat << EOF > exit.sql
exit
EOF

chown -R www-data:www-data /var/www

# run in background
#service php7.3-fpm start
#service php7.3-fpm stop

connect_db()
{
	while ! mysql -hmariadb -P3306 -u$WORDPRESS_DB_USER -p$WORDPRESS_DB_PASSWORD < exit.sql ; do
		if [ $status -ge 30 ]; then
			printf "FAILED connect to db\n"
			exit 1
		fi
		printf "Trying to connect to db ($status/30)\n"
		status=$((status+1))
		sleep 1
	done
	echo -e "Success."
}

connect_db
echo "error_log = /dev/stderr" >> /etc/php/7.3/fpm/php.ini
/usr/sbin/php-fpm7.3 -F
