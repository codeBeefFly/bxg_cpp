/*

需求；
简单的文件写入

*/


#include <iostream>
#include <fstream>


int main() {

	std::cout << "..in basic fwrite simple...\n";
	
	std::fstream fs("..\\day10_io\\fwrite.txt", std::ios::app);	// 追加
	
	if (fs.is_open()) {

		std::cout << "..文件打开成功...\n";

		fs << "hello there\n";	// 字符串输入到 fs
	
	}
	std::cout << "写入完成";

	return 0;
}


/*

output:

..in basic fwrite simple...
写入完成

*/