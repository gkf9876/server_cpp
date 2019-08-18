/*
Navicat MySQL Data Transfer

Source Server         : vmware_ubuntu19.04
Source Server Version : 50727
Source Host           : 192.168.198.128:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50727
File Encoding         : 65001

Date: 2019-08-18 19:00:26
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
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of chatting
-- ----------------------------
INSERT INTO `chatting` VALUES ('1', '2019-08-18 10:00:01', 'GKF1234', '안녕하세요 ~ !', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1');
INSERT INTO `chatting` VALUES ('2', '2019-08-18 10:00:01', 'GKF9876', '안녕하세요 ~ ! 123', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2');
INSERT INTO `chatting` VALUES ('3', '2019-08-18 10:00:01', 'GKF1234', '안녕하세요 ~ !', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1');
INSERT INTO `chatting` VALUES ('4', '2019-08-18 10:00:01', 'GKF9876', '안녕하세요 ~ ! 123', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2');

-- ----------------------------
-- Table structure for `event_info`
-- ----------------------------
DROP TABLE IF EXISTS `event_info`;
CREATE TABLE `event_info` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `inputdate` datetime DEFAULT NULL,
  `name` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `content` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  `field` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=97 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of event_info
-- ----------------------------
INSERT INTO `event_info` VALUES ('94', '2019-08-18 10:00:01', 'abcd0', '/Story/NewsGisa1.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1', '1', '2');
INSERT INTO `event_info` VALUES ('95', '2019-08-18 10:00:01', 'abcd1', '/Story/NewsGisa2.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2', '3', '4');
INSERT INTO `event_info` VALUES ('96', '2019-08-18 10:00:01', 'abcd2', '/Story/NewsGisa3.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3', '5', '6');

-- ----------------------------
-- Table structure for `inventory_info`
-- ----------------------------
DROP TABLE IF EXISTS `inventory_info`;
CREATE TABLE `inventory_info` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `itemName` varchar(50) CHARACTER SET utf8 NOT NULL DEFAULT 'nameless',
  `userName` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `type` varchar(20) CHARACTER SET utf8 DEFAULT '',
  `xpos` int(11) DEFAULT NULL,
  `ypos` int(11) DEFAULT NULL,
  `file_dir` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  `count` int(11) DEFAULT '0',
  PRIMARY KEY (`idx`,`itemName`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of inventory_info
-- ----------------------------
INSERT INTO `inventory_info` VALUES ('1', '토마토_0', 'gkf1234', 'ITEM', '1', '10', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_0', '1');
INSERT INTO `inventory_info` VALUES ('2', '토마토_1', 'gkf1234', 'ITEM', '2', '11', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_1', '2');
INSERT INTO `inventory_info` VALUES ('3', '토마토_2', 'gkf1234', 'ITEM', '3', '12', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_2', '3');
INSERT INTO `inventory_info` VALUES ('4', '토마토_3', 'gkf1234', 'ITEM', '4', '13', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_3', '4');
INSERT INTO `inventory_info` VALUES ('5', '토마토_4', 'gkf1234', 'ITEM', '5', '14', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_4', '5');
INSERT INTO `inventory_info` VALUES ('6', '토마토_5', 'gkf1234', 'ITEM', '6', '15', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_5', '6');
INSERT INTO `inventory_info` VALUES ('7', '토마토_6', 'gkf1234', 'ITEM', '7', '16', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_6', '7');
INSERT INTO `inventory_info` VALUES ('8', '토마토_7', 'gkf1234', 'ITEM', '100', '200', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_7', '8');
INSERT INTO `inventory_info` VALUES ('9', '토마토_8', 'gkf1234', 'ITEM', '200', '400', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_8', '9');
INSERT INTO `inventory_info` VALUES ('10', '토마토_9', 'gkf1234', 'ITEM', '400', '800', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_9', '10');
INSERT INTO `inventory_info` VALUES ('11', '토마토_10', 'gkf1234_10', 'ITEM', '11', '20', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_10', '11');
INSERT INTO `inventory_info` VALUES ('12', '토마토_11', 'gkf1234_11', 'ITEM', '12', '21', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_11', '12');
INSERT INTO `inventory_info` VALUES ('13', '토마토_12', 'gkf1234_12', 'ITEM', '13', '22', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_12', '13');
INSERT INTO `inventory_info` VALUES ('14', '토마토_13', 'gkf1234_13', 'ITEM', '14', '23', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_13', '14');
INSERT INTO `inventory_info` VALUES ('15', '토마토_14', 'gkf1234_14', 'ITEM', '15', '24', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_14', '15');
INSERT INTO `inventory_info` VALUES ('16', '토마토_15', 'gkf1234_15', 'ITEM', '16', '25', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_15', '16');
INSERT INTO `inventory_info` VALUES ('17', '토마토_16', 'gkf1234_16', 'ITEM', '17', '26', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_16', '17');
INSERT INTO `inventory_info` VALUES ('18', '토마토_17', 'gkf1234_17', 'ITEM', '18', '27', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_17', '18');
INSERT INTO `inventory_info` VALUES ('19', '토마토_18', 'gkf1234_18', 'ITEM', '19', '28', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_18', '19');
INSERT INTO `inventory_info` VALUES ('20', '토마토_19', 'gkf1234_19', 'ITEM', '20', '29', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx_19', '20');

-- ----------------------------
-- Table structure for `loading_screen`
-- ----------------------------
DROP TABLE IF EXISTS `loading_screen`;
CREATE TABLE `loading_screen` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  `file_path` varchar(100) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

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
  `seeDirection` int(11) DEFAULT NULL,
  `action` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`,`field`)
) ENGINE=InnoDB AUTO_INCREMENT=90 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of map_info
-- ----------------------------
INSERT INTO `map_info` VALUES ('1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '17', '13', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '19', '5', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '26', '7', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '28', '0');
INSERT INTO `map_info` VALUES ('4', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '27', '13', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('5', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '30', '12', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '29', '0');
INSERT INTO `map_info` VALUES ('6', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '20', '1', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '26', '0');
INSERT INTO `map_info` VALUES ('7', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '3', '13', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('8', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '7', '13', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('9', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '13', '10', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('10', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '20', '10', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '27', '0');
INSERT INTO `map_info` VALUES ('11', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '27', '13', '1', 'Resources/monster/사슴.jpg', '1', '12', '27', '0');
INSERT INTO `map_info` VALUES ('12', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '3', '12', '1', 'Resources/monster/사슴.jpg', '1', '12', '28', '0');
INSERT INTO `map_info` VALUES ('13', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '31', '11', '1', 'Resources/monster/사슴.jpg', '1', '12', '26', '0');
INSERT INTO `map_info` VALUES ('14', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '16', '3', '1', 'Resources/monster/사슴.jpg', '1', '12', '29', '0');
INSERT INTO `map_info` VALUES ('15', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '17', '2', '1', 'Resources/monster/사슴.jpg', '1', '12', '27', '0');
INSERT INTO `map_info` VALUES ('16', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '3', '호랑이', 'MONSTER', '12', '10', '1', 'Resources/monster/호랑이.jpg', '1', '20', '27', '0');
INSERT INTO `map_info` VALUES ('17', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '3', '호랑이', 'MONSTER', '20', '5', '1', 'Resources/monster/호랑이.jpg', '1', '20', '27', '0');
INSERT INTO `map_info` VALUES ('18', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '3', '호랑이', 'MONSTER', '9', '10', '1', 'Resources/monster/호랑이.jpg', '1', '20', '26', '0');
INSERT INTO `map_info` VALUES ('19', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '24', '2', '1', 'Resources/monster/토끼.jpg', '1', '25', '28', '0');
INSERT INTO `map_info` VALUES ('20', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '25', '11', '1', 'Resources/monster/토끼.jpg', '1', '25', '28', '0');
INSERT INTO `map_info` VALUES ('21', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '19', '13', '1', 'Resources/monster/토끼.jpg', '1', '25', '29', '0');
INSERT INTO `map_info` VALUES ('22', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '40', '10', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('23', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '11', '10', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('24', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '30', '13', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('25', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '26', '11', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('26', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '6', '13', '1', 'Resources/monster/토끼.jpg', '1', '25', '29', '0');
INSERT INTO `map_info` VALUES ('27', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '39', '13', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('28', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '25', '11', '1', 'Resources/monster/토끼.jpg', '1', '25', '27', '0');
INSERT INTO `map_info` VALUES ('29', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '4', '토끼', 'MONSTER', '28', '7', '1', 'Resources/monster/토끼.jpg', '1', '25', '28', '0');
INSERT INTO `map_info` VALUES ('30', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '4', '12', '1', 'Resources/monster/너구리.jpg', '1', '28', '29', '0');
INSERT INTO `map_info` VALUES ('31', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '20', '11', '1', 'Resources/monster/너구리.jpg', '1', '28', '27', '0');
INSERT INTO `map_info` VALUES ('32', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '29', '10', '1', 'Resources/monster/너구리.jpg', '1', '28', '26', '0');
INSERT INTO `map_info` VALUES ('33', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '36', '12', '1', 'Resources/monster/너구리.jpg', '1', '28', '27', '0');
INSERT INTO `map_info` VALUES ('34', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '40', '11', '1', 'Resources/monster/너구리.jpg', '1', '28', '27', '0');
INSERT INTO `map_info` VALUES ('35', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '2', '10', '1', 'Resources/monster/너구리.jpg', '1', '28', '26', '0');
INSERT INTO `map_info` VALUES ('36', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '7', '11', '1', 'Resources/monster/너구리.jpg', '1', '28', '26', '0');
INSERT INTO `map_info` VALUES ('37', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '17', '12', '1', 'Resources/monster/너구리.jpg', '1', '28', '27', '0');
INSERT INTO `map_info` VALUES ('38', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '9', '11', '1', 'Resources/monster/너구리.jpg', '1', '28', '29', '0');
INSERT INTO `map_info` VALUES ('39', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '29', '10', '1', 'Resources/monster/너구리.jpg', '1', '28', '26', '0');
INSERT INTO `map_info` VALUES ('40', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '26', '6', '1', 'Resources/monster/너구리.jpg', '1', '28', '26', '0');
INSERT INTO `map_info` VALUES ('41', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '29', '6', '1', 'Resources/monster/너구리.jpg', '1', '28', '29', '0');
INSERT INTO `map_info` VALUES ('42', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '37', '13', '1', 'Resources/monster/너구리.jpg', '1', '28', '27', '0');
INSERT INTO `map_info` VALUES ('43', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '37', '11', '1', 'Resources/monster/너구리.jpg', '1', '28', '29', '0');
INSERT INTO `map_info` VALUES ('44', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '5', '너구리', 'MONSTER', '16', '2', '1', 'Resources/monster/너구리.jpg', '1', '28', '28', '0');
INSERT INTO `map_info` VALUES ('45', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '18', '7', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('46', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '4', '12', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('47', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '40', '13', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('48', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '18', '2', '1', 'Resources/monster/쥐.jpg', '1', '15', '28', '0');
INSERT INTO `map_info` VALUES ('49', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '20', '8', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('50', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '26', '1', '1', 'Resources/monster/쥐.jpg', '1', '15', '26', '0');
INSERT INTO `map_info` VALUES ('51', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '39', '12', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('52', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '36', '13', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('53', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '20', '4', '1', 'Resources/monster/쥐.jpg', '1', '15', '26', '0');
INSERT INTO `map_info` VALUES ('54', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '21', '12', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('55', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '12', '13', '1', 'Resources/monster/쥐.jpg', '1', '15', '29', '0');
INSERT INTO `map_info` VALUES ('56', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '27', '11', '1', 'Resources/monster/쥐.jpg', '1', '15', '26', '0');
INSERT INTO `map_info` VALUES ('57', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '17', '7', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('58', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '12', '11', '1', 'Resources/monster/쥐.jpg', '1', '15', '28', '0');
INSERT INTO `map_info` VALUES ('59', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '27', '4', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('60', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '19', '5', '1', 'Resources/monster/쥐.jpg', '1', '15', '27', '0');
INSERT INTO `map_info` VALUES ('61', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '6', '쥐', 'MONSTER', '22', '4', '1', 'Resources/monster/쥐.jpg', '1', '15', '29', '0');
INSERT INTO `map_info` VALUES ('62', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '7', '들개', 'MONSTER', '1', '11', '1', 'Resources/monster/들개.jpg', '1', '30', '28', '0');
INSERT INTO `map_info` VALUES ('63', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '7', '들개', 'MONSTER', '17', '1', '1', 'Resources/monster/들개.jpg', '1', '30', '26', '0');
INSERT INTO `map_info` VALUES ('64', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '21', '13', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '26', '0');
INSERT INTO `map_info` VALUES ('65', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '31', '11', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '29', '0');
INSERT INTO `map_info` VALUES ('66', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '24', '2', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('67', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '27', '6', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('68', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '8', '13', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '29', '0');
INSERT INTO `map_info` VALUES ('69', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '18', '8', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '28', '0');
INSERT INTO `map_info` VALUES ('70', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '2', '13', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('71', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '28', '5', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '26', '0');
INSERT INTO `map_info` VALUES ('72', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '27', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '28', '0');
INSERT INTO `map_info` VALUES ('73', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '29', '5', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('74', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '4', '10', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '28', '0');
INSERT INTO `map_info` VALUES ('75', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '38', '10', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('76', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '18', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('77', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '38', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '29', '0');
INSERT INTO `map_info` VALUES ('78', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '9', '12', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('79', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '27', '13', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('80', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '18', '5', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('81', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '18', '2', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('82', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '21', '6', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '27', '0');
INSERT INTO `map_info` VALUES ('83', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '8', '사냥꾼', 'MONSTER', '21', '3', '1', 'Resources/monster/사냥꾼.jpg', '1', '50', '26', '0');
INSERT INTO `map_info` VALUES ('84', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '19', '12', '1', 'Resources/monster/고라니.jpg', '1', '27', '27', '0');
INSERT INTO `map_info` VALUES ('85', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '20', '3', '1', 'Resources/monster/고라니.jpg', '1', '27', '28', '0');
INSERT INTO `map_info` VALUES ('86', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '32', '10', '1', 'Resources/monster/고라니.jpg', '1', '27', '28', '0');
INSERT INTO `map_info` VALUES ('87', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '19', '6', '1', 'Resources/monster/고라니.jpg', '1', '27', '26', '0');
INSERT INTO `map_info` VALUES ('88', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '17', '7', '1', 'Resources/monster/고라니.jpg', '1', '27', '26', '0');
INSERT INTO `map_info` VALUES ('89', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '9', '고라니', 'MONSTER', '22', '3', '1', 'Resources/monster/고라니.jpg', '1', '27', '29', '0');

-- ----------------------------
-- Table structure for `map_list`
-- ----------------------------
DROP TABLE IF EXISTS `map_list`;
CREATE TABLE `map_list` (
  `idx` int(11) NOT NULL AUTO_INCREMENT,
  `field` varchar(100) CHARACTER SET utf8 NOT NULL,
  `monster1` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster2` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster3` varchar(50) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `monster1_count` int(11) DEFAULT NULL,
  `monster2_count` int(11) DEFAULT NULL,
  `monster3_count` int(11) DEFAULT NULL,
  PRIMARY KEY (`idx`,`field`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- ----------------------------
-- Records of map_list
-- ----------------------------
INSERT INTO `map_list` VALUES ('1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '다람쥐', '사슴', '호랑이', '10', '5', '3');
INSERT INTO `map_list` VALUES ('2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_07/floor.tmx', '토끼', '너구리', '쥐', '11', '15', '17');
INSERT INTO `map_list` VALUES ('3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_06/floor.tmx', '들개', '사냥꾼', '고라니', '2', '20', '6');

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
INSERT INTO `user_list` VALUES ('5', 'GKF1234', '12345', '105', '125', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx15', '295', '0', '1', '2019-08-18 10:00:01', '2019-08-18 10:00:01', '2019-08-18 10:00:01');
INSERT INTO `user_list` VALUES ('2', 'GKF5678', '5678', '27', '4', 'abc', '29', '0', '0', '2019-08-18 10:00:01', '2019-08-18 10:00:01', '2019-08-18 10:00:01');
