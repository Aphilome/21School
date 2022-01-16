service mysql start
mysql -e "CREATE DATABASE ft_server;"
mysql -e "CREATE USER 'aphilome'@'localhost' IDENTIFIED BY 'aphilome';"
mysql -e "GRANT ALL PRIVILEGES ON ft_server.* TO 'aphilome'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

service php7.3-fpm start
service nginx start
bash
