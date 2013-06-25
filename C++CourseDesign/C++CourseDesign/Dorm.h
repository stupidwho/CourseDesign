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
	std::vector<std::string> member;    //���������Ա
	int number;     //����
	bool sex;         //������Ա�Ա�
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //ÿ������������vector��¼

class Dorm
{
public:
	Dorm();
	bool enrol(std::string, bool, int, int);
	FLOOR_NUM& operator[](int);
	bool move(std::string, int, int, int, int);
	bool quit(std::string, int, int);
	
	bool add(int);
	bool add(int, int);
	bool add(int, int, int);

	std::vector<FLOOR_NUM> floors;  //ÿ��¥��������vector��¼
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

#endif