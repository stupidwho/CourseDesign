#include <fstream>
#include <iostream>

#include "Initial.h"
#include "read.h"
#include "query.h"

int main(int args, char *argv[])
{
	std::cout << "��ʼ���^�̣�" << std::endl;
	std::ifstream f(argv[1]);
	initv(f);
	f.close();
	f.open(argv[2]);
	Dorm dormitory;
	inits(f,dormitory);
	f.close();
	std::cout << std::endl;
	std::cout << "ݔ��ָ���^�̣�" << std::endl;
	f.open(argv[3]);
	read_command(f, dormitory);
	f.close();
	std::cout << "�x����ɣ��_ʼ��ԃ��" << std::endl;
	query(dormitory);
	return 0;
}
