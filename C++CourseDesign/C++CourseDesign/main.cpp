#include <fstream>

#include "Dorm.h"
#include "Initial.h"
#include "read.h"

int main(int args, char *argv[])
{
	std::ifstream f(argv[1]);
	initv(f);
	f.close();
	f.open(argv[2]);
	Dorm dormitory;
	inits(f,dormitory);
	f.close();
	f.open(argv[3]);
	read_command(f, dormitory);
	f.close();
	return 0;
}