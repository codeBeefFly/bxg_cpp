/*

����
�򵥵��ļ�д��

*/


#include <iostream>
#include <fstream>


int main() {

	std::cout << "..in basic fwrite simple...\n";
	
	std::fstream fs("..\\day10_io\\fwrite.txt", std::ios::app);	// ׷��
	
	if (fs.is_open()) {

		std::cout << "..�ļ��򿪳ɹ�...\n";

		fs << "hello there\n";	// �ַ������뵽 fs
	
	}
	std::cout << "д�����";

	return 0;
}


/*

output:

..in basic fwrite simple...
д�����

*/