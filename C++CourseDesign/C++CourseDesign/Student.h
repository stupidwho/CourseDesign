#include <string>
#include <vector>

using std::string;
using std::vector;

class Student
{
public:
	Student();

protected:
	string	name;
	string	room_number;
	bool sex;
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