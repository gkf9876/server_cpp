/*
Navicat MySQL Data Transfer

Source Server         : vmware ubuntu 18.10
Source Server Version : 50724
Source Host           : 192.168.132.128:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50724
File Encoding         : 65001

Date: 2019-01-23 07:01:02
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for `chatting`
-- ----------------------------
DROP TABLE IF EXISTS `chatting`;
CREATE TABLE `chatting` (
  `idx` int(10) NOT NULL AUTO_INCREMENT,
  `inputdate` datetime NOT NULL,
  `name` varchar(50) NOT NULL DEFAULT '',
  `content` varchar(100) DEFAULT '',
  `field` varchar(100) DEFAULT '',
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of chatting
-- ----------------------------
INSERT INTO `chatting` VALUES ('1', '2019-01-23 06:47:39', 'abcd4', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('2', '2019-01-23 06:47:39', 'abcd6', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('3', '2019-01-23 06:47:39', 'abcd3', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('4', '2019-01-23 06:47:39', 'abcd0', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('5', '2019-01-23 06:47:39', 'abcd1', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('6', '2019-01-23 06:47:39', 'abcd8', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('7', '2019-01-23 06:47:39', 'abcd2', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('8', '2019-01-23 06:47:39', 'abcd4', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('9', '2019-01-23 06:47:39', 'abcd7', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('10', '2019-01-23 06:47:39', 'abcd5', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('11', '2019-01-23 06:47:39', 'abcd6', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('12', '2019-01-23 06:47:39', 'abcd3', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('13', '2019-01-23 06:47:39', 'abcd0', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('14', '2019-01-23 06:47:39', 'abcd1', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('15', '2019-01-23 06:47:39', 'abcd2', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('16', '2019-01-23 06:47:39', 'abcd8', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('17', '2019-01-23 06:47:39', 'abcd4', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('18', '2019-01-23 06:47:39', 'abcd9', 'Hello World1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('19', '2019-01-23 06:47:39', 'abcd7', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('20', '2019-01-23 06:47:39', 'abcd6', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('21', '2019-01-23 06:47:39', 'abcd5', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('22', '2019-01-23 06:47:39', 'abcd0', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('23', '2019-01-23 06:47:39', 'abcd3', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('24', '2019-01-23 06:47:39', 'abcd1', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('25', '2019-01-23 06:47:39', 'abcd8', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('26', '2019-01-23 06:47:39', 'abcd9', 'Hello World2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('27', '2019-01-23 06:47:39', 'abcd7', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('28', '2019-01-23 06:47:39', 'abcd2', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('29', '2019-01-23 06:47:39', 'abcd5', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');
INSERT INTO `chatting` VALUES ('30', '2019-01-23 06:47:39', 'abcd9', 'Hello World3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx');

-- ----------------------------
-- Table structure for `event_info`
-- ----------------------------
DROP TABLE IF EXISTS `event_info`;
CREATE TABLE `event_info` (
  `idx` int(10) NOT NULL AUTO_INCREMENT,
  `inputdate` datetime NOT NULL,
  `name` varchar(50) NOT NULL DEFAULT '',
  `content` varchar(100) NOT NULL DEFAULT '',
  `field` varchar(100) DEFAULT '',
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`,`name`,`content`)
) ENGINE=InnoDB AUTO_INCREMENT=133 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of event_info
-- ----------------------------
INSERT INTO `event_info` VALUES ('130', '2019-01-23 06:47:39', 'abcd0', '/Story/NewsGisa1.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1', '1', '2');
INSERT INTO `event_info` VALUES ('131', '2019-01-23 06:47:39', 'abcd1', '/Story/NewsGisa2.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2', '3', '4');
INSERT INTO `event_info` VALUES ('132', '2019-01-23 06:47:39', 'abcd2', '/Story/NewsGisa3.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3', '5', '6');

-- ----------------------------
-- Table structure for `inventory_info`
-- ----------------------------
DROP TABLE IF EXISTS `inventory_info`;
CREATE TABLE `inventory_info` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `itemName` varchar(50) NOT NULL DEFAULT 'nameless',
  `userName` varchar(50) DEFAULT NULL,
  `type` varchar(20) DEFAULT '',
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  `file_dir` varchar(100) DEFAULT NULL,
  `count` int(11) DEFAULT '0',
  PRIMARY KEY (`idx`,`itemName`)
) ENGINE=InnoDB AUTO_INCREMENT=120 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of inventory_info
-- ----------------------------
INSERT INTO `inventory_info` VALUES ('12', '토마토_3', 'abcd1', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('13', '토마토_4', 'abcd1', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('14', '토마토_5', 'abcd1', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('15', '토마토_6', 'abcd1', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('16', '토마토_7', 'abcd1', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('20', '토마토_3', 'abcd2', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('21', '토마토_4', 'abcd2', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('22', '토마토_5', 'abcd2', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('23', '토마토_6', 'abcd2', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('24', '토마토_7', 'abcd2', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('28', '토마토_3', 'abcd3', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('29', '토마토_4', 'abcd3', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('30', '토마토_5', 'abcd3', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('31', '토마토_6', 'abcd3', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('32', '토마토_7', 'abcd3', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('36', '토마토_3', 'abcd4', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('37', '토마토_4', 'abcd4', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('38', '토마토_5', 'abcd4', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('39', '토마토_6', 'abcd4', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('40', '토마토_7', 'abcd4', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('44', '토마토_3', 'abcd5', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('45', '토마토_4', 'abcd5', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('46', '토마토_5', 'abcd5', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('47', '토마토_6', 'abcd5', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('48', '토마토_7', 'abcd5', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('52', '토마토_3', 'abcd6', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('53', '토마토_4', 'abcd6', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('54', '토마토_5', 'abcd6', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('55', '토마토_6', 'abcd6', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('56', '토마토_7', 'abcd6', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('57', '토마토_0', 'abcd7', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('59', '토마토_2', 'abcd7', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('62', '토마토_5', 'abcd7', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('63', '토마토_6', 'abcd7', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('64', '토마토_7', 'abcd7', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('65', '토마토_0', 'abcd8', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('68', '토마토_3', 'abcd8', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('70', '토마토_5', 'abcd8', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('71', '토마토_6', 'abcd8', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('72', '토마토_7', 'abcd8', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('74', '토마토_1', 'abcd9', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('75', '토마토_2', 'abcd9', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('76', '토마토_3', 'abcd9', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('79', '토마토_6', 'abcd9', 'ITEM', '1', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('80', '토마토_7', 'abcd9', 'ITEM', '1', '2', 'Resources/items/토마토_7.jpg', '8');
INSERT INTO `inventory_info` VALUES ('81', '토마토_3', 'abcd7', 'ITEM', '0', '3', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('82', '토마토_0', 'abcd4', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('83', '토마토_2', 'abcd8', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('85', '토마토_0', 'abcd6', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('86', '토마토_0', 'abcd1', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('87', '토마토_0', 'abcd2', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('88', '토마토_0', 'abcd3', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('89', '토마토_0', 'abcd9', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('90', '토마토_4', 'abcd7', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('91', '토마토_0', 'abcd5', 'ITEM', '0', '0', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('92', '토마토_1', 'abcd4', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('94', '토마토_1', 'abcd8', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('95', '토마토_1', 'abcd6', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('96', '토마토_1', 'abcd2', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('97', '토마토_1', 'abcd1', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('98', '토마토_1', 'abcd3', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('99', '토마토_4', 'abcd9', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('100', '토마토_1', 'abcd5', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('101', '토마토_4', 'abcd8', 'ITEM', '0', '4', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('102', '토마토_1', 'abcd7', 'ITEM', '0', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('104', '토마토_2', 'abcd2', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('105', '토마토_2', 'abcd1', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('106', '토마토_2', 'abcd6', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('107', '토마토_5', 'abcd9', 'ITEM', '1', '0', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('108', '토마토_2', 'abcd3', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('109', '토마토_2', 'abcd5', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('110', '토마토_2', 'abcd4', 'ITEM', '0', '2', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('112', '토마토_6', 'abcd0', 'ITEM', '0', '1', 'Resources/items/토마토_6.jpg', '7');
INSERT INTO `inventory_info` VALUES ('113', '토마토_5', 'abcd0', 'ITEM', '0', '2', 'Resources/items/토마토_5.jpg', '6');
INSERT INTO `inventory_info` VALUES ('114', '토마토_4', 'abcd0', 'ITEM', '0', '3', 'Resources/items/토마토_4.jpg', '5');
INSERT INTO `inventory_info` VALUES ('115', '토마토_3', 'abcd0', 'ITEM', '0', '4', 'Resources/items/토마토_3.jpg', '4');
INSERT INTO `inventory_info` VALUES ('116', '토마토_2', 'abcd0', 'ITEM', '1', '0', 'Resources/items/토마토_2.jpg', '3');
INSERT INTO `inventory_info` VALUES ('117', '토마토_1', 'abcd0', 'ITEM', '1', '1', 'Resources/items/토마토_1.jpg', '2');
INSERT INTO `inventory_info` VALUES ('118', '토마토_0', 'abcd0', 'ITEM', '1', '2', 'Resources/items/토마토_0.jpg', '1');
INSERT INTO `inventory_info` VALUES ('119', '토마토_7', 'abcd0', 'ITEM', '0', '0', 'Resources/items/토마토_7.jpg', '8');

-- ----------------------------
-- Table structure for `loading_screen`
-- ----------------------------
DROP TABLE IF EXISTS `loading_screen`;
CREATE TABLE `loading_screen` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `file_path` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of loading_screen
-- ----------------------------
INSERT INTO `loading_screen` VALUES ('3', 'GKF1234', '1234');
INSERT INTO `loading_screen` VALUES ('4', 'GKF5678', '5678');

-- ----------------------------
-- Table structure for `map_info`
-- ----------------------------
DROP TABLE IF EXISTS `map_info`;
CREATE TABLE `map_info` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `field` varchar(100) NOT NULL DEFAULT '',
  `object_code` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT 'nameless',
  `type` varchar(20) DEFAULT '',
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  `z_order` int(11) DEFAULT '1',
  `file_dir` varchar(100) DEFAULT NULL,
  `count` int(11) DEFAULT '1',
  `hp` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`,`field`)
) ENGINE=InnoDB AUTO_INCREMENT=149 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of map_info
-- ----------------------------
INSERT INTO `map_info` VALUES ('1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('4', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('5', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('6', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('7', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('8', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('9', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('10', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '1', '다람쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10');
INSERT INTO `map_info` VALUES ('11', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '2', '사슴', 'MONSTER', '10', '12', '1', 'Resources/monster/사슴.jpg', '1', '12');
INSERT INTO `map_info` VALUES ('12', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '2', '사슴', 'MONSTER', '10', '12', '1', 'Resources/monster/사슴.jpg', '1', '12');
INSERT INTO `map_info` VALUES ('13', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '2', '사슴', 'MONSTER', '10', '12', '1', 'Resources/monster/사슴.jpg', '1', '12');
INSERT INTO `map_info` VALUES ('14', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '2', '사슴', 'MONSTER', '10', '12', '1', 'Resources/monster/사슴.jpg', '1', '12');
INSERT INTO `map_info` VALUES ('15', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '2', '사슴', 'MONSTER', '10', '12', '1', 'Resources/monster/사슴.jpg', '1', '12');
INSERT INTO `map_info` VALUES ('16', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '3', '호랑이', 'MONSTER', '10', '12', '1', 'Resources/monster/호랑이.jpg', '1', '20');
INSERT INTO `map_info` VALUES ('17', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '3', '호랑이', 'MONSTER', '10', '12', '1', 'Resources/monster/호랑이.jpg', '1', '20');
INSERT INTO `map_info` VALUES ('18', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '3', '호랑이', 'MONSTER', '10', '12', '1', 'Resources/monster/호랑이.jpg', '1', '20');
INSERT INTO `map_info` VALUES ('19', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('20', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('21', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('22', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('23', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('24', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('25', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('26', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('27', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('28', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('29', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '4', '토끼', 'MONSTER', '10', '12', '1', 'Resources/monster/토끼.jpg', '1', '25');
INSERT INTO `map_info` VALUES ('30', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('31', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('32', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('33', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('34', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('35', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('36', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('37', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('38', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('39', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('40', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('41', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('42', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('43', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('44', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '5', '너구리', 'MONSTER', '10', '12', '1', 'Resources/monster/너구리.jpg', '1', '28');
INSERT INTO `map_info` VALUES ('45', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('46', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('47', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('48', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('49', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('50', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('51', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('52', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('53', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('54', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('55', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('56', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('57', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('58', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('59', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('60', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('61', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '6', '쥐', 'MONSTER', '10', '12', '1', 'Resources/monster/쥐.jpg', '1', '15');
INSERT INTO `map_info` VALUES ('62', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '7', '들개', 'MONSTER', '10', '12', '1', 'Resources/monster/들개.jpg', '1', '30');
INSERT INTO `map_info` VALUES ('63', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '7', '들개', 'MONSTER', '10', '12', '1', 'Resources/monster/들개.jpg', '1', '30');
INSERT INTO `map_info` VALUES ('64', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('65', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('66', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('67', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('68', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('69', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('70', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('71', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('72', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('73', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('74', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('75', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('76', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('77', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('78', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('79', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('80', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('81', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('82', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('83', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '8', '사냥꾼', 'MONSTER', '10', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50');
INSERT INTO `map_info` VALUES ('84', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('85', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('86', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('87', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('88', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('89', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '9', '고라니', 'MONSTER', '10', '12', '1', 'Resources/monster/고라니.jpg', '1', '27');
INSERT INTO `map_info` VALUES ('90', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '51', '81', '3', 'Images/가로등.jpg', '3', '150');
INSERT INTO `map_info` VALUES ('91', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '52', '82', '4', 'Images/가로등.jpg', '4', '150');
INSERT INTO `map_info` VALUES ('92', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '53', '83', '5', 'Images/가로등.jpg', '5', '150');
INSERT INTO `map_info` VALUES ('93', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '54', '84', '6', 'Images/가로등.jpg', '6', '150');
INSERT INTO `map_info` VALUES ('94', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '55', '85', '7', 'Images/가로등.jpg', '7', '150');
INSERT INTO `map_info` VALUES ('95', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '56', '86', '8', 'Images/가로등.jpg', '8', '150');
INSERT INTO `map_info` VALUES ('96', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '57', '87', '9', 'Images/가로등.jpg', '9', '150');
INSERT INTO `map_info` VALUES ('97', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '14', '가로등', 'OBJECT', '58', '88', '10', 'Images/가로등.jpg', '10', '150');
INSERT INTO `map_info` VALUES ('98', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '59', '89', '11', 'Images/신호등.jpg', '11', '150');
INSERT INTO `map_info` VALUES ('99', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '60', '90', '12', 'Images/신호등.jpg', '12', '150');
INSERT INTO `map_info` VALUES ('100', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '61', '91', '13', 'Images/신호등.jpg', '13', '150');
INSERT INTO `map_info` VALUES ('101', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '62', '92', '14', 'Images/신호등.jpg', '14', '150');
INSERT INTO `map_info` VALUES ('102', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '63', '93', '15', 'Images/신호등.jpg', '15', '150');
INSERT INTO `map_info` VALUES ('103', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '64', '94', '16', 'Images/신호등.jpg', '16', '150');
INSERT INTO `map_info` VALUES ('104', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '15', '신호등', 'OBJECT', '65', '95', '17', 'Images/신호등.jpg', '17', '150');
INSERT INTO `map_info` VALUES ('105', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '16', '자동차', 'OBJECT', '66', '96', '18', 'Images/자동차.jpg', '18', '150');
INSERT INTO `map_info` VALUES ('106', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '16', '자동차', 'OBJECT', '67', '97', '19', 'Images/자동차.jpg', '19', '150');
INSERT INTO `map_info` VALUES ('107', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '16', '자동차', 'OBJECT', '68', '98', '20', 'Images/자동차.jpg', '20', '150');
INSERT INTO `map_info` VALUES ('108', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '16', '자동차', 'OBJECT', '69', '99', '21', 'Images/자동차.jpg', '21', '150');
INSERT INTO `map_info` VALUES ('109', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '16', '자동차', 'OBJECT', '70', '100', '22', 'Images/자동차.jpg', '22', '150');

-- ----------------------------
-- Table structure for `map_list`
-- ----------------------------
DROP TABLE IF EXISTS `map_list`;
CREATE TABLE `map_list` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `field` varchar(100) NOT NULL,
  `monster1` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster2` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster3` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster1_count` int(11) DEFAULT NULL,
  `monster2_count` int(11) DEFAULT NULL,
  `monster3_count` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`,`field`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of map_list
-- ----------------------------
INSERT INTO `map_list` VALUES ('1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '다람쥐', '사슴', '호랑이', '10', '5', '3');
INSERT INTO `map_list` VALUES ('2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '토끼', '너구리', '쥐', '11', '15', '17');
INSERT INTO `map_list` VALUES ('3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '들개', '사냥꾼', '고라니', '2', '20', '6');

-- ----------------------------
-- Table structure for `monster_list`
-- ----------------------------
DROP TABLE IF EXISTS `monster_list`;
CREATE TABLE `monster_list` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT 'nameless',
  `type` varchar(20) DEFAULT '',
  `file_dir` varchar(100) DEFAULT NULL,
  `hp` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of monster_list
-- ----------------------------
INSERT INTO `monster_list` VALUES ('1', '다람쥐', 'MONSTER', 'Resources/monster/다람쥐.jpg', '10');
INSERT INTO `monster_list` VALUES ('2', '사슴', 'MONSTER', 'Resources/monster/사슴.jpg', '12');
INSERT INTO `monster_list` VALUES ('3', '호랑이', 'MONSTER', 'Resources/monster/호랑이.jpg', '20');
INSERT INTO `monster_list` VALUES ('4', '토끼', 'MONSTER', 'Resources/monster/토끼.jpg', '25');
INSERT INTO `monster_list` VALUES ('5', '너구리', 'MONSTER', 'Resources/monster/너구리.jpg', '28');
INSERT INTO `monster_list` VALUES ('6', '쥐', 'MONSTER', 'Resources/monster/쥐.jpg', '15');
INSERT INTO `monster_list` VALUES ('7', '들개', 'MONSTER', 'Resources/monster/들개.jpg', '30');
INSERT INTO `monster_list` VALUES ('8', '사냥꾼', 'MONSTER', 'Resources/monster/사냥꾼.jpg', '50');
INSERT INTO `monster_list` VALUES ('9', '고라니', 'MONSTER', 'Resources/monster/고라니.jpg', '27');

-- ----------------------------
-- Table structure for `server_info`
-- ----------------------------
DROP TABLE IF EXISTS `server_info`;
CREATE TABLE `server_info` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `INPUTDATE` datetime NOT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of server_info
-- ----------------------------
INSERT INTO `server_info` VALUES ('1', '2018-03-17 15:58:21');

-- ----------------------------
-- Table structure for `user_list`
-- ----------------------------
DROP TABLE IF EXISTS `user_list`;
CREATE TABLE `user_list` (
  `sock` int(11) DEFAULT NULL,
  `name` varchar(50) NOT NULL,
  `password` varchar(50) DEFAULT NULL,
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  `field` varchar(100) DEFAULT '',
  `seeDirection` int(11) NOT NULL DEFAULT '29',
  `action` int(11) DEFAULT NULL,
  `login` tinyint(1) DEFAULT '0',
  `lastLogin` datetime DEFAULT NULL,
  `lastLogout` datetime DEFAULT NULL,
  `joinDate` datetime DEFAULT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of user_list
-- ----------------------------
INSERT INTO `user_list` VALUES ('0', 'abcd0', '5678', '6', '6', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '26', '6', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:43', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd1', '5678', '9', '9', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '27', '9', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd2', '5678', '456', '456', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor0.tmx', '27', '456', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd3', '5678', '333', '333', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '27', '333', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd4', '5678', '666', '666', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '27', '666', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd5', '5678', '999', '999', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '27', '999', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd6', '5678', '33', '33', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor3.tmx', '27', '33', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd7', '5678', '66', '66', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '27', '66', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd8', '5678', '99', '99', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '27', '99', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
INSERT INTO `user_list` VALUES ('0', 'abcd9', '5678', '3', '3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor7.tmx', '27', '3', '0', '2019-01-23 06:47:39', '2019-01-23 06:47:42', '2019-01-23 06:47:39');
