/*

����


���ﶼ����ʳ����Ϊ������ÿ�ֶ���Ե�ʳ�ﶼ��̫һ����
��ʹ����������˼�룬����麯������ƶ�����ʳ����Ϊ��

*/



#include <iostream>

class Animal {
public:

	Animal() {
		std::cout << "..animal ����...\n";
	}
	virtual ~Animal() {
		std::cout << "..animal ����...\n";
	}

	virtual void eat() {
		std::cout << "..animal eat food...\n";
	}
};


class Tiger : public Animal{
public:

	Tiger() {
		std::cout << "..Tiger ����...\n";
	}
	virtual ~Tiger() {
		std::cout << "..Tiger ����...\n";
	}


	void eat() {
		std::cout << "..tiger eat meat...\n";
	}
};


class Deer : public Animal {
public:

	Deer() {
		std::cout << "..Deer ����...\n";
	}
	virtual ~Deer() {
		std::cout << "..Deer ����...\n";
	}


	void eat() {
		std::cout << "..deer eat flower...\n";
	}
};



int main() {

	std::cout << "..in virtual_function_practice_virtual_eat...\n";

	Animal* animal_1 = new Tiger();
	animal_1->eat();

	Animal* animal_2 = new Deer();
	animal_2->eat();


	delete animal_1;
	delete animal_2;
	
	return 0;
}


/*

output:


.in virtual_function_practice_virtual_eat...
..animal ����...
..Tiger ����...
..tiger eat meat...
..animal ����...
..Deer ����...
..deer eat flower...
..Tiger ����...
..animal ����...
..Deer ����...
..animal ����...

*/