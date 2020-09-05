/*

需求：


动物都有觅食的行为，但是每种动物吃的食物都不太一样。
请使用面向对象的思想，配合虚函数来设计动物觅食的行为。

*/



#include <iostream>

class Animal {
public:

	Animal() {
		std::cout << "..animal 构造...\n";
	}
	virtual ~Animal() {
		std::cout << "..animal 析构...\n";
	}

	virtual void eat() {
		std::cout << "..animal eat food...\n";
	}
};


class Tiger : public Animal{
public:

	Tiger() {
		std::cout << "..Tiger 构造...\n";
	}
	virtual ~Tiger() {
		std::cout << "..Tiger 析构...\n";
	}


	void eat() {
		std::cout << "..tiger eat meat...\n";
	}
};


class Deer : public Animal {
public:

	Deer() {
		std::cout << "..Deer 构造...\n";
	}
	virtual ~Deer() {
		std::cout << "..Deer 析构...\n";
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
..animal 构造...
..Tiger 构造...
..tiger eat meat...
..animal 构造...
..Deer 构造...
..deer eat flower...
..Tiger 析构...
..animal 析构...
..Deer 析构...
..animal 析构...

*/