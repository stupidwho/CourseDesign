#ifndef GIRL_CLASS
#define GIRL_CLASS

#include "Student.h"

class Girl:public Student
{
public:
	Girl(const std::string&, const bool&, const int&, const int&);
	void eat(int);
	void study(int);
	void ownact(int);

protected:
	int looks;
private:
	int weight_add(int, int);
	int cost_add(int, int);
	int looks_add(int);
	int charm_add(int, int, int);
};

void Girl::eat(int e)
{
	cost_add(e, 0);
	charm_add(0, 0, weight_add(e, 0));
}

void Girl::study(int s)
{
	charm_add(s, 0, weight_add(0, s));
}

void Girl::ownact(int m)
{
	cost_add(0, m);
	charm_add(0, looks_add(m), 0);
}

Girl::Girl(const std::string& n, const bool& s, const int& fn, const int& rn)
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



int Girl::weight_add(int f, int s)
{
	weight += (f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT);
	return f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT;
}

int Girl::cost_add(int f, int m)
{
	cost += (f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST);
	return f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST;
}

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