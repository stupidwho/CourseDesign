#include <vector>
#include <string>

#include "Student.h"

typedef struct
{
	std::vector<std::string> member;    //���������Ա
	int number;     //����
	bool sex;         //������Ա�Ա�
} ROOM_NUM;

typedef std::vector<ROOM_NUM> FLOOR_NUM;  //ÿ������������vector��¼

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
	std::vector<FLOOR_NUM> floors;  //ÿ��¥��������vector��¼
private:

};

Dorm::Dorm()
{
}