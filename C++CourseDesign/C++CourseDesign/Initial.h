#ifndef INITIAL_FUNCTIONS
#define INITIAL_FUNCTIONS

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

#include "Init_value.h"
#include "split.h"
#include "Dorm.h"
#include "Boy.h"
#include "Girl.h"

using namespace Init_value;

void initv(std::istream& is)
{
	std::string str;
	std::vector<std::string> strs;
	while (std::getline(is,str))
	{
		if (str.size() == 0 || str[0] == '/')
			continue;
		else
		{
			strs = split(str);
			if (strs[0] == "FLOOR:")
				FLOOR = atoi(strs[1].c_str());
			else if (strs[0] == "ROOM:")
				ROOM = atoi(strs[1].c_str());
			else if (strs[0] == "CAPACITY:")
				CAPACITY = atoi(strs[1].c_str());
			else if (strs[0] == "FOOD_WEIGHT:")
				FOOD_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "FOOD_COST:")
				FOOD_COST = atoi(strs[1].c_str());
			else if (strs[0] == "STUDY_WEIGHT:")
				STUDY_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "STUDY_CHARM:")
				STUDY_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "MAKEUP_LOOKS:")
				MAKEUP_LOOKS = atoi(strs[1].c_str());
			else if (strs[0] == "MAKEUP_COST:")
				MAKEUP_COST = atoi(strs[1].c_str());
			else if (strs[0] == "EXERCISE_HEALTH:")
				EXERCISE_HEALTH = atoi(strs[1].c_str());
			else if (strs[0] == "EXERCISE_WEIGHT:")
				EXERCISE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_WEIGHT:")
				MALE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_MONEY:")
				MALE_MONEY = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_CHARM:")
				MALE_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_HEALTH:")
				MALE_HEALTH = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_WEIGHT:")
				FEMALE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_MONEY:")
				FEMALE_MONEY = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_CHARM:")
				FEMALE_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_LOOKS:")
				FEMALE_LOOKS = atoi(strs[1].c_str());
		}
	}
}

void inits(std::istream& is, Dorm &d)
{
	std::string str;
	std::vector<std::string> strs;
	std::getline(is, str);
	strs = split(str);
	std::string t = strs[1];
	int fl;
	sscanf(strs[2].c_str(),"%d",&fl);
	int ro;
	sscanf(strs[4].c_str(),"%d",&ro);
	fl--;
	ro--;
	bool sex = (strs[1] != t);
	d.enrol(strs[0], sex, fl, ro);
	while (std::getline(is,str))
	{
		if (str.size() == 0)
			continue;
		strs = split(str);
		sscanf(strs[2].c_str(),"%d",&fl);
		sscanf(strs[4].c_str(),"%d",&ro);
		fl--;
		ro--;
		bool sex = (strs[1] != t);
		d.enrol(strs[0], sex, fl, ro);
	}
}

#endif