#ifndef READ_command
#define READ_command

#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "split.h"
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
				if (!d.move(n, ff, fr, tf, tr))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
			}
			break;
		case CMD_QUIT: 
			{
				if (!d.quit(strs[0]))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
			}
			break;
		case CMD_ENROL: 
			{
				int fl;
				int rm;
				bool s = (strcmp(strs[1].c_str(),"Å®") == 0);
				sscanf(strs[3].c_str(),"%d",&fl);
				sscanf(strs[5].c_str(),"%d",&rm);
				if (!d.enrol(strs[0], s, fl, rm))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
			}
			break;
		case CMD_ADD_FLOORS: 
			{
				int fls;
				sscanf(strs[1].c_str(),"%d",&fls);
				if (!d.add(fls))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
			}
			break;
		case CMD_ADD_ROOMS: 
			{
				int fls,rms;
				sscanf(strs[1].c_str(),"%d",&fls);
				sscanf(strs[4].c_str(),"%d",&rms);
				if (!d.add(fls, rms))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
			}
			break;
		case CMD_ADD_BEDS: 
			{
				int fl,rm,beds;
				sscanf(strs[1].c_str(),"%d",&fl);
				sscanf(strs[4].c_str(),"%d",&rm);
				sscanf(strs[6].c_str(),"%d",&beds);
				if (!d.add(fl, rm, beds))
					std::cout << "Ö¸ÁîÄÚÈÝ´íÎó" << std::endl;
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
				std::cout << "Ö¸Áî¸ñÊ½´íÎó" << std::endl;
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