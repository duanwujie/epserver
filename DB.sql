# SQL-Front 5.1  (Build 4.16)

/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE */;
/*!40101 SET SQL_MODE='' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES */;
/*!40103 SET SQL_NOTES='ON' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;


# Host: 192.168.0.254    Database: epdb 
# ------------------------------------------------------
# Server version 5.5.29-0ubuntu0.12.04.1

DROP DATABASE IF EXISTS `epdb`;
CREATE DATABASE `epdb` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `epdb`;

# ======================================================
#
# Source for table func(功能表)
#
DROP TABLE IF EXISTS `func`;
CREATE TABLE `func` (
    `func_id` int (11) NOT NULL,
    `func_name` char (40) NOT NULL,
    `res_path` char (128) NOT NULL,
    PRIMARY KEY (`func_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table func 
#
LOCK TABLES `func` WRITE;
/*!40000 ALTER TABLE `func` DISABLE KEYS */;
INSERT INTO `func` VALUES (1,'个人','/var/resources/abc.png');
INSERT INTO `func` VALUES (2,'学校','/var/resources/deg.png');
INSERT INTO `func` VALUES (3,'家庭','1.png');
INSERT INTO `func` VALUES (4,'好友','2.png');
INSERT INTO `func` VALUES (5,'办公室','2.png');
/*!40000 ALTER TABLE `func` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table client_type(客户端类型表)
#
DROP TABLE IF EXISTS `client_type`;
CREATE TABLE `client_type` (
    `client_type_id` int (11) NOT NULL,
    `client_type_name` char (40) NOT NULL,
    PRIMARY KEY (`client_type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table client_type 
#
LOCK TABLES `client_type` WRITE;
/*!40000 ALTER TABLE `client_type` DISABLE KEYS */;
INSERT INTO `client_type` VALUES (1,'院长');
INSERT INTO `client_type` VALUES (2,'教师');
INSERT INTO `client_type` VALUES (3,'家长');
INSERT INTO `client_type` VALUES (4,'学生');
INSERT INTO `client_type` VALUES (5,'白板');
/*!40000 ALTER TABLE `client_type` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table client_type_func(客户端功能关系表)
#
DROP TABLE IF EXISTS `client_type_func`;
CREATE TABLE `client_type_func` (
    `client_type_id` int (11) NOT NULL,
    `func_id` int (11) NOT NULL,
    PRIMARY KEY (`func_id`, `client_type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table client_type_func 
#
LOCK TABLES `client_type_func` WRITE;
/*!40000 ALTER TABLE `client_type_func` DISABLE KEYS */;
INSERT INTO `client_type_func` VALUES (2,2);
INSERT INTO `client_type_func` VALUES (2,5);
INSERT INTO `client_type_func` VALUES (4,1);
INSERT INTO `client_type_func` VALUES (4,2);
/*!40000 ALTER TABLE `client_type_func` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course_group (课件组表)
#
DROP TABLE IF EXISTS `course_group`;
CREATE TABLE `course_group` (
    `group_id` int (11) NOT NULL,
    `group_name` char (40) NOT NULL,
    PRIMARY KEY (`group_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course_group
#
LOCK TABLES `course_group` WRITE;
/*!40000 ALTER TABLE `course_group` DISABLE KEYS */;
INSERT INTO `course_group` VALUES (1,'绘本');
INSERT INTO `course_group` VALUES (2,'绘画');
INSERT INTO `course_group` VALUES (3,'连线');
/*!40000 ALTER TABLE `course_group` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table course (课程表)
#
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
        `course_id` int (11) NOT NULL,
        `course_name` char (40) NOT NULL,
        `group_id` int (11) NOT NULL,
        `language` int (11) NOT NULL,
        `art` int (11) NOT NULL,
        `community` int (11) NOT NULL,
        `health` int (11) NOT NULL,
        `science` int (11) NOT NULL,
        `resPath` char (128) NOT NULL,
        PRIMARY KEY (`course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table course
#
LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES (1,'绘小猴子',2, 13, 56, 76, 25, 92, '/res/a.tar.gz');
INSERT INTO `course` VALUES (2,'绘小鸭子',2, 83, 64, 15, 18, 32, '/res/b.tar.gz');
INSERT INTO `course` VALUES (3,'三只小猪',1, 41, 26, 11, 65, 82, '/res/c.tar.gz');
INSERT INTO `course` VALUES (4,'白雪公主',1, 35, 56, 25, 95, 11, '/res/d.tar.gz');
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table grade_course (年级课程表)
#
DROP TABLE IF EXISTS `grade_course`;
CREATE TABLE `grade_course` (
        `grade_course_id` int (11) NOT NULL AUTO_INCREMENT,
        `grade_id` int (11) NOT NULL,
        `course_id` int (11) NOT NULL,
        PRIMARY KEY (`grade_course_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table grade_course
#
LOCK TABLES `grade_course` WRITE;
/*!40000 ALTER TABLE `grade_course` DISABLE KEYS */;
INSERT INTO `grade_course` VALUES (1,1,1);
INSERT INTO `grade_course` VALUES (2,1,2);
INSERT INTO `grade_course` VALUES (3,1,3);
INSERT INTO `grade_course` VALUES (4,1,4);

INSERT INTO `grade_course` VALUES (5,2,1);
INSERT INTO `grade_course` VALUES (6,2,3);

INSERT INTO `grade_course` VALUES (7,3,2);
INSERT INTO `grade_course` VALUES (8,3,3);
INSERT INTO `grade_course` VALUES (9,3,4);
/*!40000 ALTER TABLE `grade_course` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table resource_type (资源类型表)
#
DROP TABLE IF EXISTS `resource_type`;
CREATE TABLE `resource_type` (
        `type_id` int (11) NOT NULL,
        `name` int (11) NOT NULL,
        PRIMARY KEY (`type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table resource (资源表)
#
DROP TABLE IF EXISTS `resource`;
CREATE TABLE `resource` (
        `resource_id`   int(11)         NOT NULL,
        `type_id`       int(11)         NOT NULL,
        `name`          int(11)         NOT NULL,
        `img_path`      char(128)       NOT NULL,
        PRIMARY KEY (`resource_id`, `type_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

# ======================================================
#
# Source for table country (国家表)
#

DROP TABLE IF EXISTS `country`;
CREATE TABLE `country` (
        `country_id`    int(11)         NOT NULL,
        `country_name`  char(100)       NOT NULL,
        PRIMARY KEY (`country_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table country
#

LOCK TABLES `country` WRITE;
/*!40000 ALTER TABLE `country` DISABLE KEYS */;
INSERT INTO `country` VALUES (1,'中国');
INSERT INTO `country` VALUES (2,'美国');
/*!40000 ALTER TABLE `country` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table native_place (所在地配置表)
#

DROP TABLE IF EXISTS `native_place`;
CREATE TABLE `native_place` (
        `native_id`     int(11)         NOT NULL,
        `province`      char(20)        NOT NULL,
        PRIMARY KEY (`native_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table native_place
#

LOCK TABLES `native_place` WRITE;
/*!40000 ALTER TABLE `native_place` DISABLE KEYS */;
INSERT INTO `native_place` VALUES (1,'四川');
INSERT INTO `native_place` VALUES (2,'上海');
/*!40000 ALTER TABLE `native_place` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table school (学校表)
#
DROP TABLE IF EXISTS `school`;
CREATE TABLE `school` (
        `school_id`     int(11)         NOT NULL,
        `school_name`   char(100)       NOT NULL,
        `native_id`     int(11)         NOT NULL,
        PRIMARY KEY (`school_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table school
#
LOCK TABLES `school` WRITE;
/*!40000 ALTER TABLE `school` DISABLE KEYS */;
INSERT INTO `school` VALUES (1,'双楠幼儿园',1);
INSERT INTO `school` VALUES (2,'三楠幼儿园',1);
INSERT INTO `school` VALUES (3,'上海幼儿园',2);
/*!40000 ALTER TABLE `school` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table grade (年级表)
#
DROP TABLE IF EXISTS `grade`;
CREATE TABLE `grade` (
        `grade_id`      int(11)         NOT NULL,
        `grade_name`    char(100)       NOT NULL,
        `school_id`     int(11)         NOT NULL,
        PRIMARY KEY (`grade_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table grade
#
LOCK TABLES `grade` WRITE;
/*!40000 ALTER TABLE `grade` DISABLE KEYS */;
INSERT INTO `grade` VALUES (1,'小班',1);
INSERT INTO `grade` VALUES (2,'中班',1);
INSERT INTO `grade` VALUES (3,'大班',1);
/*!40000 ALTER TABLE `grade` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table class (班级表)
#
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class` (
        `class_id`              int(11)         NOT NULL,
        `class_name`            char(40)        NOT NULL,
        `grade_id`              int(11)         NOT NULL,
        `class_teacher_id`      int(11)         NOT NULL,
        PRIMARY KEY (`class_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table class
#
LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES (1,'小班向阳班',1,1);
INSERT INTO `class` VALUES (2,'小班草莓班',1,1);
INSERT INTO `class` VALUES (3,'小班苹果班',1,1);
INSERT INTO `class` VALUES (4,'小班豆豆班',1,1);
INSERT INTO `class` VALUES (5,'小班果冻班',1,1);

INSERT INTO `class` VALUES (6,'中班向阳班',2,2);
INSERT INTO `class` VALUES (7,'中班草莓班',2,2);
INSERT INTO `class` VALUES (8,'中班苹果班',2,2);
INSERT INTO `class` VALUES (9,'中班豆豆班',2,2);
INSERT INTO `class` VALUES (10,'中班果冻班',2,2);

INSERT INTO `class` VALUES (11,'大班向阳班',3,3);
INSERT INTO `class` VALUES (12,'大班草莓班',3,3);
INSERT INTO `class` VALUES (13,'大班苹果班',3,3);
INSERT INTO `class` VALUES (14,'大班豆豆班',3,3);
INSERT INTO `class` VALUES (15,'大班果冻班',3,3);

/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table teacher (教师表)
#
DROP TABLE IF EXISTS `teacher`;
CREATE TABLE `teacher` (
        `teacher_id`            int(11)         NOT NULL,
        `last_name`             char(100)       NOT NULL,
        `first_name`            char(100)       NOT NULL,
        `sex`                   char(2)         DEFAULT '女',
        `age`                   int(11)         NOT NULL DEFAULT '0',
        `race_id`               int(11)         NOT NULL,
        `birthday`              date            NOT NULL,
        `account`               char(100)       NOT NULL,
        `password`              char(100)       NOT NULL,
        `picture_id`            int(11)         NOT NULL,
        `country_id`            int(11)         NOT NULL DEFAULT '0',
        `native_place_id`       int(11)         NOT NULL,
        `school_id`             int(11)         NOT NULL,
        `client_type_id`        int(11)         DEFAULT 2,
        PRIMARY KEY (`teacher_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table teacher
#

LOCK TABLES `teacher` WRITE;
/*!40000 ALTER TABLE `teacher` DISABLE KEYS */;
INSERT INTO `teacher` VALUES (1,'张','三','女',1,1,'1989-12-30','张三','123456',2001,1,1,1,2);
INSERT INTO `teacher` VALUES (2,'李','四','男',1,1,'1989-12-30','李四','123456',2001,1,1,1,2);
INSERT INTO `teacher` VALUES (3,'王','五','男',1,1,'1989-12-30','王五','123456',2001,1,1,1,2);
/*!40000 ALTER TABLE `teacher` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table student (学生表)
#
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student` (
        `student_id`            int(11)         NOT NULL,
        `number`                char(20)        NOT NULL,
        `last_name`             char(10)        NOT NULL,
        `first_name`            char(10)        NOT NULL,
        `sex`                   char(2)         DEFAULT '男',
        `age`                   int(11)         NOT NULL DEFAULT '0',
        `race_id`               int(11)         NOT NULL,
        `birthday`              date            NOT NULL,
        `account`               char(100)       NOT NULL,
        `password`              char(34)        NOT NULL,
        `country_id`            int(11)         DEFAULT '1',
        `native_place_id`       int(11)         NOT NULL,
        `class_id`              int(11)         NOT NULL,
        `picture_id`            int(11)         NOT NULL,
        `client_type_id`        int(11)         DEFAULT 4,
        PRIMARY KEY (`student_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table student
#

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'10000001','yang','c1','男',1,1,'2000-01-01','学生1','123456',1,1,1,1001,4);
INSERT INTO `student` VALUES (2,'10000002','yang','c2','男',1,1,'2000-01-01','学生2','123456',1,1,1,1002,4);
INSERT INTO `student` VALUES (3,'10000003','yang','c3','女',1,1,'2000-01-01','学生3','123456',1,1,1,1003,4);
INSERT INTO `student` VALUES (4,'10000004','yang','c4','女',1,1,'2000-01-01','学生4','123456',1,1,1,1004,4);
INSERT INTO `student` VALUES (5,'10000005','yang','c5','女',1,1,'2000-01-01','学生5','123456',1,1,1,1005,4);
INSERT INTO `student` VALUES (6,'10000006','yang','c6','男',1,1,'2000-01-01','学生6','123456',1,1,1,1006,4);
INSERT INTO `student` VALUES (7,'10000007','yang','c7','女',1,1,'2000-01-01','学生7','123456',1,1,1,1007,4);
INSERT INTO `student` VALUES (8,'10000008','yang','c8','女',1,1,'2000-01-01','学生8','123456',1,1,1,1008,4);
INSERT INTO `student` VALUES (9,'10000009','yang','c9','男',1,1,'2000-01-01','学生9','123456',1,1,1,1009,4);
INSERT INTO `student` VALUES (10,'10000010','yang','c10','女',1,1,'2000-01-01','学生10','123456',1,1,1,1010,4);
INSERT INTO `student` VALUES (11,'10000011','yang','c11','女',1,1,'2000-01-01','学生11','123456',1,1,1,1011,4);
INSERT INTO `student` VALUES (12,'10000012','yang','c12','女',1,1,'2000-01-01','学生12','123456',1,1,1,1012,4);
INSERT INTO `student` VALUES (13,'10000013','yang','c13','女',1,1,'2000-01-01','学生13','123456',1,1,1,1013,4);
INSERT INTO `student` VALUES (14,'10000014','yang','c14','女',1,1,'2000-01-01','学生14','123456',1,1,1,1014,4);
INSERT INTO `student` VALUES (15,'10000015','yang','c15','女',1,1,'2000-01-01','学生15','123456',1,1,1,1015,4);
INSERT INTO `student` VALUES (16,'10000016','yang','c16','男',1,1,'2000-01-01','学生16','123456',1,1,1,1016,4);
INSERT INTO `student` VALUES (17,'10000017','yang','c17','女',1,1,'2000-01-01','学生17','123456',1,1,1,1017,4);
INSERT INTO `student` VALUES (18,'10000018','yang','c18','女',1,1,'2000-01-01','学生18','123456',1,1,1,1018,4);
INSERT INTO `student` VALUES (19,'10000019','yang','c19','女',1,1,'2000-01-01','学生19','123456',1,1,1,1019,4);
INSERT INTO `student` VALUES (20,'10000020','yang','c20','女',1,1,'2000-01-01','学生20','123456',1,1,1,1020,4);
INSERT INTO `student` VALUES (21,'10000021','yang','c21','男',1,1,'2000-01-01','学生21','123456',1,1,1,1021,4);
INSERT INTO `student` VALUES (22,'10000022','yang','c22','女',1,1,'2000-01-01','学生22','123456',1,1,1,1022,4);
INSERT INTO `student` VALUES (23,'10000023','yang','c23','女',1,1,'2000-01-01','学生23','123456',1,1,1,1023,4);
INSERT INTO `student` VALUES (24,'10000024','yang','c24','男',1,1,'2000-01-01','学生24','123456',1,1,1,1024,4);
INSERT INTO `student` VALUES (25,'10000025','yang','c25','女',1,1,'2000-01-01','学生25','123456',1,1,1,1025,4);
INSERT INTO `student` VALUES (26,'10000026','yang','c26','男',1,1,'2000-01-01','学生26','123456',1,1,1,1026,4);
INSERT INTO `student` VALUES (27,'10000027','yang','c27','女',1,1,'2000-01-01','学生27','123456',1,1,1,1027,4);
INSERT INTO `student` VALUES (28,'10000028','yang','c28','男',1,1,'2000-01-01','学生28','123456',1,1,1,1028,4);
INSERT INTO `student` VALUES (29,'10000029','yang','c29','女',1,1,'2000-01-01','学生29','123456',1,1,1,1029,4);
INSERT INTO `student` VALUES (30,'10000030','yang','c30','男',1,1,'2000-01-01','学生30','123456',1,1,1,1030,4);
INSERT INTO `student` VALUES (31,'10000031','yang','c31','女',1,1,'2000-01-01','学生31','123456',1,1,1,1031,4);
INSERT INTO `student` VALUES (32,'10000032','yang','c32','女',1,1,'2000-01-01','学生32','123456',1,1,1,1032,4);
INSERT INTO `student` VALUES (33,'10000033','yang','c33','女',1,1,'2000-01-01','学生33','123456',1,1,1,1033,4);
INSERT INTO `student` VALUES (34,'10000034','yang','c34','女',1,1,'2000-01-01','学生34','123456',1,1,1,1034,4);
INSERT INTO `student` VALUES (35,'10000035','yang','c35','男',1,1,'2000-01-01','学生35','123456',1,1,1,1035,4);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table race (民族配置表)
#

DROP TABLE IF EXISTS `race`;
CREATE TABLE `race` (
        `race_id`       int(11)         NOT NULL,
        `race_name`     char(40)        NOT NULL,
        PRIMARY KEY (`race_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table race
#

LOCK TABLES `race` WRITE;
/*!40000 ALTER TABLE `race` DISABLE KEYS */;
INSERT INTO `race` VALUES (1,'汉族');
INSERT INTO `race` VALUES (2,'少数民族');
/*!40000 ALTER TABLE `race` ENABLE KEYS */;
UNLOCK TABLES;

# ======================================================
#
# Source for table classroom (教室表)
#
DROP TABLE IF EXISTS `classroom`;
CREATE TABLE `classroom` (
        `classroom_id`          int(11)         NOT NULL,
        `classroom_name`        char(100)       NOT NULL,
        `white_board`           char(20)        NOT NULL,
        `school_id`              int(11)         NOT NULL,
        PRIMARY KEY (`classroom_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Dumping data for table classroom
#
LOCK TABLES `classroom` WRITE;
/*!40000 ALTER TABLE `classroom` DISABLE KEYS */;
INSERT INTO `classroom` VALUES (1,'A教室','白板1',1);
INSERT INTO `classroom` VALUES (2,'B教室','白板2',1);
INSERT INTO `classroom` VALUES (3,'C教室','白板3',1);
INSERT INTO `classroom` VALUES (4,'D教室','白板4',1);
INSERT INTO `classroom` VALUES (5,'E教室','白板5',1);
/*!40000 ALTER TABLE `classroom` ENABLE KEYS */;
UNLOCK TABLES;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
