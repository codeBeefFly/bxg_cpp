#include <iostream>
#include "stu.h"
//#include <WinBase.h>


int main(){
	
	std::cout << "...in main.cpp...\n";

	//HINSTANCE hDLL;
	//hDLL = LoadLibrary("mydll.dll");  //加载 DLL文件
	//if (hDLL == NULL)
	//	std::cout << "Error!!!\n";

	stu s("张三");
	s.run();
	
	return 0;
	
}