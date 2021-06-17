#! /bin/bash
cat << EOF > exit.sql
exit
EOF

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

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
wp core install --path=/var/www/html/wordpress --admin_password=1234 --url=https://yeslee.42.fr --title=highway_to_hell --admin_user=yeslee --admin_email=1234@42.fr --allow-root --skip-email

# run in background
/usr/sbin/php-fpm7.3 -F
