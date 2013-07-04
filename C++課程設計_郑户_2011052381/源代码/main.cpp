#include <fstream>
#include <iostream>

#include "Initial.h"
#include "read.h"
#include "query.h"

int main(int args, char *argv[])
{
	std::cout << "初始化過程：" << std::endl;
	std::ifstream f(argv[1]);  // argv[1]包含第1个文件名
	initv(f);  //从文件中读取初始配置信息
	f.close();

	f.open(argv[2]);  // argv[2]包含第2个文件名
	Dorm dormitory;
	inits(f,dormitory);  //  从文件中读取数据并实现宿舍初始化
	f.close();

	std::cout << std::endl;
	std::cout << "輸入指令過程：" << std::endl;
	f.open(argv[3]);  // argv[3]包含第3个文件名
	read_command(f, dormitory);  // 从文件中读取指令并且实现
	f.close();

	std::cout << "讀入完成，開始查詢：" << std::endl;
	query(dormitory);  // 查询
	
	return 0;
}
