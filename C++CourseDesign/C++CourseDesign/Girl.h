#ifndef GIRL_CLASS
#define GIRL_CLASS

#include "Student.h"

/*
*    该类的基类为抽象类Student，继承实现虚函数，用以表示女生学生对象。
*/
class Girl:public Student
{
public:
	Girl(const std::string&, const bool&, const int&, const int&);  //带参数的构造函数

	//以下函数为Student类的抽象函数，需要声明并且实现
	bool eat(int);
	bool study(int);
	bool ownact(int);
	int person_value();

protected:
	int looks;   //Girl类特有的属性值

private:
	//以下函数为女生的一系列增量函数，实现进行相应学生活动后对相应值修改
	int weight_add(int, int);
	int cost_add(int, int);
	int looks_add(int);
	int charm_add(int, int, int);
};

//以下函数为对所有基类的虚函数的实现

//实现女生的吃饭活动
bool Girl::eat(int e)
{
	if (e < 0)
		return false;
	cost_add(e, 0);  //吃饭活动影响金钱增量
	charm_add(0, 0, weight_add(e, 0));   //联动地影响体重增量，进而影响魅力增量
	return true;
}

//实现女生的学习活动
bool Girl::study(int s)
{
	if (s < 0)
		return false;
	charm_add(s, 0, weight_add(0, s));
	return true;
}

//实现女生的化妆活动
bool Girl::ownact(int m)
{
	if (m < 0)
		return false;
	cost_add(0, m);
	charm_add(0, looks_add(m), 0);
	return true;
}

//返回女生对象的容貌值
int Girl::person_value()
{
	return looks;
}

//带参数的构造函数，参数分别为名字、性别、楼层号、房间号（号码从0开始计算）
Girl::Girl(const std::string& n, const bool& s, const int& fn, const int& rn)
{
	name = n;
	floor_number = fn;
	room_number = rn;
	sex = s;

	//  用用户输入的初始值初始化成员函数
	fascination = Init_value::FEMALE_CHARM;
	weight = Init_value::FEMALE_WEIGHT;
	cost = Init_value::FEMALE_MONEY;
	looks = Init_value::FEMALE_LOOKS;
}

//女生体重增量，根据固定公式计算得出
int Girl::weight_add(int f, int s)
{
	weight += (f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT);
	return f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT;
}

//女生花费增量，根据固定公式计算得出
int Girl::cost_add(int f, int m)
{
	cost += (f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST);
	return f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST;
}

//女生容貌增量，根据固定公式计算得出
int Girl::looks_add(int m)
{
	int t = m*Init_value::MAKEUP_LOOKS;
	looks += t;
	if (looks > 100)
	{
		t -= (looks - 100);
		looks = 100;
	}
	return t;
}

//女生魅力值增量，根据固定公式计算得出
int Girl::charm_add(int s, int m, int w)
{
	int t = (s*Init_value::STUDY_CHARM + m/20 - w/4);
	fascination += t;
	if (fascination > 100)
	{
		t -= (fascination-100);
		fascination = 100;
	}
	return t;
}

#endif