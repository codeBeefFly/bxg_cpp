/*

需求：

单行string ss 的行读取

*/



#include <iostream>
#include <sstream>
#include <vector>




int main() {

	std::cout << "..in day_10_io_basic_fread_matrix_dot_simple...\n";

	std::string sv = "1, 2, 4.5, 7";
	std::vector<double> vd = { 1, 2, 4.5, 7 };


	{
		std::stringstream ss(sv);

		std::string data_s;
		while (ss >> data_s) {
			std::cout << data_s << "\n";
		}
	}

	std::cout << "\n*******************************\n";

	{
		std::stringstream ss(sv);

		double data_d;
		while (ss >> data_d) {
			std::cout << data_d << "\n";
		}

	}

	std::cout << "\n*******************************\n";

	//{
	//	// 这里是错误的
	//	std::stringstream ss(vd);	//	构造器是 basic_stream 类

	//	double data_d;
	//	while (ss >> data_d) {
	//		std::cout << data_d << "\n";
	//	}

	//}

	{
		std::stringstream ss(sv);

		double data_d;
		while (ss >> data_d) {
			if (ss.peek() == ',' || ss.peek() == ' ') {
				ss.ignore();
			}
			std::cout << data_d << "\t";
		}
	}


	return 0;
}