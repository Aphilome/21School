# Secrets are generated on every container start and never stored in the repo
DB_PASSWORD=$(openssl rand -hex 16)
WP_CONFIG=/var/www/html/wordpress/wp-config.php
sed -i "s/__DB_PASSWORD__/$DB_PASSWORD/" $WP_CONFIG
for key in AUTH_KEY SECURE_AUTH_KEY LOGGED_IN_KEY NONCE_KEY AUTH_SALT SECURE_AUTH_SALT LOGGED_IN_SALT NONCE_SALT; do
	sed -i "s/__${key}__/$(openssl rand -hex 32)/" $WP_CONFIG
done
sed -i "s/__BLOWFISH_SECRET__/$(openssl rand -hex 16)/" /var/www/html/phpmyadmin/config.inc.php

service mysql start
mysql -e "CREATE DATABASE ft_server;"
mysql -e "CREATE USER 'aphilome'@'localhost' IDENTIFIED BY '$DB_PASSWORD';"
mysql -e "GRANT ALL PRIVILEGES ON ft_server.* TO 'aphilome'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

service php7.3-fpm start
service nginx start
bash
