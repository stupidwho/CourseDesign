#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include <vector>

#include "Init_value.h"

class Student
{

public:
	virtual bool eat(int){return true;}
	virtual bool study(int){return true;}
	virtual bool ownact(int){return true;}
	virtual int person_value(){return 0;}
	std::string	name;
	bool sex;
	int	floor_number;
	int	room_number;
	int	fascination;
	int	weight;
	int	cost;
	std::vector<std::string> lover;
	std::vector<std::string> past_lover;
};

#endif