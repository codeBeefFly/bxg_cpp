/*

����

��ϰ���麯��


��һ�����麯��������ǳ�����

�����಻�ܴ���������Ϊ�����д��麯�������麯��û�к�����

�������п�����ͨ�ĳ�Ա����

���һ������̳��˳����࣬��ô������д���г����������д��麯��������ҲΪ������

���麯�������е������ⲿ�ֹ���

*/		   


#include <iostream>

class Virtual_Animal {		// ȫ�Ǵ��麯���ĳ�����
public:
	
	virtual void eat() = 0;
	virtual void run() = 0;
	virtual void sleep() = 0;
};


class Fish : public Virtual_Animal {
public:
	void eat() {
		std::cout << "..fish eat algae...\n";
	}

	void run() {
		std::cout << "..fish swim with fins...\n";
	}

	void sleep() {
		std::cout << "..fish sleep with eyes open...\n";
	}
};


class Cat : public Virtual_Animal {		// �������Ҫʵ�� base �麯�������г�Ա�������ܹ��������󡣲�Ȼ��Ȼ�Ǵ��麯��
public:
	void eat() {
		std::cout << "..Cat eats meat...\n";
	}

	void run() {
		std::cout << "..Cat run with four legs...\n";
	}

	//void sleep() {
	//	std::cout << "..Cat sleep curl up all the day...\n";
	//}
};



class X {		// ֻ��һ�����麯���ĳ�����
public :
	virtual void A() {
		std::cout << "....aaaa" << std::endl;
	}

	void B() {
		std::cout << "...bbbb" << std::endl;
	}
};


int main() {

	std::cout << "..in virtual_fuction_pure_virtual_function...\n";

	Virtual_Animal* va_1 = new Fish();
	va_1->eat();
	va_1->run();
	va_1->sleep();

	//Virtual_Animal* va_2 = new Cat();	// object of abstruct class type Cat is not allowed, pure virtual function virtual void sleep has no overrider.
	//va_2->eat();
	//va_2->run();
	//va_2->sleep();



	return 0;
}