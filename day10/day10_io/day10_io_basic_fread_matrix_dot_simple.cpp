/*

����

����string ss ���ж�ȡ

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
	//	// �����Ǵ����
	//	std::stringstream ss(vd);	//	�������� basic_stream ��

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