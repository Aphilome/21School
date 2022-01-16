FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get install -y wget \
	-y nginx \
	-y mariadb-server \
	-y vim \
	-y php-cgi php-common php-fpm php-pear php-mbstring \
	-y php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath

# Nginx
COPY ./srcs/conf_nginx /etc/nginx/sites-available/default

# SSL
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=ru/ST=tatarstan/L=kazan/CN=aphilome" \
	-keyout /etc/ssl/private/aphilomes_ssl.key -out /etc/ssl/certs/aphilomes_ssl.crt

COPY ./srcs/run.sh ./var/www/html

WORKDIR /var/www/html
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

# WordPress
RUN wget https://wordpress.org/latest.tar.gz \
	&& tar -xf latest.tar.gz \
	&& rm -f latest.tar.gz
COPY ./srcs/wp-config.php /var/www/html/wordpress/

# phpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz \
	&& tar -xf phpMyAdmin-5.1.0-english.tar.gz \
	&& mv phpMyAdmin-5.1.0-english phpmyadmin \
	&& rm -f phpMyAdmin-5.1.0-english.tar.gz
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin

CMD bash run.sh

