<?php
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'ft_server' );

/** MySQL database username */
define( 'DB_USER', 'aphilome' );

/** MySQL database password */
define( 'DB_PASSWORD', 'aphilome' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
	define('AUTH_KEY',         '{Q1:m+qc+@R E8rfiPXl|dv/PE{:MQFap[3l-CuJV|=(T,GGS|A$AVXz9<[-~1-V');
	define('SECURE_AUTH_KEY',  '9Q2+J1Wl.Mn%(Bvw%/.HXGY+p&jPupK%2aS=FFlPy]p(C1GKVG]L|Y0!LIxtqh[D');
	define('LOGGED_IN_KEY',    '%LKD2;X+6N7~3?x6v^Y_!}O=gDWH&e3/>70gQ~9-Pln6:`e>>iG-K^8rITY7m~?0');
	define('NONCE_KEY',        ')0~T{u6BwwqEpwB*DVyv2,#L v7BuJ^{3 Ma[EwoPS-(U`_Ho?rl/4nwkcP=$0 a');
	define('AUTH_SALT',        'Z3-v-Y:Sg8M~,wyXQt,g,@LA6QFc8.xWD(+Zebd~:6l]+!jL,J7)g{JEO%&XW.6I');
	define('SECURE_AUTH_SALT', ')c,p8pHT(|7Tqm%*E1^Gh+w(x.IKNzpY2$(DG(5Nv8Iwl3DpB;cfE?vM0o]3x7a<');
	define('LOGGED_IN_SALT',   '4[B`g1$5@x<P9~,xFrpumo_w>7X+Qc(<yX$t]xDR$@(dg;Qpe:+0ULq;]+DQ<B3-');
	define('NONCE_SALT',       'Bt1.b($)>NrKm `!8m3VO!F/VBi$J{+G&!srd)jfW)VfVT%}@GT!UMe-WR<M6b~o');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
