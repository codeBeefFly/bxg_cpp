#include <iostream>
#include "stu.h"
//#include <WinBase.h>


int main(){
	
	std::cout << "...in main.cpp...\n";

	//HINSTANCE hDLL;
	//hDLL = LoadLibrary("mydll.dll");  //���� DLL�ļ�
	//if (hDLL == NULL)
	//	std::cout << "Error!!!\n";

	stu s("����");
	s.run();
	
	return 0;
	
}