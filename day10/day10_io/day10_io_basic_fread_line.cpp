/*

����

�ļ���Ч��ȡ����ȡһ��

ʹ�� while ѭ����ȡ 

getLine(fs, line)

*/




#include <iostream>
#include <fstream>
#include <string>


int main() {

	std::cout << "..in day10_io_basic_fread_line...\n";

	std::string relative_path = "..\\day10_io\\test_file.txt";
	
	//����һ���ļ���
	std::fstream fs(relative_path, std::ios::in);
	if (fs.is_open()) {
		std::cout << "..�ļ�����...\n";

		std::string line;
		while (std::getline(fs, line)) {	// <string>��ѭ����ȡ�ļ�����
			std::cout << line << "\n";
		}
	}
	else {
		std::cout << "..�ļ�������...\n";
	}

	fs.close();

	return 0;
}


/*

output:

..in day10_io_basic_fread_line...
..�ļ�����...
abc123
�����й���
��ϲ��Ư��������

*/