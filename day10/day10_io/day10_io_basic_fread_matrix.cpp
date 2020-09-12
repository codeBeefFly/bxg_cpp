/*

需求：

文件流读取矩阵数据

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>




int main() {

	std::cout << "..in day10_io_basic_fread_matrix...\n";

	// 创建并初始化文件流
	std::fstream fs("..\\day10_io\\test_file_matrix_space.txt");

	// 创建一个矩阵
	std::vector<std::vector<double>> matrix;	// 用来存放二维矩阵
	
	// 判断文件是否存在
	if (fs.is_open()) {


		std::string line;
		while (std::getline(fs, line)) {

			std::cout << "..line::\t" << line << "\n";
		
			// 创建一个行向量
			std::vector<double> row_vector;

			// 将读取的 line 交给 stringstream 对象保管
			std::stringstream ss(line);				// 需要导入 <sstream>

			// 空格切割每一行数字
			double data = 0;
			while (ss >> data) {					// 对每一个 ss 按照空格进行切割，每切割一次放入 data
				row_vector.push_back(data);
			}

			matrix.push_back(row_vector);
		}

	}


	// 打印
	for (std::vector<double> row_vector : matrix) {
		for (double element : row_vector) {
			std::cout << element << "\t";
		}
		std::cout << "\n";
	}



	fs.close();


	return 0;

}


/*

output:


..in day10_io_basic_fread_matrix...
..line::        1 6 2 10.5
..line::        11 15.2 2 21
..line::        3 9 1 7.5
1       6       2       10.5
11      15.2    2       21
3       9       1       7.5

*/