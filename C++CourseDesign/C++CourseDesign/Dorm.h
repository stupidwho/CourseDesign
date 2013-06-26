#ifndef DORM_CLASS
#define DORM_CLASS

#include <vector>
#include <string>
#include <map>

#include "Init_value.h"
#include "split.h"
#include "Student.h"
#include "Girl.h"
#include "Boy.h"

typedef struct
{
	std::vector<std::string> member;    //已有宿舍成员
	int number;     //容量
	bool sex;         //宿舍人员性别
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //每层所含房间用vector记录

class Dorm
{
public:
	Dorm();
	bool enrol(std::string, bool, int, int);
	FLOOR_NUM& operator[](int);
	bool exists(int, int);
	bool move(std::string, int, int, int, int);
	bool quit(std::string);
	
	bool add(int);
	bool add(int, int);
	bool add(int, int, int);

	std::vector<FLOOR_NUM> floors;  //每座楼所含层用vector记录
	std::map<std::string,Student*> students;
	
};

Dorm::Dorm()
{
	for(int i=0; i<Init_value::FLOOR; i++)
	{
		FLOOR_NUM f;
		for(int j=0; j<Init_value::ROOM; j++)
		{
			ROOM_NUM tmp;
			tmp.sex = false;
			tmp.number = Init_value::CAPACITY;
			f.push_back(tmp);
		}
		floors.push_back(f);
	}
}

bool Dorm::enrol(string n, bool s, int fl, int rm)
{
	if (!exists(fl,rm) || floors[fl][rm].member.size()==floors[fl][rm].number 
		||floors[fl][rm].sex!=s)
		return false;
	Student *p;
	if (s)
		p = new Girl(n, s, fl, rm);
	else
		p = new Boy(n, s, fl, rm);
	floors[fl][rm].member.push_back(n);
	floors[fl][rm].sex = s;
	students[n] = p;
	return true;
}

FLOOR_NUM& Dorm::operator[](int i)
{
	return floors[i];
}

bool Dorm::exists(int fl, int rm)
{
	if (floors.size() < fl+1 || floors[fl].size() < rm+1)
		return false;
	else
		return true;
}

bool Dorm::move(std::string n, int flfrom, int rmfrom, int flto, int rmto)
{
	if (!exists(flfrom,rmfrom) || !exists(flto,rmto) 
		|| floors[flfrom][rmfrom].sex != floors[flto][rmto].sex
		|| floors[flto][rmto].member.size()>= floors[flto][rmto].number)
		return false;
	std::vector<std::string>& tmp = floors[flfrom][rmfrom].member;

	std::vector<string>::iterator  iter;
	for(iter = tmp.begin();
		iter != tmp.end(); iter++)
	{
		if (*iter == n)
		{
			tmp.erase(iter);
			floors[flfrom][rmfrom].member.push_back(n);
			students[n]->floor_number = flto;
			students[n]->room_number = rmto;
			break;
		}
	}
	if (iter == tmp.end())
		return false;

	return true;
}

bool Dorm::quit(std::string n)
{
	std::map<std::string,Student*>::iterator iter;
	if ((iter=students.find(n)) == students.end())
		return false;
	int fl = iter->second->floor_number;
	int rm = iter->second->room_number;
	std::vector<std::string>& tmp = floors[fl][rm].member;
	std::vector<string>::iterator  it;
	for(it = tmp.begin(); it != tmp.end(); it++)
	{
		if (*it == n)
		{
			tmp.erase(it);
			break;
		}
	}
	delete iter->second;
	students.erase(iter);
	return true;
}

bool Dorm::add(int fls)
{
}

bool Dorm::add(int, int);
	bool add(int, int, int);

#endif