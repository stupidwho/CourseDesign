#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include <vector>

#include "Init_value.h"

using std::string;
using std::vector;

class Student
{
	friend class Dorm;
public:
	void eat();
	void study();
protected:
	string	name;
	bool sex;
	int	floor_number;
	int	room_number;
	int	fascination;
	int	weight;
	int	cost;
	vector<string> lover;
	vector<string> past_lover;
private:
};

#endif