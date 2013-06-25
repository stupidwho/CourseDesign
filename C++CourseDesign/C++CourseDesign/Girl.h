#ifndef GIRL_CLASS
#define GIRL_CLASS

#include "Student.h"

class Girl:public Student
{
public:
	Girl(const string&, const bool&, const int&, const int&);
	void makeup();
	
	int looks;
};

Girl::Girl(const string& n, const bool& s, const int& fn, const int& rn)
{
	name = n;
	floor_number = fn;
	room_number = rn;
	sex = s;
	fascination = Init_value::FEMALE_CHARM;
	weight = Init_value::FEMALE_WEIGHT;
	cost = Init_value::FEMALE_MONEY;
	looks = Init_value::FEMALE_LOOKS;
}

#endif