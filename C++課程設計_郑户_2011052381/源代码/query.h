#ifndef QUERY_FUNCTIONS
#define QUERY_FUNCTIONS

/*
*该文件包含各种查询函数，实现查询功能
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Dorm.h"

using std::cin;
using std::cout;
using std::endl;

//  显示主界面
int main_interface();

//查询体重
void query_weight(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//查询金钱
void query_money(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//查询魅力值
void query_charm(Dorm&, std::vector<Student*>&, std::vector<Student*>&, std::vector<Student*>&);

//查询学生属性值
void query_person(std::vector<Student*>&);

//查询学生信息
void query_student(Dorm&);

//查询房间信息
void query_room(Dorm&);

//进行查询调用
void query(Dorm& d)
{
	int n;
	while (1)
	{
		n = main_interface();
		std::vector<Student*> vec,g_vec,b_vec;  // 分别用vector记录所有学生、男生、女生

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
		
		//根据选择调用对应函数
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

//  显示主界面并且输入选择，返回选项的序号
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

//  体重、金钱、魅力值显示时选项几乎相同，因此用一函数实现然后重用
void q_input(std::string& s)
{
	cout << endl << "請輸入查詢" << s << "的範圍：" << endl;
	cout << "1.全體學生    2.男生     3.女生    4.返回上一界面" << endl;
	cout << endl << "請輸入序號，按ENTER確認：";
}

/////////////下面的体重、金钱、魅力值查询均为类似方法，只在细节处不同//////////////////

////////////////////////////////體重查詢//////////////////////////////////////////////////
bool cmp1(Student *a, Student *b)
{
	if (a->weight == b->weight)
		return a->name < b->name;
	else
		return a->weight < b->weight;
}

//根据输出学生的体重的最值，以及根据输入输出值属于特定范围的人名
void qw_output(std::vector<Student*>& vec)
{
	int n;
	// 输出最值
	cout << "最小值：  " << vec[0]->name << "  " <<vec[0]->weight << endl;
	cout << "最大值：  " << vec[vec.size()-1]->name << "  " <<vec[vec.size()-1]->weight << endl;
	cout << endl << "結束請輸入1，按值範圍查詢請輸入2：";
	cin >> n;

	if (2 == n)
	{
		// 根据输入输出该范围的值和对应学生
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

//通过选择的范围，即全体学生、男生或者女生选择输出
void query_weight(Dorm& d,std::vector<Student*>& vec, std::vector<Student*>& g_vec, std::vector<Student*>& b_vec)
{
	int n;
	sort(vec.begin(),vec.end(),cmp1);
	sort(g_vec.begin(),g_vec.end(),cmp1);
	sort(b_vec.begin(),b_vec.end(),cmp1);

	while (1)
	{
		std::string a = "體重";
		q_input(a);  // 调用输出选项
		cin >> n;
		if (4 == n)
		{
			system("cls");
			break;
		}
		if (1 == n)
		{
			qw_output(vec);  // 若范围是全体学生则输入vec
		}
		else if (2 == n)
			qw_output(b_vec);  // 若范围是全体男生则输入b_vec
		else if (3 == n)
			qw_output(g_vec);  // 若范围是全体女生则输入g_vec
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
		//因为容貌和健康对应女生和男生，不需要范围选择，直接输出最值并且按范围查询
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

// 查询d中的学生信息
void query_student(Dorm& d)
{
	while(1)
	{
		cout << "請輸入學生姓名:" << endl;
		std::string str;
		cin >> str;

		std::map<std::string,Student*>::iterator i,iter;
		if ((i = d.students.find(str)) == d.students.end())  // 不存在这个学生则继续输入
		{
			cout << "不存在這個學生，請重新輸入!" << endl;
			continue;
		}
		else
		{
			while (1)
			{
				int n;
				//  根据姓名找到这个学生，并且实现对这名学生各种情况的查询
				cout << "1.查詢他(她)的當前戀人信息\n2.查詢她(他)的戀愛史\
						\n3.查詢她(他)的具體信息\n4.返回\n\n請輸入：";
				cin >> n;

				if (1 == n)
				{
					if (i->second->lover.size() == 0)  // 当前恋人为空
					{
						cout << "孤獨寂寞冷" << endl;
					}
					else
					{
						//  输出该学生恋人具体信息
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
					if (i->second->past_lover.size() == 0)  // 恋爱史为空
						cout << "她(他)有着一段不爲人知的過去" << endl;
					else
					{
						// 输出恋爱史
						cout << "他(她)的過去：" << endl;
						for(int j=0; j<i->second->past_lover.size(); j++)
							cout << i->second->past_lover[j] << endl;
					}
				}
				else if (3 == n)
				{
					// 输出该学生具体信息
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

//  查询d中房间的信息
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