#ifndef DORM_CLASS
#define DORM_CLASS

#include <vector>
#include <string>
#include <map>

#include "Dorm.h"
#include "split.h"
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
	std::vector<FLOOR_NUM> floors;  //每座楼所含层用vector记录
	std::map<std::string,Student*> students;

	Dorm();
	FLOOR_NUM& operator[](int);
	bool exists(int, int);
	bool enrol(std::string, bool, int, int);
	bool move(std::string, int, int, int, int);
	bool quit(std::string);

	bool add(int);
	bool add(int, int);
	bool add(int, int, int);
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

bool Dorm::enrol(std::string n, bool s, int fl, int rm)
{
	if (!exists(fl,rm) || floors[fl][rm].member.size()>=floors[fl][rm].number)
		return false;
	else if (floors[fl][rm].member.size() != 0 && floors[fl][rm].sex != s)
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

bool Dorm::move(std::string n, int flfrom, int rmfrom, int flto, int rmto)
{
	if (!exists(flfrom,rmfrom) || !exists(flto,rmto) 
		|| floors[flto][rmto].member.size()>= floors[flto][rmto].number)
		return false;
	else if (floors[flto][rmto].member.size() !=0 
		&& floors[flfrom][rmfrom].sex != floors[flto][rmto].sex)
		return false;

	floors[flto][rmto].sex = floors[flfrom][rmfrom].sex;
	std::vector<std::string>& tmp = floors[flfrom][rmfrom].member;

	std::vector<std::string>::iterator  iter;
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
	std::vector<std::string>::iterator  it;
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
	for(int i=0; i<fls; i++)
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
	return true;
}

bool Dorm::add(int fl, int rms)
{
	if (floors.size() < fl+1)
		return false;
	for(int i=0; i<rms; i++)
	{
		ROOM_NUM tmp;
		tmp.sex = false;
		tmp.number = Init_value::CAPACITY;
		floors[fl].push_back(tmp);
	}
	return true;
}

bool Dorm::add(int fl, int rm, int beds)
{
	if (!exists(fl,rm))
		return false;
	floors[fl][rm].number += beds;
	return true;
}

#endif