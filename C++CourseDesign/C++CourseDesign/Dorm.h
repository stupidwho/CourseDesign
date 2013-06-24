#include <boost/shared_ptr.hpp>
#include <vector>

#include "Student.h"

using std::vector;

typedef struct
{
	vector<boost::shared_ptr <Student> > member;    //已有宿舍成员
	int number;     //容量
	bool sex;         //宿舍人员性别
} ROOM;

typedef vector<ROOM> FLOOR;

class Dorm
{
public:
	Dorm();
protected:
	vector<FLOOR> floors;
private:

};

Dorm::Dorm()
{
}