#ifndef GIRL_CLASS
#define GIRL_CLASS

#include "Student.h"

/*
*    ����Ļ���Ϊ������Student���̳�ʵ���麯�������Ա�ʾŮ��ѧ������
*/
class Girl:public Student
{
public:
	Girl(const std::string&, const bool&, const int&, const int&);  //�������Ĺ��캯��

	//���º���ΪStudent��ĳ���������Ҫ��������ʵ��
	bool eat(int);
	bool study(int);
	bool ownact(int);
	int person_value();

protected:
	int looks;   //Girl�����е�����ֵ

private:
	//���º���ΪŮ����һϵ������������ʵ�ֽ�����Ӧѧ��������Ӧֵ�޸�
	int weight_add(int, int);
	int cost_add(int, int);
	int looks_add(int);
	int charm_add(int, int, int);
};

//���º���Ϊ�����л�����麯����ʵ��

//ʵ��Ů���ĳԷ��
bool Girl::eat(int e)
{
	if (e < 0)
		return false;
	cost_add(e, 0);  //�Է��Ӱ���Ǯ����
	charm_add(0, 0, weight_add(e, 0));   //������Ӱ����������������Ӱ����������
	return true;
}

//ʵ��Ů����ѧϰ�
bool Girl::study(int s)
{
	if (s < 0)
		return false;
	charm_add(s, 0, weight_add(0, s));
	return true;
}

//ʵ��Ů���Ļ�ױ�
bool Girl::ownact(int m)
{
	if (m < 0)
		return false;
	cost_add(0, m);
	charm_add(0, looks_add(m), 0);
	return true;
}

//����Ů���������òֵ
int Girl::person_value()
{
	return looks;
}

//�������Ĺ��캯���������ֱ�Ϊ���֡��Ա�¥��š�����ţ������0��ʼ���㣩
Girl::Girl(const std::string& n, const bool& s, const int& fn, const int& rn)
{
	name = n;
	floor_number = fn;
	room_number = rn;
	sex = s;

	//  ���û�����ĳ�ʼֵ��ʼ����Ա����
	fascination = Init_value::FEMALE_CHARM;
	weight = Init_value::FEMALE_WEIGHT;
	cost = Init_value::FEMALE_MONEY;
	looks = Init_value::FEMALE_LOOKS;
}

//Ů���������������ݹ̶���ʽ����ó�
int Girl::weight_add(int f, int s)
{
	weight += (f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT);
	return f*Init_value::FOOD_WEIGHT-s*Init_value::STUDY_WEIGHT;
}

//Ů���������������ݹ̶���ʽ����ó�
int Girl::cost_add(int f, int m)
{
	cost += (f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST);
	return f*Init_value::FOOD_COST+m*Init_value::MAKEUP_COST;
}

//Ů����ò���������ݹ̶���ʽ����ó�
int Girl::looks_add(int m)
{
	int t = m*Init_value::MAKEUP_LOOKS;
	looks += t;
	if (looks > 100)
	{
		t -= (looks - 100);
		looks = 100;
	}
	return t;
}

//Ů������ֵ���������ݹ̶���ʽ����ó�
int Girl::charm_add(int s, int m, int w)
{
	int t = (s*Init_value::STUDY_CHARM + m/20 - w/4);
	fascination += t;
	if (fascination > 100)
	{
		t -= (fascination-100);
		fascination = 100;
	}
	return t;
}

#endif