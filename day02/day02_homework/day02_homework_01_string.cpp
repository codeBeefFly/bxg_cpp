/*
需求
1. 有两个字符串 A ， B ， A 为源字符串，B 为要删除的字符串，判断A
是否包含B ，如果包含，请把A 里面包含B的字符删除后，输出全新的
字符串A，否则直接输出源字符串A。
*/

#include <iostream>

int main() {
	std::cout << "..day02_homework_01_string..." << std::endl;

	std::string string_source{ "aabbccddeeeffgh" };
	std::string string_toDelete{ "eee" };
	std::string string_new{ "" };

	std::size_t found;

	// 判断 string_source 中是否有 string_toDelete, find()
	// 使用 replace() erase() 删除目标字符串
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