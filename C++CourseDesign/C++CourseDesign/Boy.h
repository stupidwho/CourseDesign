#ifndef BOY_CLASS
#define BOY_CLASS

#include "Student.h"

class Boy:public Student
{
public:
	Boy(const std::string&, const bool&, const int&, const int&);
	bool eat(int);
	bool study(int);
	bool ownact(int);
	int person_value();

protected:
	int health;
private:
	int weight_add(int, int, int);
	int cost_add(int);
	int health_add(int);
	int charm_add(int, int, int);
};

bool Boy::eat(int e)
{
	if (e < 0)
		return false;
	cost_add(e);
	charm_add(0, 0, weight_add(e, 0, 0));
	return true;
}

bool Boy::study(int s)
{
	if (s < 0)
		return false;
	charm_add(s, 0, weight_add(0, s, 0));
	return true;
}

bool Boy::ownact(int e)
{
	if (e < 0)
		return false;
	charm_add(0, health_add(e), weight_add(0, 0, e));
	return true;
}

int Boy::person_value()
{
	return health;
}

Boy::Boy(const std::string& n, const bool& s, const int& fn, const int& rn)
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



int Boy::weight_add(int f, int s, int e)
{
	weight += (f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT-e*Init_value::EXERCISE_WEIGHT);
	return f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT-e*Init_value::EXERCISE_WEIGHT;
}

int Boy::cost_add(int f)
{
	cost += f*Init_value::FOOD_COST;
	return f*Init_value::FOOD_COST;
}

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