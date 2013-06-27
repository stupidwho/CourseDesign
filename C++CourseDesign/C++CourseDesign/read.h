#ifndef READ_command
#define READ_command

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

int check_command(std::string);

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
					std::cout << "指令内容错误" << std::endl;
			}
			break;
		case CMD_QUIT: 
			{
				if (!d.quit(strs[0]))
					std::cout << "指令内容错误" << std::endl;
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
					std::cout << "指令内容错误" << std::endl;
			}
			break;
		case CMD_ADD_FLOORS: 
			{
				int fls;
				sscanf(strs[1].c_str(),"%d",&fls);
				if (!d.add(fls))
					std::cout << "指令内容错误" << std::endl;
			}
			break;
		case CMD_ADD_ROOMS: 
			{
				int fl,rms;
				sscanf(strs[1].c_str(),"%d",&rms);
				sscanf(strs[4].c_str(),"%d",&fl);
				fl--;
				if (!d.add(fl, rms))
					std::cout << "指令内容错误" << std::endl;
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
					std::cout << "指令内容错误" << std::endl;
			}
			break;
		case CMD_COURT: 
			{
				if (court(d.students[strs[0]], d.students[strs[2]]))
					std::cout << "追求成功" << std::endl;
				else
					std::cout << "追求失败" << std::endl;
			}
			break;
		case CMD_BREAKUP: 
			{
				if (breakup(d.students[strs[0]], d.students[strs[1]]))
					std::cout << "分手成功" << std::endl;
				else
					std::cout << "分手失败" << std::endl;
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
						d.students[strs[0]]->eat(e);
					}
					t = "STUDY";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						d.students[strs[0]]->study(e);
					}
					t = "MAKEUP";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						d.students[strs[0]]->ownact(e);
					}
					t = "EXERCISE";
					if (strs[i] == t)
					{
						int e;
						sscanf(strs[i+1].c_str(), "%d", &e);
						d.students[strs[0]]->ownact(e);
					}
				}
			}
			break;
		case WRONG_CMD: 
			{
				std::cout << "指令格式错误" << std::endl;
			}
			break;
		}
	}
}

int check_command(std::string str)
{
	std::string t;
	std::vector<std::string> strs;
	strs = split(str);
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