/*
����
1. �������ַ��� A �� B �� A ΪԴ�ַ�����B ΪҪɾ�����ַ������ж�A
�Ƿ����B ��������������A �������B���ַ�ɾ�������ȫ�µ�
�ַ���A������ֱ�����Դ�ַ���A��
*/

#include <iostream>

int main() {
	std::cout << "..day02_homework_01_string..." << std::endl;

	std::string string_source{ "aabbccddeeeffgh" };
	std::string string_toDelete{ "eee" };
	std::string string_new{ "" };

	std::size_t found;

	// �ж� string_source ���Ƿ��� string_toDelete, find()
	// ʹ�� replace() erase() ɾ��Ŀ���ַ���
	found = string_source.find(string_toDelete);
	if (found == std::string::npos) {
		std::cout << "..not find string_toDelete in source...\n";
		string_new = string_source;
	}
	else {
		std::cout << "..find target at pos. :: " << found << "\n";
		string_source.erase(found, string_toDelete.length());
		string_new = string_source;
	}

	std::cout << "..new string is :: " << string_new << "\n";


	return 0;
}