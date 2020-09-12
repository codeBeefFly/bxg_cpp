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

	std::cout << "..in day10_io_basic_fread_matrix_dot_2...\n";

	// ��������ʼ���ļ���
	std::string relative_path = "..\\day10_io\\test_file_matrix_2.txt";
	std::fstream fs(relative_path, std::ios::in);

	std::vector<std::vector<double>> matrix;

	// �ļ��򿪲���
	if (fs.is_open()) {
		std::cout << "..�ļ���...\n";

		std::string line;						
		std::vector<double> line_vector;
		double data_d;
		//std::stringstream ss;		// û�����������
		while (std::getline(fs, line)) {
			std::cout << line << "\n";
			std::stringstream ss(line);
			while (ss >> data_d) {
				if (ss.peek() == ',' || ss.peek() == ' ') {
					ss.ignore();
				}
				std::cout << data_d << "\t";
				line_vector.push_back(data_d);
			}
			matrix.push_back(line_vector);
		}
	}
	else {
		std::cout << "..�ļ�δ��...\n";
	}

	fs.close();

	// ��ȡ����
	for (std::vector<double> row_vector : matrix) {
		for (double data : row_vector) {
			std::cout << data << "\t";
		}
		std::cout << "\n";
	}

	return 0;
}

/*

output

..in day10_io_basic_fread_matrix_dot_2...
..�ļ���...
1, 3
1       3       4, 7.5
4       7.5     1       3
1       3       4       7.5

*/