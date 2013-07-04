#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include <vector>

#include "Init_value.h"

/*
*����Ϊ��ʾѧ��һ�����࣬�������ֵ����ԣ��Է���ѧϰ����ױ���˶��
*/
class Student
{

public:
	virtual bool eat(int){return true;}  //  ѧ���Է��
	virtual bool study(int){return true;}  //  ѧ��ѧϰ�
	virtual bool ownact(int){return true;}  //  ����Ϊ�˶����Ů��Ϊ��ױ�
	virtual int person_value(){return 0;}  //  �������ؽ���ֵ��Ů��������òֵ

	std::string	name;      //����
	bool sex;                      //�Ա�trueΪŮ����falseΪ����
	int	floor_number;    //¥��ţ���0��ʼ��
	int	room_number;   //����ţ���0��ʼ��
	int	fascination;         //����ֵ
	int	weight;                 //����
	int	cost;                      //��Ǯ
	std::vector<std::string> lover;  //��ǰ�����б�
	std::vector<std::string> past_lover;  //����ʷ
};

#endif