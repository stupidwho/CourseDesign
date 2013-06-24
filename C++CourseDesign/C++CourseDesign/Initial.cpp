#include <string>
#include <vector>
#include <cstdlib>

#include "Initial.h"
#include "Init_value.h"
#include "split.h"

using namespace Init_value;

void init(std::istream& is)
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
	std::cout << FLOOR << std::endl;
	std::cout << ROOM << std::endl;
	std::cout << FEMALE_CHARM << std::endl;
	std::cout << FEMALE_LOOKS << std::endl;
}