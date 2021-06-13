<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('WORDPRESS_DB_NAME') );

/** MySQL database username */
define( 'DB_USER', getenv('WORDPRESS_DB_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('WORDPRESS_DB_PASSWORD') );

/** MySQL hostname: borrow server  */
#define( 'DB_HOST', 'mariadb:3306' );
define( 'DB_HOST', getenv('WORDPRESS_DB_HOST') );

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
define('AUTH_KEY',         'PtuzR,&BQeqR-i!kap+-QIJ0rVz<U4>K[0:YR~&=-iuP$US,O0Co7D#EAPdx0*)v');
define('SECURE_AUTH_KEY',  '69z%8jNwphjKm_rQ)Aetr&V:,h.Xn*NR;]8`3p-Zdj?=tXY]W{1RkFJunFTT7IHu');
define('LOGGED_IN_KEY',    ')B/Yn(Z Pf!R%@8l,d3:,sO?F]xHVV0>adx5m/;wb-wu$v!%|%6U2+/LFbXg.UG_');
define('NONCE_KEY',        '*:cN^-T=daq<xanQlN$borVKb%+aB|+|`i9iTtLFn-G!<JZ^?ihgI)PlQ?7bl=:z');
define('AUTH_SALT',        '8v:v%zDa9OKvB.5{[IOGaw=Nd%~ &DfhIb}/s&(T<+dM6|i2vEMs03WTeL]q[HC1');
define('SECURE_AUTH_SALT', '`2Ij|U*:e~x+;#VwtZ-mXVJpR?D+LwE3()|a6)mu9$m:L> [W|:95<=k:1EkLJy~');
define('LOGGED_IN_SALT',   'Z~uhcE<odct4taA2UVY[KOm c^O$GTga=1ut]gev+IBnX{/QO+I+oK% `{$]C,nb');
define('NONCE_SALT',       ' ~[y~U`N83ah+)0G9fIp)*%WzdshW^NZAzN20:VIyn|o;[L4%; l9m6#aCH-CSlt');

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
define( 'WP_DEBUG', true );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
