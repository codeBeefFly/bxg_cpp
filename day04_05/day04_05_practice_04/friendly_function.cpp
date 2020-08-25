/*

友元函数

*/



#include <iostream>

class Car {

private:
	std::string color;

public:

	Car() {
		std::cout << "..log::无参构造函数...\n";
	}

	Car(std::string color) : color{ color } {
		std::cout << "..log::有参构造函数...\n";
	}

	friend void showColor(Car c);
};


void showColor(Car c) {
	std::cout << "..color of the Car is [" << c.color << "].\n";
}


int main() {

	std::cout << "..in friendly_function...\n";

	Car c("red");

	showColor(c);
	

	return 0;
}