#ifndef BOY_CLASS
#define BOY_CLASS

#include "Student.h"

/*
*    该类的基类为抽象类Student，继承实现虚函数，用以表示男生学生对象。
*/
class Boy:public Student
{
public:
	Boy(const std::string&, const bool&, const int&, const int&);  //带参数的构造函数
	
	//以下函数为Student类的抽象函数，需要声明并且实现
	bool eat(int);
	bool study(int);
	bool ownact(int);
	int person_value();

protected:
	int health;  //Boy类特有的属性值

private:
	//以下函数为男生的一系列增量函数，实现进行相应学生活动后对相应值修改
	int weight_add(int, int, int);
	int cost_add(int);
	int health_add(int);
	int charm_add(int, int, int);
};

//以下函数为对所有基类的虚函数的实现

//实现男生的吃饭活动
bool Boy::eat(int e)
{
	if (e < 0)
		return false;
	cost_add(e);  //吃饭活动影响金钱增量
	charm_add(0, 0, weight_add(e, 0, 0));  //联动地影响体重增量，进而影响魅力增量
	return true;
}

//实现男生的学习活动
bool Boy::study(int s)
{
	if (s < 0)
		return false;
	charm_add(s, 0, weight_add(0, s, 0));
	return true;
}

//实现男生的运动活动
bool Boy::ownact(int e)
{
	if (e < 0)
		return false;
	charm_add(0, health_add(e), weight_add(0, 0, e));
	return true;
}

//返回男生对象的健康值
int Boy::person_value()
{
	return health;
}

//带参数的构造函数，参数分别为名字、性别、楼层号、房间号（号码从0开始计算）
Boy::Boy(const std::string& n, const bool& s, const int& fn, const int& rn)
{
	name = n;
	floor_number = fn;
	room_number = rn;
	sex = s;

	//  用用户输入的初始值初始化成员函数
	fascination = Init_value::MALE_CHARM;
	weight = Init_value::MALE_WEIGHT;
	cost = Init_value::MALE_MONEY;
	health = Init_value::MALE_HEALTH;
}

//男生体重增量，根据固定公式计算得出
int Boy::weight_add(int f, int s, int e)
{
	weight += (f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT-e*Init_value::EXERCISE_WEIGHT);
	return f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT-e*Init_value::EXERCISE_WEIGHT;
}

//男生花费增量，根据固定公式计算得出
int Boy::cost_add(int f)
{
	cost += f*Init_value::FOOD_COST;
	return f*Init_value::FOOD_COST;
}

//男生健康增量，根据固定公式计算得出
int Boy::health_add(int e)
{
	int t = e*Init_value::EXERCISE_HEALTH;
	health += t;
	if (health > 100)
	{
		t -= (health - 100);
		health = 100;
	}
	return t;
}

//男生魅力值增量，根据固定公式计算得出
int Boy::charm_add(int s, int h, int w)
{
	int t = (s*Init_value::STUDY_CHARM + h/10 - w/5);
	fascination += t;
	if (fascination > 100)
	{
		t -= (fascination-100);
		fascination = 100;
	}
	return t;
}

#endif