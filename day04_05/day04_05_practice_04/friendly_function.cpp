/*

��Ԫ����

*/



#include <iostream>

class Car {

private:
	std::string color;

public:

	Car() {
		std::cout << "..log::�޲ι��캯��...\n";
	}

	Car(std::string color) : color{ color } {
		std::cout << "..log::�вι��캯��...\n";
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