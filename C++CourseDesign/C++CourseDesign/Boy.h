#ifndef BOY_CLASS
#define BOY_CLASS

#include "Student.h"

class Boy:public Student
{
public:
	Boy(const string&, const bool&, const int&, const int&);
	void exercise();
protected:
	int health;
};

Boy::Boy(const string& n, const bool& s, const int& fn, const int& rn)
{
	name = n;
	floor_number = fn;
	room_number = rn;
	sex = s;
	fascination = Init_value::MALE_CHARM;
	weight = Init_value::MALE_WEIGHT;
	cost = Init_value::MALE_MONEY;
	health = Init_value::MALE_HEALTH;
}

#endif