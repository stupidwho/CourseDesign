#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include <vector>

class Student
{

public:
	virtual void eat(int){}
	virtual void study(int){}
	virtual void ownact(int){}

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

class Boy:public Student
{
public:
	Boy(const std::string&, const bool&, const int&, const int&);
	void eat(int);
	void study(int);
	void ownact(int);

protected:
	int health;
private:
	int weight_add(int, int, int);
	int cost_add(int);
	int health_add(int);
	int charm_add(int, int, int);
};



////////////////////////·Ö¸îÏß///////////////////////////////////////////////

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



#endif