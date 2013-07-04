#ifndef LOVE_FUNCTIONS
#define LOVE_FUNCTIONS

/*
*������court��breakup������ʵ��ѧ����׷�������
*/

#include "Student.h"

bool fall_love(Student *, Student *);  //  �����Ƿ�����
bool fall_break(Student *, Student *);  //  �����Ƿ����
int nrand(int);  // ���������

//  ʵ��a׷��b
bool court(Student *a, Student *b)
{
	std::vector<std::string>::iterator i;
	for(i=a->lover.begin(); i!=a->lover.end(); i++)  // ����Ѿ���������ֱ�ӷ���true
		if (*i == b->name)
			return true;

	if (fall_love(a,b))  //  ����ʽ��������Ƿ������ɹ�
	{
		a->lover.push_back(b->name);
		b->lover.push_back(a->name);
		return true;
	}
	else
		return false;
}

//  ����ʽ����a׷��b�Ƿ�ɹ�
bool fall_love(Student *a, Student *b)
{
	double t = (double (a->fascination - b->fascination))/b->fascination*(nrand(3)+1);
	return 1.6>=t && t>=0.8;
}

//  ����ʽ����a��b�����Ƿ�ɹ�
bool breakup(Student *a, Student *b)
{
	std::vector<std::string>::iterator i;
	for(i=a->lover.begin(); i!=a->lover.end(); i++)
		if (*i == b->name)
			break;
	if (i == a->lover.end())  // �������������򷵻�true
		return true;

	if (fall_break(a, b))  //  �ж��Ƿ���ֳɹ�
	{
		std::vector<std::string>::iterator i;
		for(i = a->lover.begin(); i!=a->lover.end(); i++)
		{
			if (*i == b->name)
			{
				a->lover.erase(i);  //��a��ǰ������ɾ��
				break;
			}
		}
		for(i = b->lover.begin(); i!=b->lover.end(); i++)
		{
			if (*i == a->name)
			{
				b->lover.erase(i);  //��b��ǰ������ɾ��
				break;
			}
		}

		a->past_lover.push_back(b->name);  //����˫��������ʷ��¼
		b->past_lover.push_back(a->name);  
		return true;
	}
	else
	{
		return false;
	}
}

//  ����ʽ�����Ƿ���ֳɹ�
bool fall_break(Student *a, Student *b)
{
	double t = abs((double)(a->fascination - b->fascination))
		/std::min(a->fascination, b->fascination)*(nrand(3)+1);
	return t > 1.6;
}

//ȡ0~n-1֮��������
int nrand(int n)
{
	const int bucket_size = RAND_MAX / n;
	int r;
	do
	r = rand() / bucket_size;
	while (r >= n);
	return r;
}

#endif