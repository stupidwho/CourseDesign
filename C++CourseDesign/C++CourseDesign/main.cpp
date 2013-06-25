#include <iostream>
#include <fstream>

#include "Initial.h"

using namespace std;

int main(int args, char *argv[])
{
	ifstream f1(argv[1]);
	initv(f1);
	f1.close();
	return 0;
}