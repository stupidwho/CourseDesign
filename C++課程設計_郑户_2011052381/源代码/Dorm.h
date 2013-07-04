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
*����ʵ�ְ���¥�㡢���䡢�Լ�ѧ��������
*/

typedef struct
{
	std::vector<std::string> member;    //���������Ա
	int number;     //����
	bool sex;         //������Ա�Ա�trueΪŮ��falseΪ��
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //ÿ������������vector��¼

class Dorm
{
public:
	std::vector<FLOOR_NUM> floors;  //ÿ��¥��������vector��¼

	//  ��ӳ���¼�����ⶰ�����ѧ��
	//  ��ͨ��ѧ�������ҳ���Ӧ��Student�Ķ��󣬹����ڴ�ռ�
	std::map<std::string,Student*> students;  

	Dorm();  //  ���캯��
	~Dorm();
	FLOOR_NUM& operator[](int);  //  ͨ��¥���ʵ�ַ��ظ�¥��vector
	bool exists(int, int);  //  �жϸ�¥�㡢�����Ƿ����
	bool enrol(std::string, bool, int, int);  //  ʵ����ѧ
	bool move(std::string, int, int, int, int);  //  ʵ�ְ�����
	bool quit(std::string);  //  ʵ����ѧ

	bool add(int);  //  ����¥��
	bool add(int, int);  //  ���ӷ���
	bool add(int, int, int);  //  ���Ӵ�λ
};

Dorm::Dorm()
{
	for(int i=0; i<Init_value::FLOOR; i++)  //  ���Init_value::FLOOR��¥
	{
		FLOOR_NUM f;
		for(int j=0; j<Init_value::ROOM; j++)  //  ���Init_value::ROOM�䷿
		{
			ROOM_NUM tmp;
			tmp.sex = false;
			tmp.number = Init_value::CAPACITY;  //  ��ʼ�������������ֵ
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

//���ص�i��¥
FLOOR_NUM& Dorm::operator[](int i)
{
	return floors[i];
}

bool Dorm::exists(int fl, int rm)
{
	//  ���ж�fl���Ƿ���ڣ����ж�rm�Ƿ����
	if (0 > fl || floors.size() < fl+1 || 0 > rm || floors[fl].size() < rm+1)
		return false;
	else
		return true;
}

bool Dorm::enrol(std::string n, bool s, int fl, int rm)
{
	//���ж��Ƿ���ڸ÷��ţ����жϷ��������Ƿ�����
	if (!exists(fl,rm) || floors[fl][rm].member.size()>=floors[fl][rm].number)  
		return false;
	//  �ж��Ƿ�Ϊ�գ�Ϊ��������Ա𣬷�����Ҫ�ж��Ա��Ƿ���ͬ
	else if (floors[fl][rm].member.size() != 0 && floors[fl][rm].sex != s)
		return false;

	Student *p;
	//  �����Ա𴴽�������Student����ָ��ʵ�ֶ�̬
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
	//  �жϷ����Ƿ���ڡ������Ƿ�δ�����Ա��Ƿ���ͬ
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
			tmp.erase(iter);  //�ҵ�n�Ժ�ɾ��
			floors[flfrom][rmfrom].member.push_back(n);  //��ȥ�ķ�������n������
			students[n]->floor_number = flto;  // �޸�¥�㡢�����
			students[n]->room_number = rmto;
			break;
		}
	}
	if (iter == tmp.end())  // �Ҳ�����ʾ���������ѧ��������false
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
			tmp.erase(it);  //�ҳ���ɾ����ѧ�����ڷ��������
			break;
		}
	}
	delete iter->second;  //���ն�Ӧѧ��ָ��ָ����ڴ�
	students.erase(iter);  //  ɾ����ӳ��
	return true;
}

//����fls��¥
bool Dorm::add(int fls)
{
	if (fls < 0)
		return false;
	for(int i=0; i<fls; i++)
	{
		FLOOR_NUM f;
		for(int j=0; j<Init_value::ROOM; j++)  //������Ĭ��ֵ��ʼ��
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

//��fl������rms�䷿
bool Dorm::add(int fl, int rms)
{
	if (!exists(fl,0) || rms < 0)
		return false;
	for(int i=0; i<rms; i++)  //������Ĭ��ֵ��ʼ��
	{
		ROOM_NUM tmp;
		tmp.sex = false;
		tmp.number = Init_value::CAPACITY;
		floors[fl].push_back(tmp);
	}
	return true;
}

//��fl�㡢rm������beds�Ŵ�
bool Dorm::add(int fl, int rm, int beds)
{
	if (!exists(fl,rm) || beds < 0)
		return false;
	floors[fl][rm].number += beds;  // �޸�����
	return true;
}

#endif