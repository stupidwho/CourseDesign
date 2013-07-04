#ifndef INITIAL_FUNCTIONS
#define INITIAL_FUNCTIONS

/*
*该文件作用为实现各种初始化的函数
*/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

#include "split.h"
#include "Dorm.h"
#include "Student.h"
#include "Init_value.h"

//  从输入流is读入文件的默认配置
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

//从输入流is读入宿舍初始化数据，保存在d中
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
		fl--;  // 输入时从1开始，因此减1使得号码从0开始
		ro--;
		bool sex = (strcmp(strs[1].c_str(), "Ů") == 0);  // 判断性别
		
		d.enrol(strs[0], sex, fl, ro);
	}
}

#endif