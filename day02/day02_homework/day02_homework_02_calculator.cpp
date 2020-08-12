/*
����
2. ����һ�����������ṩ�Ӽ��˳�����
a.����һ��calc.h ��Ϊ�Ӽ��˳� �ĸ�����������
b.����һ��calc.cpp ��Ϊ�������ľ���ʵ��
c.����һ��main.cpp ��Ϊ��������
*/


#include <iostream>
#include "calc.h"

int main() {
	std::cout << "..day02_homework_02_calculator..." << std::endl;

	std::cout << "..operation:: \n"
		<< "..1: + \n" << "..2: - \n" << "..3: * \n" << "..4: / \n" << "..0: exit \n";
	
	int choice;
	while (true)
	{
		std::cout << "..enter your choice :: ";
		std::cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0) {
			std::cout << "..invalide choice...\n";
		}
		else if (choice == 0) {
			std::cout << "..choice 0 selected, exiting..\n";
			return 0;	// exit program
		}
		else {
			break;
		}

	}

	int oprand1{}, oprand2{};
	switch (choice)
	{
	case 1:
		std::cout << "..addition :: enter oprand1 oprand2 in order :: ";
		std::cin >> oprand1 >> oprand2;
		std::cout << ".." << oprand1 << " + " << oprand2 << " = " << op_add(oprand1, oprand2) << std::endl;
		break;
	case 2:
		std::cout << "..subtraction :: enter oprand1 oprand2 in order :: ";
		std::cin >> oprand1 >> oprand2;
		std::cout << ".." << oprand1 << " - " << oprand2 << " = " << op_sub(oprand1, oprand2) << std::endl;
		break;
	case 3:
		std::cout << "..multiplication :: enter oprand1 oprand2 in order :: ";
		std::cin >> oprand1 >> oprand2;
		std::cout << ".." << oprand1 << " * " << oprand2 << " = " << op_mul(oprand1, oprand2) << std::endl;
		break;
	case 4:
		std::cout << "..division :: enter oprand1 oprand2 in order :: ";
		std::cin >> oprand1 >> oprand2;
		std::cout << ".." << oprand1 << " / " << oprand2 << " = " << op_div(oprand1, oprand2) << std::endl;
		break;
	default:
		break;
	}

	return 0;
}