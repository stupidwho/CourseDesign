#include <fstream>
#include <iostream>

#include "Initial.h"
#include "read.h"
#include "query.h"

int main(int args, char *argv[])
{
	std::cout << "��ʼ���^�̣�" << std::endl;
	std::ifstream f(argv[1]);  // argv[1]������1���ļ���
	initv(f);  //���ļ��ж�ȡ��ʼ������Ϣ
	f.close();

	f.open(argv[2]);  // argv[2]������2���ļ���
	Dorm dormitory;
	inits(f,dormitory);  //  ���ļ��ж�ȡ���ݲ�ʵ�������ʼ��
	f.close();

	std::cout << std::endl;
	std::cout << "ݔ��ָ���^�̣�" << std::endl;
	f.open(argv[3]);  // argv[3]������3���ļ���
	read_command(f, dormitory);  // ���ļ��ж�ȡָ���ʵ��
	f.close();

	std::cout << "�x����ɣ��_ʼ��ԃ��" << std::endl;
	query(dormitory);  // ��ѯ
	
	return 0;
}
