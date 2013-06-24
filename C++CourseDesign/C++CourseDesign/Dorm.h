#include <boost/shared_ptr.hpp>
#include <vector>

#include "Student.h"

using std::vector;

typedef struct
{
	vector<boost::shared_ptr <Student> > member;    //���������Ա
	int number;     //����
	bool sex;         //������Ա�Ա�
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