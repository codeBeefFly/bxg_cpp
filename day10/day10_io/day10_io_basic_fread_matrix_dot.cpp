/*

����

�� �� �ո� �� ���� �ָ�ľ�����ж�ȡ

*/



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>





int main() {

	std::cout << "..in day10_io_basic_fread_matrix_dot...\n";

	// ��������ʼ���ļ���
	std::string relative_path = "..\\day10_io\\test_file_matrix.txt";

	std::fstream fs(relative_path, std::ios::in);
	std::vector<std::vector<double>> matrix;


	// �ж��Ƿ��
	if (fs.is_open()) {
		std::cout << "..�ļ���...\n";

		// ���� ������
		std::vector<double> row_vector;

		// ѭ����ȡ
		std::string line;
		while (std::getline(fs, line)) {
			std::cout << "..line = " << line << "\n";
			
			// �� line װ�� stringstream
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
		std::cout << "..�ļ�δ��...\n";
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