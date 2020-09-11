/*

需求：

文件高效读取，读取一行

使用 while 循环读取 

getLine(fs, line)

*/




#include <iostream>
#include <fstream>
#include <string>


int main() {

	std::cout << "..in day10_io_basic_fread_line...\n";

	std::string relative_path = "..\\day10_io\\test_file.txt";
	
	//创建一个文件流
	std::fstream fs(relative_path, std::ios::in);
	if (fs.is_open()) {
		std::cout << "..文件存在...\n";

		std::string line;
		while (std::getline(fs, line)) {	// <string>，循环读取文件的行
			std::cout << line << "\n";
		}
	}
	else {
		std::cout << "..文件不存在...\n";
	}

	fs.close();

	return 0;
}


/*

output:

..in day10_io_basic_fread_line...
..文件存在...
abc123
我是中国人
我喜欢漂亮的妹子

*/