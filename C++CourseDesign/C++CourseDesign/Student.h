#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include <vector>

#include "Init_value.h"

/*
*该类为表示学生一个基类，包含名字等属性，吃饭、学习、化妆、运动活动
*/
class Student
{

public:
	virtual bool eat(int){return true;}  //  学生吃饭活动
	virtual bool study(int){return true;}  //  学生学习活动
	virtual bool ownact(int){return true;}  //  男生为运动活动，女生为化妆活动
	virtual int person_value(){return 0;}  //  男生返回健康值，女生返回容貌值

	std::string	name;      //名字
	bool sex;                      //性别，true为女生，false为男生
	int	floor_number;    //楼层号（从0开始）
	int	room_number;   //房间号（从0开始）
	int	fascination;         //魅力值
	int	weight;                 //体重
	int	cost;                      //金钱
	std::vector<std::string> lover;  //当前爱人列表
	std::vector<std::string> past_lover;  //恋爱史
};

#endif