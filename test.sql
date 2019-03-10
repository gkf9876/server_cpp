/*
Navicat MySQL Data Transfer

Source Server         : home
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2019-03-10 21:20:04
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
INSERT INTO `chatting` VALUES ('1', '2019-03-09 15:16:28', 'GKF1234', '안녕하세요 ~ !', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1');
INSERT INTO `chatting` VALUES ('2', '2019-03-09 15:16:28', 'GKF9876', '안녕하세요 ~ ! 123', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2');
INSERT INTO `chatting` VALUES ('3', '2019-03-09 15:16:28', 'GKF1234', '안녕하세요 ~ !', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1');
INSERT INTO `chatting` VALUES ('4', '2019-03-09 15:16:28', 'GKF9876', '안녕하세요 ~ ! 123', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2');

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
) ENGINE=InnoDB AUTO_INCREMENT=864 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of event_info
-- ----------------------------
INSERT INTO `event_info` VALUES ('861', '2019-03-09 15:16:28', 'abcd0', '/Story/NewsGisa1.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx1', '1', '2');
INSERT INTO `event_info` VALUES ('862', '2019-03-09 15:16:28', 'abcd1', '/Story/NewsGisa2.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx2', '3', '4');
INSERT INTO `event_info` VALUES ('863', '2019-03-09 15:16:28', 'abcd2', '/Story/NewsGisa3.json', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx3', '5', '6');

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
  `count` int(11) DEFAULT 0,
  PRIMARY KEY (`idx`,`itemName`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8;

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
  `name` varchar(100) DEFAULT NULL,
  `file_path` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`idx`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of loading_screen
-- ----------------------------
INSERT INTO `loading_screen` VALUES ('1', '12345', '105');
INSERT INTO `loading_screen` VALUES ('2', 'GKF5678', '5678');

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
  `z_order` int(11) DEFAULT 1,
  `file_dir` varchar(100) DEFAULT NULL,
  `count` int(11) DEFAULT 1,
  `hp` int(11) DEFAULT NULL,
  `seeDirection` int(11) NOT NULL DEFAULT 29,
  `action` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`idx`,`field`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of map_info
-- ----------------------------
INSERT INTO `map_info` VALUES ('1', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '1', '다람쥐', 'MONSTER', '4', '6', '1', 'Resources/monster/다람쥐.jpg', '1', '10', '0', '0');
INSERT INTO `map_info` VALUES ('2', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '2', '사슴', 'MONSTER', '4', '6', '1', 'Resources/monster/사슴.jpg', '1', '10', '0', '0');
INSERT INTO `map_info` VALUES ('3', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '3', '호랑이', 'MONSTER', '4', '6', '1', 'Resources/monster/호랑이.jpg', '1', '10', '0', '0');
INSERT INTO `map_info` VALUES ('4', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '14', '가로등', 'OBJECT', '51', '81', '3', 'Images/가로등.jpg', '3', '150', '0', '0');
INSERT INTO `map_info` VALUES ('5', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx', '14', '신호등', 'OBJECT', '11', '31', '2', 'Images/신호등.jpg', '2', '200', '0', '0');

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
  `seeDirection` int(11) NOT NULL DEFAULT 29,
  `action` int(11) DEFAULT NULL,
  `login` tinyint(1) DEFAULT 0,
  `lastLogin` datetime DEFAULT NULL,
  `lastLogout` datetime DEFAULT NULL,
  `joinDate` datetime DEFAULT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of user_list
-- ----------------------------
INSERT INTO `user_list` VALUES ('5', 'GKF1234', '12345', '105', '125', 'TileMaps/KonyangUniv.Daejeon/JukhunDigitalFacilitie/floor_08/floor.tmx15', '295', '0', '1', '2019-03-09 15:16:27', '2019-03-09 15:16:27', '2019-03-09 15:16:27');
INSERT INTO `user_list` VALUES ('2', 'GKF5678', '5678', '27', '4', 'abc', '29', '0', '0', '2019-03-09 15:16:27', '2019-03-09 15:16:27', '2019-03-09 15:16:27');
