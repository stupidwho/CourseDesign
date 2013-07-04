#ifndef LOVE_FUNCTIONS
#define LOVE_FUNCTIONS

/*
*包含了court、breakup函数，实现学生的追求与分手
*/

#include "Student.h"

bool fall_love(Student *, Student *);  //  返回是否恋爱
bool fall_break(Student *, Student *);  //  返回是否分手
int nrand(int);  // 返回随机数

//  实现a追求b
bool court(Student *a, Student *b)
{
	std::vector<std::string>::iterator i;
	for(i=a->lover.begin(); i!=a->lover.end(); i++)  // 如果已经恋爱中则直接返回true
		if (*i == b->name)
			return true;

	if (fall_love(a,b))  //  按公式随机决定是否恋爱成功
	{
		a->lover.push_back(b->name);
		b->lover.push_back(a->name);
		return true;
	}
	else
		return false;
}

//  按公式计算a追求b是否成功
bool fall_love(Student *a, Student *b)
{
	double t = (double (a->fascination - b->fascination))/b->fascination*(nrand(3)+1);
	return 1.6>=t && t>=0.8;
}

//  按公式计算a和b分手是否成功
bool breakup(Student *a, Student *b)
{
	std::vector<std::string>::iterator i;
	for(i=a->lover.begin(); i!=a->lover.end(); i++)
		if (*i == b->name)
			break;
	if (i == a->lover.end())  // 若本不是情侣则返回true
		return true;

	if (fall_break(a, b))  //  判断是否分手成功
	{
		std::vector<std::string>::iterator i;
		for(i = a->lover.begin(); i!=a->lover.end(); i++)
		{
			if (*i == b->name)
			{
				a->lover.erase(i);  //从a当前恋人中删除
				break;
			}
		}
		for(i = b->lover.begin(); i!=b->lover.end(); i++)
		{
			if (*i == a->name)
			{
				b->lover.erase(i);  //从b当前恋人中删除
				break;
			}
		}

		a->past_lover.push_back(b->name);  //计入双方的恋爱史记录
		b->past_lover.push_back(a->name);  
		return true;
	}
	else
	{
		return false;
	}
}

//  按公式计算是否分手成功
bool fall_break(Student *a, Student *b)
{
	double t = abs((double)(a->fascination - b->fascination))
		/std::min(a->fascination, b->fascination)*(nrand(3)+1);
	return t > 1.6;
}

//取0~n-1之间的随机数
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