#ifndef DORM_CLASS
#define DORM_CLASS

#include <vector>
#include <string>
#include <map>

#include "Dorm.h"
#include "split.h"
#include "Girl.h"
#include "Boy.h"

/*
*该类实现包含楼层、房间、以及学生的宿舍
*/

typedef struct
{
	std::vector<std::string> member;    //已有宿舍成员
	int number;     //容量
	bool sex;         //宿舍人员性别，true为女，false为男
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //每层所含房间用vector记录

class Dorm
{
public:
	std::vector<FLOOR_NUM> floors;  //每座楼所含层用vector记录

	//  用映射记录所有这栋宿舍的学生
	//  可通过学生名字找出对应的Student的对象，共享内存空间
	std::map<std::string,Student*> students;  

	Dorm();  //  构造函数
	~Dorm();
	FLOOR_NUM& operator[](int);  //  通过楼层号实现返回该楼层vector
	bool exists(int, int);  //  判断该楼层、房间是否存在
	bool enrol(std::string, bool, int, int);  //  实现入学
	bool move(std::string, int, int, int, int);  //  实现搬宿舍
	bool quit(std::string);  //  实现退学

	bool add(int);  //  增加楼层
	bool add(int, int);  //  增加房间
	bool add(int, int, int);  //  增加床位
};

Dorm::Dorm()
{
	for(int i=0; i<Init_value::FLOOR; i++)  //  添加Init_value::FLOOR层楼
	{
		FLOOR_NUM f;
		for(int j=0; j<Init_value::ROOM; j++)  //  添加Init_value::ROOM间房
		{
			ROOM_NUM tmp;
			tmp.sex = false;
			tmp.number = Init_value::CAPACITY;  //  初始化房间容量最大值
			f.push_back(tmp);
		}
		floors.push_back(f);
	}
}

Dorm::~Dorm()
{
	std::map<std::string,Student*>::iterator i;
	for(i = students.begin(); i!=students.end(); i++)
	{
		delete i->second;
	}
	floors.clear();
}

//返回第i层楼
FLOOR_NUM& Dorm::operator[](int i)
{
	return floors[i];
}

bool Dorm::exists(int fl, int rm)
{
	//  先判断fl层是否存在，再判断rm是否存在
	if (0 > fl || floors.size() < fl+1 || 0 > rm || floors[fl].size() < rm+1)
		return false;
	else
		return true;
}

bool Dorm::enrol(std::string n, bool s, int fl, int rm)
{
	//先判断是否存在该房号，再判断房间容量是否已满
	if (!exists(fl,rm) || floors[fl][rm].member.size()>=floors[fl][rm].number)  
		return false;
	//  判断是否为空，为空则忽略性别，否则需要判断性别是否相同
	else if (floors[fl][rm].member.size() != 0 && floors[fl][rm].sex != s)
		return false;

	Student *p;
	//  根据性别创建对象，用Student类型指针实现多态
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
	//  判断房号是否存在、容量是否未满、性别是否相同
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
			tmp.erase(iter);  //找到n以后删除
			floors[flfrom][rmfrom].member.push_back(n);  //从去的房号增加n的名字
			students[n]->floor_number = flto;  // 修改楼层、房间号
			students[n]->room_number = rmto;
			break;
		}
	}
	if (iter == tmp.end())  // 找不到表示不存在这个学生，返回false
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
			tmp.erase(it);  //找出并删除该学生所在房间的名字
			break;
		}
	}
	delete iter->second;  //回收对应学生指针指向的内存
	students.erase(iter);  //  删除该映射
	return true;
}

//增加fls层楼
bool Dorm::add(int fls)
{
	if (fls < 0)
		return false;
	for(int i=0; i<fls; i++)
	{
		FLOOR_NUM f;
		for(int j=0; j<Init_value::ROOM; j++)  //其余用默认值初始化
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

//对fl层增加rms间房
bool Dorm::add(int fl, int rms)
{
	if (!exists(fl,0) || rms < 0)
		return false;
	for(int i=0; i<rms; i++)  //其余用默认值初始化
	{
		ROOM_NUM tmp;
		tmp.sex = false;
		tmp.number = Init_value::CAPACITY;
		floors[fl].push_back(tmp);
	}
	return true;
}

//对fl层、rm房增加beds张床
bool Dorm::add(int fl, int rm, int beds)
{
	if (!exists(fl,rm) || beds < 0)
		return false;
	floors[fl][rm].number += beds;  // 修改容量
	return true;
}

#endif