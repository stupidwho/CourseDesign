#ifndef LOVE_FUNCTIONS
#define LOVE_FUNCTIONS

#include "Student.h"

bool fall_love(Student *, Student *);
bool fall_break(Student *, Student *);
int nrand(int);

bool court(Student *a, Student *b)
{
	if (fall_love(a,b))
	{
		a->lover.push_back(b->name);
		b->lover.push_back(a->name);
		return true;
	}
	else
	{
		return false;
	}
}

bool fall_love(Student *a, Student *b)
{
	double t = (double (a->fascination - b->fascination))/b->fascination*(nrand(3)+1);
	return 1.6>=t && t>=0.8;
}

bool breakup(Student *a, Student *b)
{
	if (fall_break(a, b))
	{
		std::vector<std::string>::iterator i;
		for(i = a->lover.begin(); i!=a->lover.end(); i++)
			if (*i == b->name)
			{
				a->lover.erase(i);
				break;
			}
		for(i = b->lover.begin(); i!=b->lover.end(); i++)
			if (*i == a->name)
			{
				b->lover.erase(i);
				break;
			}
		if (i != b->lover.end())
		{
			a->past_lover.push_back(b->name);
			b->past_lover.push_back(a->name);
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool fall_break(Student *a, Student *b)
{
	double t = abs((double)(a->fascination - b->fascination))
		/std::min(a->fascination, b->fascination)*(nrand(3)+1);
	return t > 1.6;
}

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