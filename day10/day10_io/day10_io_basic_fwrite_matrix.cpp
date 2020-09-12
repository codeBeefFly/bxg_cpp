/*

����

��ȡ��ά�����е�Ԫ�أ���д���ļ�
ע���ʽ��ÿһ�е�ÿ����Ԫ�ؼ��� , ������ÿһ��ĩβû�з���
�����еĳ��� ʹ�� vector�е� size() ����

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
	
	
	// �����ļ������󲢳�ʼ��
	std::fstream fs("..\\day10_io\\fwrite_matrix.txt", std::ios::app);

	// ѭ����ȡ����
	if (fs.is_open()) {
		std::cout << "..�ļ��򿪳ɹ�...\n";

		for (std::vector<double> data_1d : data_2d) {
			for (double data : data_1d) {
				if (data == data_1d.at(data_1d.size()-1)) {	// ʹ�� data �Ƿ���� ���һ��Ԫ�����ж�
					fs << data << "\n";
				}
				else {
					fs << data << ",";
				}
			}
		}
		
		std::cout << "..д�����...\n";
	}
	else {
		std::cout << "..�ļ���ʧ��...\n";
	}


	fs.close();


	return 0;
}