#ifndef QUERY_FUNCTIONS
#define QUERY_FUNCTIONS

/*
*���ļ��������ֲ�ѯ������ʵ�ֲ�ѯ����
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Dorm.h"

using std::cin;
using std::cout;
using std::endl;

//  ��ʾ������
int main_interface();

//��ѯ����
void query_weight(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//��ѯ��Ǯ
void query_money(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//��ѯ����ֵ
void query_charm(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//��ѯѧ������ֵ
void query_person(std::vector<Student*>&);

//��ѯѧ����Ϣ
void query_student(Dorm&);

//��ѯ������Ϣ
void query_room(Dorm&);

//���в�ѯ����
void query(Dorm& d)
{
	int n;
	while (1)
	{
		n = main_interface();
		std::vector<Student*> vec,g_vec,b_vec;  // �ֱ���vector��¼����ѧ����������Ů��

		std::map<std::string, Student*>::iterator i;
		for(i = d.students.begin(); i!=d.students.end(); i++)
		{
			vec.push_back(i->second);
			if (i->second->sex)
				g_vec.push_back(i->second);
			else
				b_vec.push_back(i->second);
		}
		system("cls");
		
		//����ѡ����ö�Ӧ����
		if (n == 9)
			break;
		switch(n)
		{
		case 1: query_weight(d, vec, g_vec, b_vec); system("cls"); break;
		case 2: query_money(d, vec, g_vec, b_vec); system("cls"); break;
		case 3: query_charm(d, vec, g_vec, b_vec); system("cls"); break;
		case 4: query_person(g_vec); break;
		case 5: query_person(b_vec); break;
		case 6: query_student(d); break;
		case 7: query_room(d); break;
		case 8: system("cls"); break;
		default:;
		}
	}
}

//  ��ʾ�����沢������ѡ�񣬷���ѡ������
int main_interface()
{
	cout << endl << "                 ***��ӭ��ѯɽ���Ǳߣ������Ǳ�ѧУѧ����Ϣ***" << endl << endl;
	cout << "             ****************************************************" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             *         Ոݔ���ԃ������̖����ENTER�_�J:         *" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             *         1.�w��          2.���X                   *" << endl;
	cout << "             *         3.����ֵ        4.��òֵ                 *" << endl;
	cout << "             *         5.����ֵ        6.�W����Ϣ               *" << endl;
	cout << "             *         7.���g��Ϣ      8.����                   *" << endl;
	cout << "             *         9.�Y����ԃ                               *" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             ****************************************************" << endl;
	cout << "Ոݔ����̖��";
	int n;
	cin >> n;
	return n;
}

//  ���ء���Ǯ������ֵ��ʾʱѡ�����ͬ�������һ����ʵ��Ȼ������
void q_input(std::string& s)
{
	cout << endl << "Ոݔ���ԃ" << s << "�Ĺ�����" << endl;
	cout << "1.ȫ�w�W��    2.����     3.Ů��    4.������һ����" << endl;
	cout << endl << "Ոݔ����̖����ENTER�_�J��";
}

/////////////��������ء���Ǯ������ֵ��ѯ��Ϊ���Ʒ�����ֻ��ϸ�ڴ���ͬ//////////////////

////////////////////////////////�w�ز�ԃ//////////////////////////////////////////////////
bool cmp1(Student *a, Student *b)
{
	if (a->weight == b->weight)
		return a->name < b->name;
	else
		return a->weight < b->weight;
}

//�������ѧ�������ص���ֵ���Լ������������ֵ�����ض���Χ������
void qw_output(std::vector<Student*>& vec)
{
	int n;
	// �����ֵ
	cout << "��Сֵ��  " << vec[0]->name << "  " <<vec[0]->weight << endl;
	cout << "���ֵ��  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->weight << endl;
	cout << endl << "�Y��Ոݔ��1����ֵ������ԃՈݔ��2��";
	cin >> n;

	if (2 == n)
	{
		// ������������÷�Χ��ֵ�Ͷ�Ӧѧ��
		cout << endl << "Ոݔ�빠����";
		int a,b;
		cin >> a >> b;
		cout << endl;

		if (a > b)
		{
			n = a; a = b; b= n;
		}
		std::vector<Student*>::iterator iter;
		for(iter = vec.begin(); iter != vec.end(); iter++)
		{
			if (a <=(*iter)->weight && (*iter)->weight <=b)
				cout << (*iter)->name << "  " << (*iter)->weight << endl;
		}
	}// end of    if(2 == n)
}

//ͨ��ѡ��ķ�Χ����ȫ��ѧ������������Ů��ѡ�����
void query_weight(Dorm& d,std::vector<Student*>& vec, std::vector<Student*>& g_vec, std::vector<Student*>& b_vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp1);
	sort(g_vec.begin(),g_vec.end(),cmp1);
	sort(b_vec.begin(),b_vec.end(),cmp1);

	while (1)
	{
		std::string a = "�w��";
		q_input(a);  // �������ѡ��
		cin >> n;
		if (4 == n)
		{
			system("cls");
			break;
		}
		if (1 == n)
		{
			qw_output(vec);  // ����Χ��ȫ��ѧ��������vec
		}
		else if (2 == n)
			qw_output(b_vec);  // ����Χ��ȫ������������b_vec
		else if (3 == n)
			qw_output(g_vec);  // ����Χ��ȫ��Ů��������g_vec
		else
			cout << "ݔ��ָ���e�`��" << endl;
	}
}


////////////////////////////���X��ԃ////////////////////////////////////////////////////
bool cmp2(Student *a, Student *b)
{
	if (a->cost == b->cost)
		return a->name < b->name;
	else
		return a->cost < b->cost;
}

void qm_output(std::vector<Student*>& vec)
{
	int n;
	cout << "��Сֵ��  " << vec[0]->name << "  " <<vec[0]->cost << endl;
	cout << "���ֵ��  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->cost << endl;
	cout << endl << "�Y��Ոݔ��1����ֵ������ԃՈݔ��2��";
	cin >> n;

	if (2 == n)
	{
		cout << endl << "Ոݔ�빠����";
		int a,b;
		cin >> a >> b;
		cout << endl;

		if (a > b)
		{
			n = a; a = b; b= n;
		}
		std::vector<Student*>::iterator iter;
		for(iter = vec.begin(); iter != vec.end(); iter++)
		{
			if (a <=(*iter)->cost && (*iter)->cost <=b)
				cout << (*iter)->name << "  " << (*iter)->cost << endl;
		}
	}// end of    if(2 == n)
}

void query_money(Dorm& d,std::vector<Student*>& vec, std::vector<Student*>& g_vec, std::vector<Student*>& b_vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp2);
	sort(g_vec.begin(),g_vec.end(),cmp2);
	sort(b_vec.begin(),b_vec.end(),cmp2);

	while (1)
	{
		std::string a = "���X";
		q_input(a);
		cin >> n;

		if (4 == n)
		{
			system("cls");
			break;
		}
		if (1 == n)
		{
			qm_output(vec);
		}
		else if (2 == n)
			qm_output(b_vec);
		else if (3 == n)
			qm_output(g_vec);
		else
			cout << "ݔ��ָ���e�`��" << endl;
	}
}

////////////////////////////����ֵ��ԃ//////////////////////////////////////////////////
bool cmp3(Student *a, Student *b)
{
	if (a->fascination == b->fascination)
		return a->name < b->name;
	else
		return a->fascination < b->fascination;
}

void qf_output(std::vector<Student*>& vec)
{
	int n;
	cout << "��Сֵ��  " << vec[0]->name << "  " <<vec[0]->fascination << endl;
	cout << "���ֵ��  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->fascination << endl;
	cout << endl << "1.�Y��ݔ��;  2.��ֵ������ԃ           Ոݔ�룺";
	cin >> n;

	if (2 == n)
	{
		cout << endl << "Ոݔ�빠����";
		int a,b;
		cin >> a >> b;
		cout << endl;

		if (a > b)
		{
			n = a; a = b; b= n;
		}
		std::vector<Student*>::iterator iter;
		for(iter = vec.begin(); iter != vec.end(); iter++)
		{
			if (a <=(*iter)->fascination && (*iter)->fascination <=b)
				cout << (*iter)->name << "  " << (*iter)->fascination << endl;
		}
	}// end of    if(2 == n)
}
void query_charm(Dorm& d,std::vector<Student*>& vec, std::vector<Student*>& g_vec, std::vector<Student*>& b_vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp3);
	sort(g_vec.begin(),g_vec.end(),cmp3);
	sort(b_vec.begin(),b_vec.end(),cmp3);

	while (1)
	{
		std::string a = "����";
		q_input(a);
		cin >> n;

		if (4 == n)
		{
			system("cls");
			break;
		}
		if (1 == n)
		{
			qf_output(vec);
		}
		else if (2 == n)
			qf_output(b_vec);
		else if (3 == n)
			qf_output(g_vec);
		else
			cout << "ݔ��ָ���e�`��" << endl;
	}
}

/////////////////////////////Ů����ò������������ԃ///////////////////////////////////////////
bool cmp4(Student *a, Student *b)
{
	if (a->cost == b->cost)
		return a->name < b->name;
	else
		return a->person_value() < b->person_value();
}
void query_person(std::vector<Student*>& vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp4);
	while (1)
	{
		//��Ϊ��ò�ͽ�����ӦŮ��������������Ҫ��Χѡ��ֱ�������ֵ���Ұ���Χ��ѯ
		cout << "��Сֵ��  " << vec[0]->name << "  " <<vec[0]->person_value() << endl;
		cout << "���ֵ��  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->person_value() << endl;
		cout << endl << "1.�Y��ݔ��;  2.��ֵ������ԃ           Ոݔ�룺";
		cin >> n;

		if (2 == n)
		{
			cout << endl << "Ոݔ�빠����";
			int a,b;
			cin >> a >> b;
			cout << endl;

			if (a > b)
			{
				n = a; a = b; b= n;
			}
			std::vector<Student*>::iterator iter;
			for(iter = vec.begin(); iter != vec.end(); iter++)
			{
				if (a <=(*iter)->person_value() && (*iter)->person_value() <=b)
					cout << (*iter)->name << "  " << (*iter)->person_value() << endl;
			}
		}
		else if (1 == n)
			break;
		else
			cout << "ݔ��ָ���e�`��" << endl;
	}
}

// ��ѯd�е�ѧ����Ϣ
void query_student(Dorm& d)
{
	while(1)
	{
		cout << "Ոݔ��W������:" << endl;
		std::string str;
		cin >> str;

		std::map<std::string,Student*>::iterator i,iter;
		if ((i = d.students.find(str)) == d.students.end())  // ���������ѧ�����������
		{
			cout << "�������@���W����Ո����ݔ��!" << endl;
			continue;
		}
		else
		{
			while (1)
			{
				int n;
				//  ���������ҵ����ѧ��������ʵ�ֶ�����ѧ����������Ĳ�ѯ
				cout << "1.��ԃ��(��)�Į�ǰ������Ϣ\n2.��ԃ��(��)�đِ�ʷ\
						\n3.��ԃ��(��)�ľ��w��Ϣ\n4.����\n\nՈݔ�룺";
				cin >> n;

				if (1 == n)
				{
					if (i->second->lover.size() == 0)  // ��ǰ����Ϊ��
					{
						cout << "�ª���į��" << endl;
					}
					else
					{
						//  �����ѧ�����˾�����Ϣ
						for(int j=0; j<i->second->lover.size(); j++)
						{
							iter = d.students.find(i->second->lover[j]);
							cout << iter->second->name << endl;
							cout << "�Ԅe��";
							if (iter->second->sex)
								cout << "Ů" << endl;
							else
								cout << "��" << endl;
							printf("��̖��%02d - %02d\n",iter->second->floor_number+1,iter->second->room_number+1);
							cout << endl;
						}
					}
				}
				else if (2 == n)
				{
					if (i->second->past_lover.size() == 0)  // ����ʷΪ��
						cout << "��(��)����һ�β�����֪���^ȥ" << endl;
					else
					{
						// �������ʷ
						cout << "��(��)���^ȥ��" << endl;
						for(int j=0; j<i->second->past_lover.size(); j++)
							cout << i->second->past_lover[j] << endl;
					}
				}
				else if (3 == n)
				{
					// �����ѧ��������Ϣ
					cout << "�Ԅe��";
					if (i->second->sex)
						cout << "Ů" << endl;
					else
						cout << "��" << endl;
					printf("��̖��%02d - %02d\n",i->second->floor_number+1,i->second->room_number+1);
					cout << endl;
				}
				else if (4 == n)
				{
					system("cls");
					break;
				}
				else
				{
					cout << "ݔ��ָ���e�`��" << endl;
				}
			}
		}
		break;
	}
}

//  ��ѯd�з������Ϣ
void query_room(Dorm& d)
{
	int fl,rm;
	std::string str;
	std::vector<std::string> strs;
	cout << "Ոݔ�뷿�g̖��" << endl;
	while (getline(cin,str))
		if (str.size() != 0)
			break;

	strs = split(str);
	sscanf(strs[0].c_str(), "%d", &fl);
	sscanf(strs[2].c_str(), "%d", &rm);
	fl--;
	rm--;

	if (!d.exists(fl,rm))
	{
		cout << "�������@�����g" << endl;
	}
	else
	{
		std::vector<std::string> vec = d[fl][rm].member;
		if (vec.size() == 0)
			cout << "����һ��շ���" << endl;

		sort(vec.begin(),vec.end());
		for(int i=0; i<vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}
}

#endif