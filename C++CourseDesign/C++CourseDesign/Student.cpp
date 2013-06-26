#include "Student.h"

void Boy::eat(int e)
{
	cost_add(e);
	charm_add(0, 0, weight_add(e, 0, 0));
}

void Boy::study(int s)
{
	charm_add(s, 0, weight_add(0, s, 0));
}

void Boy::ownact(int e)
{
	charm_add(0, health_add(e), weight_add(0, 0, e));
}

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
	int t = e*Init_value::MAKEUP_LOOKS;
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

/////////////////////////////////////////////////////////////////////////////

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