/*

����

ʹ�� fstream ���ļ��ж�ȡ�ַ�

<fstream>
read()
path  "D:\W_workPlace\bxg_cpp\day10\day10_io\test_file.txt"

*/


#include <iostream>
#include <fstream>



int main() {

	std::cout << "..in day10_io_basic_fread...\n";

	// ����һ���ļ���ȡ������
	std::string test_file_path = "D:\\W_workPlace\\bxg_cpp\\day10\\day10_io\\test_file.txt";
	
	std::fstream fs(test_file_path, std::ios::in);
	if (fs.is_open()) {
		char* c = new char;
		fs.read(c, 1);
		std::cout << *c << "\n";	// a
		//std::cout << *(c+1) << "\n";	// û�����
		//std::cout << *(c+2) << "\n";	// û�����
	}
	else {
		std::cout << "..�ļ�û�д�...\n";
	}



	return 0;
}


/*

output

a

*/