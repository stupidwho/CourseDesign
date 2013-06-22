#include <string>
#include <vector>

using std::string;
using std::vector;

class Student
{
public:
	Student();
	~Student();

protected:
	string	name;
	string	sex;
	string	room_number;
	int	fascination;
	int	weight;
	int	cost;
	vector<string> lover;
	vector<string> past_lover;
private:

};

Student::Student()
{
}

Student::~Student()
{
}