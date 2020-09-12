/*

需求，

对 用 空格 与 逗号 分割的矩阵进行读取

*/



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>





int main() {

	std::cout << "..in day10_io_basic_fread_matrix_dot...\n";

	// 创建并初始化文件流
	std::string relative_path = "..\\day10_io\\test_file_matrix.txt";

	std::fstream fs(relative_path, std::ios::in);
	std::vector<std::vector<double>> matrix;


	// 判断是否打开
	if (fs.is_open()) {
		std::cout << "..文件打开...\n";

		// 创建 行向量
		std::vector<double> row_vector;

		// 循环读取
		std::string line;
		while (std::getline(fs, line)) {
			std::cout << "..line = " << line << "\n";
			
			// 将 line 装入 stringstream
			std::stringstream ss(line);

			//std::string data = 0;
			double data = 0;

			while (ss >> data) {

				std::cout << "..data = " << data << "\n";

				if (ss.peek() == ',' || ss.peek() == ' ') {
					ss.ignore();
				}
				//else {
				//	row_vector.push_back((double)data);
				//}

				row_vector.push_back(data);

			}
			matrix.push_back(row_vector);
		}

	}
	else {
		std::cout << "..文件未打开...\n";
	}

	//fs.close();


	for (std::vector<double> row_vector : matrix) {
		for (double data : row_vector) {
			std::cout << data << "\t";
		}
		std::cout << "\n";
	}

	return 0;
}