#ifndef READ_command
#define READ_command

/*
*实现从文件读取指令，并且转换为int型指令，然后进行函数调用
*/

#include <iostream>
#include <vector>
#include <string>

#include "Dorm.h"
#include "love.h"

#define CMD_MOVE 1
#define CMD_QUIT 2
#define CMD_ENROL 3
#define CMD_ADD_FLOORS 4
#define CMD_ADD_ROOMS 5
#define CMD_ADD_BEDS 6
#define CMD_COURT 7
#define CMD_BREAKUP 8
#define CMD_MULTI 9
#define CMD_EAT 10
#define CMD_STUDY 11
#define CMD_MAKEUP 12
#define CMD_EXERCISE 13
#define WRONG_CMD -1

int check_command(std::string);  //将string型指令转化为int型

// 从输入流is读取活动指令并且d进行实现
void read_command(std::istream& is, Dorm& d)
{
	std::string str,n;
	std::vector<std::string> strs;
	while (getline(is,str))
	{
		if (str.size() == 0)
			continue;
		strs = split(str);
		switch(check_command(str))
		{
		case CMD_MOVE:
			{
				n = strs[0];
				int ff;
				sscanf(strs[3].c_str(),"%d",&ff);
				int fr;
				sscanf(strs[5].c_str(),"%d",&fr);
				int tf;
				sscanf(strs[7].c_str(),"%d",&tf);
				int tr;
				sscanf(strs[9].c_str(),"%d",&tr);
				ff--,fr--,tf--,tr--;

				if (!d.move(n, ff, fr, tf, tr))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_QUIT: 
			{
				if (!d.quit(strs[0]))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_ENROL: 
			{
				int fl;
				int rm;
				bool s = (strcmp(strs[1].c_str(),"女") == 0);
				sscanf(strs[3].c_str(),"%d",&fl);
				sscanf(strs[5].c_str(),"%d",&rm);
				fl--,rm--;

				if (!d.enrol(strs[0], s, fl, rm))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_ADD_FLOORS: 
			{
				int fls;
				sscanf(strs[1].c_str(),"%d",&fls);

				if (!d.add(fls))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_ADD_ROOMS: 
			{
				int fl,rms;
				sscanf(strs[1].c_str(),"%d",&rms);
				sscanf(strs[4].c_str(),"%d",&fl);
				fl--;

				if (!d.add(fl, rms))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_ADD_BEDS: 
			{
				int fl,rm,beds;
				sscanf(strs[1].c_str(),"%d",&beds);
				sscanf(strs[4].c_str(),"%d",&fl);
				sscanf(strs[6].c_str(),"%d",&rm);
				fl--,rm--;

				if (!d.add(fl, rm, beds))
					std::cout << "无效指令内容:" << str << std::endl;
			}
			break;
		case CMD_COURT: 
			{
				court(d.students[strs[0]], d.students[strs[2]]);
			}
			break;
		case CMD_BREAKUP: 
			{
				breakup(d.students[strs[0]], d.students[strs[1]]);
			}
			break;
		case CMD_MULTI: 
			{
				std::string t;
				for(int i=1; i<strs.size(); i+=2)
				{
					t = "EAT";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						if (!d.students[strs[0]]->eat(e))
							std::cout << "无效指令内容:" << str << std::endl;
					}

					t = "STUDY";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						if (!d.students[strs[0]]->study(e))
							std::cout << "无效指令内容:" << str << std::endl;
					}

					t = "MAKEUP";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						if (!d.students[strs[0]]->ownact(e))
							std::cout << "无效指令内容:" << str << std::endl;
					}

					t = "EXERCISE";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						if (!d.students[strs[0]]->ownact(e))
							std::cout << "无效指令内容:" << str << std::endl;
					}
				}
			}
			break;
		case WRONG_CMD: 
			{
				std::cout << "指令格式错误:" << str << std::endl;
			}
			break;
		}
	}
}

// 判断str指令是否错误并且返回对应int型指令值
int check_command(std::string str)
{
	std::string t;
	std::vector<std::string> strs;
	strs = split(str);
	// 有ADD表示是增加楼层、房间或者床位
	t = "ADD";
	if (strs[0] == t)
	{
		if (strs.size() == 3)
			return CMD_ADD_FLOORS;
		else if (strs.size() == 6)
			return CMD_ADD_ROOMS;
		else if (strs.size() == 7)
			return CMD_ADD_BEDS;
		else
			return WRONG_CMD;
	}
	else
	{
		t = "MOVE";
		if (strs[1] == t)
			return CMD_MOVE;
		t = "QUIT";
		if (strs[1] == t)
			return CMD_QUIT;
			t = "COURT";
		if (strs[1] == t)
			return CMD_COURT;
		t = "ENTER";
		if (strs[2] == t)
			return CMD_ENROL;
		t = "BREAK";
		if (strs[2] == t)
			return CMD_BREAKUP;

		// 下面的活动可在同一行出现多次，因此需要用不同的方法解析
		t = "EAT";
		if (strs[1] == t)
			return CMD_MULTI;
		t = "STUDY";
		if (strs[1] == t)
			return CMD_MULTI;
		t = "MAKEUP";
		if (strs[1] == t)
			return CMD_MULTI;
		t = "EXERCISE";
		if (strs[1] == t)
			return CMD_MULTI;
		return WRONG_CMD;
	}
}

#endif