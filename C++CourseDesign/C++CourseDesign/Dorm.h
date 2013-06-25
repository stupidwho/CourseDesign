#include <vector>
#include <string>

#include "Student.h"

typedef struct
{
	std::vector<std::string> member;    //已有宿舍成员
	int number;     //容量
	bool sex;         //宿舍人员性别
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //每层所含房间用vector记录

class Dorm
{
public:
	Dorm();
	bool move(string, int, int, int, int);
	bool quit(string, int, int);
	bool enrol(string, bool, int, int);
	bool add(int);
	bool add(int, int);
	bool add(int, int, int);
protected:
	std::vector<FLOOR_NUM> floors;  //每座楼所含层用vector记录
private:

};

Dorm::Dorm()
{
}