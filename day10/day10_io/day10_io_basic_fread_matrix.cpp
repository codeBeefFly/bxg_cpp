/*

����

�ļ�����ȡ��������

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>




int main() {

	std::cout << "..in day10_io_basic_fread_matrix...\n";

	// ��������ʼ���ļ���
	std::fstream fs("..\\day10_io\\test_file_matrix_space.txt");

	// ����һ������
	std::vector<std::vector<double>> matrix;	// ������Ŷ�ά����
	
	// �ж��ļ��Ƿ����
	if (fs.is_open()) {


		std::string line;
		while (std::getline(fs, line)) {

			std::cout << "..line::\t" << line << "\n";
		
			// ����һ��������
			std::vector<double> row_vector;

			// ����ȡ�� line ���� stringstream ���󱣹�
			std::stringstream ss(line);				// ��Ҫ���� <sstream>

			// �ո��и�ÿһ������
			double data = 0;
			while (ss >> data) {					// ��ÿһ�� ss ���տո�����иÿ�и�һ�η��� data
				row_vector.push_back(data);
			}

			matrix.push_back(row_vector);
		}

	}


	// ��ӡ
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