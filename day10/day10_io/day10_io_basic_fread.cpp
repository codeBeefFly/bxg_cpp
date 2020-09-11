/*

需求：

使用 fstream 从文件中读取字符

<fstream>
read()
path  "D:\W_workPlace\bxg_cpp\day10\day10_io\test_file.txt"

*/


#include <iostream>
#include <fstream>



int main() {

	std::cout << "..in day10_io_basic_fread...\n";

	// 创建一个文件读取流对象
	std::string test_file_path = "D:\\W_workPlace\\bxg_cpp\\day10\\day10_io\\test_file.txt";
	
	std::fstream fs(test_file_path, std::ios::in);
	if (fs.is_open()) {
		char* c = new char;
		fs.read(c, 1);
		std::cout << *c << "\n";	// a
		//std::cout << *(c+1) << "\n";	// 没有输出
		//std::cout << *(c+2) << "\n";	// 没有输出
	}
	else {
		std::cout << "..文件没有打开...\n";
	}



	return 0;
}


/*

output

a

*/