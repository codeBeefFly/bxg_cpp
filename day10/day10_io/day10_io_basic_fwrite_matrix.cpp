/*

需求：

读取二维数组中的元素，并写入文件
注意格式，每一行的每两个元素间用 , 隔开，每一行末尾没有符号
计算行的长度 使用 vector中的 size() 函数

*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


int main() {

	std::cout << "..in day10_io_basic_fwrite_matrix...\n";

	std::vector < std::vector<double>> data_2d {
		{1, 2, 3.5},
		{4, 5.5, 9},
		{8, 19, 9.5},
	};
	
	
	// 创建文件流对象并初始化
	std::fstream fs("..\\day10_io\\fwrite_matrix.txt", std::ios::out);

	// 循环读取向量
	if (fs.is_open()) {
		std::cout << "..文件打开成功...\n";

		for (std::vector<double> data_1d : data_2d) {
			for (double data : data_1d) {
				if (data == data_1d.at(data_1d.size()-1)) {	// 使用 data 是否等于 最后一个元素来判断
					fs << data << "\n";
				}
				else {
					fs << data << ",";
				}
			}
		}
		
		std::cout << "..写入完成...\n";
	}
	else {
		std::cout << "..文件打开失败...\n";
	}


	fs.close();


	// 读取
	std::vector<std::vector<double>> new_data_2d;
	std::vector<double> new_data_1d;
	std::string line;
	double new_data;

	std::fstream fs_r("..\\day10_io\\fwrite_matrix.txt", std::ios::in);

	if (fs_r.is_open()) {
		std::cout << "..文件打开成功...\n";

		while (std::getline(fs_r, line)) {
			std::cout << "line = " << line << "\n";
			std::stringstream ss(line);
			new_data_1d.clear();
			while(ss >> new_data) {
				std::cout << "new_data = " << new_data << "\n";
				if (ss.peek() == ',' || ss.peek() == ' ') {	// 仅读出，不取走
				//if (ss.peek() == ',') {
					//std::cout << ss.peek() << "\n";
					ss.ignore();
				}
				//else {
				//	//std::cout << ss.peek() << ", " << new_data << "\n";
				//	std::cout << "..new_data = " << new_data << "\n";
				//	new_data_1d.push_back(new_data);
				//}
				new_data_1d.push_back(new_data);
			}
			new_data_2d.push_back(new_data_1d);
		}
	}
	else {
		std::cout << "..文件打开失败...\n";
	}


	// 打印
	for (std::vector<double> data_1d : new_data_2d) {
		for (double data : data_1d) {
			std::cout << data << " ";
		}
		std::cout << "\n";
	}

	fs_r.close();

	return 0;
}



/*

output:

..in day10_io_basic_fwrite_matrix...
..文件打开成功...
..写入完成...
..文件打开成功...
line = 1,2,3.5
new_data = 1
new_data = 2
new_data = 3.5
line = 4,5.5,9
new_data = 4
new_data = 5.5
new_data = 9
line = 8,19,9.5
new_data = 8
new_data = 19
new_data = 9.5
1 2 3.5
4 5.5 9
8 19 9.5


*/