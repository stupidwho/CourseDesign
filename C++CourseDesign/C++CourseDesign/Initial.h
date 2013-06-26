#ifndef INITIAL_FUNCTIONS
#define INITIAL_FUNCTIONS

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

#include "Init_value.h"
#include "split.h"
#include "Dorm.h"
#include "Student.h"

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
				Init_value::FLOOR = atoi(strs[1].c_str());
			else if (strs[0] == "ROOM:")
				Init_value::ROOM = atoi(strs[1].c_str());
			else if (strs[0] == "CAPACITY:")
				Init_value::CAPACITY = atoi(strs[1].c_str());
			else if (strs[0] == "FOOD_WEIGHT:")
				Init_value::FOOD_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "FOOD_COST:")
				Init_value::FOOD_COST = atoi(strs[1].c_str());
			else if (strs[0] == "STUDY_WEIGHT:")
				Init_value::STUDY_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "STUDY_CHARM:")
				Init_value::STUDY_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "MAKEUP_LOOKS:")
				Init_value::MAKEUP_LOOKS = atoi(strs[1].c_str());
			else if (strs[0] == "MAKEUP_COST:")
				Init_value::MAKEUP_COST = atoi(strs[1].c_str());
			else if (strs[0] == "EXERCISE_HEALTH:")
				Init_value::EXERCISE_HEALTH = atoi(strs[1].c_str());
			else if (strs[0] == "EXERCISE_WEIGHT:")
				Init_value::EXERCISE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_WEIGHT:")
				Init_value::MALE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_MONEY:")
				Init_value::MALE_MONEY = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_CHARM:")
				Init_value::MALE_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "MALE_HEALTH:")
				Init_value::MALE_HEALTH = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_WEIGHT:")
				Init_value::FEMALE_WEIGHT = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_MONEY:")
				Init_value::FEMALE_MONEY = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_CHARM:")
				Init_value::FEMALE_CHARM = atoi(strs[1].c_str());
			else if (strs[0] == "FEMALE_LOOKS:")
				Init_value::FEMALE_LOOKS = atoi(strs[1].c_str());
		}
	}
}

void inits(std::istream& is, Dorm &d)
{
	std::string str;
	std::vector<std::string> strs;
	int fl,ro;
	while (std::getline(is,str))
	{
		if (str.size() == 0)
			continue;
		strs = split(str);
		sscanf(strs[2].c_str(),"%d",&fl);
		sscanf(strs[4].c_str(),"%d",&ro);
		fl--;
		ro--;
		bool sex = (strcmp(strs[1].c_str(), "Ů") == 0);
		d.enrol(strs[0], sex, fl, ro);
	}
}

#endif