#ifndef QUERY_FUNCTIONS
#define QUERY_FUNCTIONS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Dorm.h"

using std::cin;
using std::cout;
using std::endl;

int main_interface();
void query_weight(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);
void query_money(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);
void query_charm(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);
void query_person(std::vector<Student*>&);
void query_student(Dorm&);
void query_room(Dorm&);

void query(Dorm& d)
{
	int n;
	while (1)
	{
		n = main_interface();
		std::vector<Student*> vec,g_vec,b_vec;
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

int main_interface()
{
	cout << endl << "                 ***欢迎查询山的那边，湖的那边学校学生信息***" << endl << endl;
	cout << "             ****************************************************" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             *         請輸入查詢內容序號，按ENTER確認:         *" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             *         1.體重          2.金錢                   *" << endl;
	cout << "             *         3.魅力值        4.容貌值                 *" << endl;
	cout << "             *         5.健康值        6.學生信息               *" << endl;
	cout << "             *         7.房間信息      8.清屏                   *" << endl;
	cout << "             *         9.結束查詢                               *" << endl;
	cout << "             *                                                  *" << endl;
	cout << "             ****************************************************" << endl;
	cout << "請輸入序號：";
	int n;
	cin >> n;
	return n;
}

void q_input(std::string& s)
{
	cout << endl << "請輸入查詢" << s << "的範圍：" << endl;
	cout << "1.全體學生    2.男生     3.女生    4.返回上一界面" << endl;
	cout << endl << "請輸入序號，按ENTER確認：";
}

////////////////////////////體重查詢//////////////////////////////////////////////////
bool cmp1(Student *a, Student *b)
{
	if (a->weight == b->weight)
		return a->name < b->name;
	else
		return a->weight < b->weight;
}

void qw_output(std::vector<Student*>& vec)
{
	int n;
	cout << "最小值：  " << vec[0]->name << "  " <<vec[0]->weight << endl;
	cout << "最大值：  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->weight << endl;
	cout << endl << "結束請輸入1，按值範圍查詢請輸入2：";
	cin >> n;
	if (2 == n)
	{
		cout << endl << "請輸入範圍：";
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

void query_weight(Dorm& d,std::vector<Student*>& vec, std::vector<Student*>& g_vec, std::vector<Student*>& b_vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp1);
	sort(g_vec.begin(),g_vec.end(),cmp1);
	sort(b_vec.begin(),b_vec.end(),cmp1);
	while (1)
	{
		std::string a = "體重";
		q_input(a);
		cin >> n;
		if (4 == n)
		{
			system("cls");
			break;
		}
		if (1 == n)
		{
			qw_output(vec);
		}
		else if (2 == n)
			qw_output(b_vec);
		else if (3 == n)
			qw_output(g_vec);
		else
			cout << "輸入指令錯誤！" << endl;
	}
}

////////////////////////////金錢查詢////////////////////////////////////////////////////
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
	cout << "最小值：  " << vec[0]->name << "  " <<vec[0]->cost << endl;
	cout << "最大值：  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->cost << endl;
	cout << endl << "結束請輸入1，按值範圍查詢請輸入2：";
	cin >> n;
	if (2 == n)
	{
		cout << endl << "請輸入範圍：";
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
		std::string a = "金錢";
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
			cout << "輸入指令錯誤！" << endl;
	}
}

////////////////////////////魅力值查詢//////////////////////////////////////////////////
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
	cout << "最小值：  " << vec[0]->name << "  " <<vec[0]->fascination << endl;
	cout << "最大值：  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->fascination << endl;
	cout << endl << "1.結束輸入;  2.按值範圍查詢           請輸入：";
	cin >> n;
	if (2 == n)
	{
		cout << endl << "請輸入範圍：";
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
		std::string a = "魅力";
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
			cout << "輸入指令錯誤！" << endl;
	}
}

/////////////////////////////女生容貌、男生健康查詢///////////////////////////////////////////
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
		cout << "最小值：  " << vec[0]->name << "  " <<vec[0]->person_value() << endl;
		cout << "最大值：  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->person_value() << endl;
		cout << endl << "1.結束輸入;  2.按值範圍查詢           請輸入：";
		cin >> n;
		if (2 == n)
		{
			cout << endl << "請輸入範圍：";
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
			cout << "輸入指令錯誤！" << endl;
	}
}

void query_student(Dorm& d)
{
	while(1)
	{
		cout << "請輸入學生姓名:" << endl;
		std::string str;
		cin >> str;
		std::map<std::string,Student*>::iterator i,iter;
		if ((i = d.students.find(str)) == d.students.end())
		{
			cout << "不存在這個學生，請重新輸入!" << endl;
			continue;
		}
		else
		{
			while (1)
			{
				int n;
				cout << "1.查詢他(她)的當前戀人信息\n2.查詢她(他)的戀愛史\
						\n3.查詢她(他)的具體信息\n4.返回\n\n請輸入：";
				cin >> n;
				if (1 == n)
				{
					if (i->second->lover.size() == 0)
					{
						cout << "孤獨寂寞冷" << endl;
					}
					else
					{
						for(int j=0; j<i->second->lover.size(); j++)
						{
							iter = d.students.find(i->second->lover[j]);
							cout << iter->second->name << endl;
							cout << "性別：";
							if (iter->second->sex)
								cout << "女" << endl;
							else
								cout << "男" << endl;
							printf("房號：%02d - %02d\n",iter->second->floor_number+1,iter->second->room_number+1);
							cout << endl;
						}
					}
				}
				else if (2 == n)
				{
					if (i->second->past_lover.size() == 0)
						cout << "她(他)有着一段不爲人知的過去" << endl;
					else
					{
						cout << "他(她)的過去：" << endl;
						for(int j=0; j<i->second->past_lover.size(); j++)
							cout << i->second->past_lover[j] << endl;
					}
				}
				else if (3 == n)
				{
					cout << "性別：";
					if (i->second->sex)
						cout << "女" << endl;
					else
						cout << "男" << endl;
					printf("房號：%02d - %02d\n",i->second->floor_number+1,i->second->room_number+1);
					cout << endl;
				}
				else if (4 == n)
				{
					system("cls");
					break;
				}
				else
				{
					cout << "輸入指令錯誤！" << endl;
				}
			}
		}
		break;
	}
}
void query_room(Dorm& d)
{
	int fl,rm;
	std::string str;
	std::vector<std::string> strs;
	cout << "請輸入房間號：" << endl;
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
		cout << "不存在這個房間" << endl;
	}
	else
	{
		std::vector<std::string> vec = d[fl][rm].member;
		if (vec.size() == 0)
			cout << "这是一间空房间" << endl;
		sort(vec.begin(),vec.end());
		for(int i=0; i<vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}
}

#endif