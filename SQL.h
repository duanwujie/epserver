/**
* @file Sock.h
* @brief 常用的SQL查询脚本
* @author fU9ANg (bb.newlife@gmail.com)
* @version v1.0
* @date 2014-01-03
*/

#ifndef _SQL_H_
#define _SQL_H_

// 学生表操作SQL
#define SQL_GET_STU_INFO_BY_NUM                     \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.account AS account, s.password AS password FROM student AS s WHERE s.number=?"

#define SQL_GET_STU_INFO_BY_ACCOUT_AND_PW           \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.sex, s.age, s.birthday, s.account AS account, s.password AS password, n.province AS native_name, r.race_name AS race_name FROM student AS s, race AS r, native_place AS n WHERE r.race_id=s.race_id AND s.native_place_id=n.native_id AND s.account=? AND s.password=?"

#define SQL_GET_STU_INFO_BY_ACCOUT                  \
"SELECT s.number, s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.sex, s.age, s.birthday, s.account AS account, s.password AS password, n.province AS native_name, r.race_name AS race_name, cl.class_id, cl.class_name FROM student AS s, race AS r, native_place AS n, class AS cl where s.class_id=cl.class_id AND r.race_id=s.race_id AND s.native_place_id=n.native_id AND s.account=?"        

#define SQL_GET_STU_INFO_BY_NAME                    \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.account AS account, s.password AS password FROM student AS s WHERE s.first_name=? AND s.last_name=?"

#define SQL_GET_STU_LIST_BY_CLASSID                 \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.account AS account, s.password AS password, c.class_name AS class_name FROM student AS s, class AS c WHERE s.class_id=c.class_id AND c.class_id=?"

#define SQL_GET_STU_LIST_BY_CLASSNAME               \
"SELECT s.student_id AS student_id, s.first_name AS first_name, s.last_name AS last_name, s.account AS account, s.password AS password, c.class_name AS class_name FROM student AS s, class AS c WHERE s.class_id=c.class_id AND c.class_name=?"

// 教师表操作SQL
#define SQL_GET_TEA_INFO_BY_ID                      \
"SELECT t.teacher_id AS teacher_id, t.last_name AS last_name, t.first_name AS first_name, t.sex AS sex, t.birthday AS birthday, t.account AS account, t.password AS password FROM teacher AS t WHERE t.teacher_id=?"

#define SQL_GET_TEA_INFO_BY_NAME                    \
"SELECT t.teacher_id AS teacher_id, t.last_name AS last_name, t.first_name AS first_name, t.sex AS sex, t.birthday AS birthday, t.account AS account, t.password AS password FROM teacher AS t WHERE t.first_name=? AND t.last_name=?"

#define SQL_GET_TEA_INFO_BY_ACCOUNT                 \
"SELECT t.teacher_id AS teacher_id, t.last_name AS last_name, t.first_name AS first_name, t.sex AS sex, t.birthday AS birthday, t.age AS age, t.account AS account, t.password AS password, r.race_name AS race_name, n.province AS native_name, s.school_id AS school_id, s.school_name AS school_name FROM teacher AS t, native_place AS n, race AS r, school AS s WHERE r.race_id=t.race_id AND t.native_place_id=n.native_id AND s.school_id=t.school_id AND t.account=?"

#define SQL_GET_TEA_INFO_BY_ACCOUNT_AND_PW          \
"SELECT t.teacher_id AS teacher_id, t.last_name AS last_name, t.first_name AS first_name, t.sex AS sex, t.birthday AS birthday, t.age AS age, t.account AS account, t.password AS password, r.race_name AS race_name, n.province AS native_name, s.school_id AS school_id, s.school_name AS school_name FROM teacher AS t, native_place AS n, race AS r, school AS s WHERE r.race_id=t.race_id AND t.native_place_id=n.native_id AND s.school_id=t.school_id AND t.account=? AND t.password=?"

// 课程表操作SQL
#define SQL_GET_GRADE_COURSE_LIST                   \
"SELECT g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id"

#define SQL_GET_COURSE_LIST_BY_GRADE_NAME           \
"SELECT g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id AND g.grade_name=?"

#define SQL_GET_COURSE_LIST_BY_GRADE_ID             \
"SELECT c.course_id, g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id AND g.grade_id=?"

#define SQL_GET_COURSE_LIST_BY_TYPE                 \
"SELECT g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id AND cg.group_name=?"

#define SQL_GET_COURSE_BY_GRADE_AND_NAME            \
"SELECT g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id AND g.grade_name=? AND c.course_name=?"

#define SQL_GET_COURSE_BY_GRADE_AND_TYPE            \
"SELECT g.grade_name, c.course_name, cg.group_name, c.language, c.art, c.community, c.health, c.science, c.resPath FROM grade AS g, course AS c, course_group as cg, grade_course as gc WHERE g.grade_id=gc.grade_id AND gc.course_id=c.course_id AND c.group_id=cg.group_id AND g.grade_name=? AND cg.group_name=?"

// 年级和班级操作SQL
#define SQL_GET_ALL_GRADE_LIST_BY_SCHOOL_ID         \
"SELECT g.grade_id AS grade_id, g.grade_name AS grade_name FROM grade AS g, school AS s WHERE s.school_id=g.school_id AND s.school_id=?"

#define SQL_GET_ALL_CLASS_LIST                      \
"SELECT g.grade_name AS grade_name, c.class_name AS class_name, t.last_name, t.first_name FROM grade AS g, class AS c, teacher AS t WHERE c.class_teacher_id=t.teacher_id AND c.grade_id=g.grade_id"

#define SQL_GET_CLASS_LIST_BY_GRADE_NAME            \
"SELECT g.grade_name AS grade_name, c.class_name AS class_name, t.last_name, t.first_name FROM grade AS g, class AS c, teacher AS t WHERE c.class_teacher_id=t.teacher_id AND c.grade_id=g.grade_id AND g.grade_name=?"

#define SQL_GET_CLASS_LIST_BY_GRADE_ID              \
"SELECT g.grade_name AS grade_name, c.class_id, c.class_name AS class_name FROM grade AS g, class AS c WHERE c.grade_id=g.grade_id AND g.grade_id=?"

// 功能内容表SQL
#define SQL_GET_FUNC_LIST                           \
"SELECT func_id AS id, func_name AS name, res_path FROM func"

#define SQL_GET_FUNC_LIST_BY_TYPE                   \
"SELECT f.func_id AS id, f.func_name AS name, f.res_path AS res_path FROM client_type_func AS ctf, client_type AS ct, func AS f WHERE ctf.func_id=f.func_id AND ctf.client_type_id=ct.client_type_id AND ct.client_type_id=?"

// 教室表SQL
#define SQL_GET_CLASSROOM_LIST_BY_SCHOOL_ID         \
"SELECT classroom_id, classroom_name, white_board, school_id FROM classroom WHERE school_id=?"

#endif
