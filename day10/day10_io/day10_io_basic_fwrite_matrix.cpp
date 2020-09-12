/*

需求：

读取二维数组中的元素，并写入文件
注意格式，每一行的每两个元素间用 , 隔开，每一行末尾没有符号
计算行的长度 使用 vector中的 size() 函数

*/


#include <iostream>
#include <fstream>
#include <vector>


int main() {

	std::cout << "..in day10_io_basic_fwrite_matrix...\n";

	std::vector < std::vector<double>> data_2d {
		{1, 2, 3.5},
		{4, 5.5, 9},
		{8, 19, 9.5},
	};
	
	
	// 创建文件流对象并初始化
	std::fstream fs("..\\day10_io\\fwrite_matrix.txt", std::ios::app);

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


	return 0;
}