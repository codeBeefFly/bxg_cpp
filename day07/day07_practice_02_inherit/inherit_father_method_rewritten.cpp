/*

����

��д����ͬ������

������̳и���֮�󣬿��ԶѸ��ຯ����ǿ��չ��

���������ඨ���븸����ͬ�ĺ��������������������ʹ�� ����::���ຯ��()��������
����ĺ���

����һ��ϴ�»������� wash

����һ������ϴ�»������� wash

*/


#include <iostream>


class Wash_Machine {
public:
	void wash() {
		std::cout << "..ϴ�»�ϴ�·�...\n";
	}
};


class Smart_Wash_Machine : Wash_Machine {
public:
	void wash() {
		
		std::cout << "..����ϴ�»��趨ϴ��ģʽ...\n";
		
		Wash_Machine::wash();	// ���ø���ĺ���
	}
};

int main() {

	std::cout << "..in inherit_father_method_rewritten\n";


	Smart_Wash_Machine swm;
	swm.wash();

	return 0;
}



/*

..in inherit_father_method_rewritten
..����ϴ�»��趨ϴ��ģʽ...
..ϴ�»�ϴ�·�...

*/