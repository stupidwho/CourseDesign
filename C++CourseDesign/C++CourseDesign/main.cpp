#include <fstream>

#include "Initial.h"
#include "Dorm.h"

int main(int args, char *argv[])
{
	std::ifstream f1(argv[1]);
	initv(f1);
	f1.close();
	f1.open(argv[2]);
	Dorm dormitory;
	inits(f1,dormitory);
	f1.close();
	return 0;
}