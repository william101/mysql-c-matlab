CREATE DATABASE IF NOT EXIST `process_control` /*!40100 DEFAULT CHARACTER SET latin1 */

CREATE TABLE IF NOT EXIST `mixer_temp` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `date` datetime DEFAULT NULL,
  `mixer_temp` varchar(225) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=102 DEFAULT CHARSET=latin1