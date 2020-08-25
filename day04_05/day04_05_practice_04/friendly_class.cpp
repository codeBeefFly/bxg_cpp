/*

��Ԫ��

*/


#include <iostream>

class Car {

private:

	std::string color;

	friend class SSSS;		// ����һ����Ԫ��

public:

	Car() : Car(color){
		std::cout << "..�޲ι��캯��...\n";
	}


	Car(std::string color) : color{ color } {
		std::cout << "..�вι��캯��...\n";
	}

	std::string getColor() {
		return color;
	}
};



class SSSS {

public:

	void paintNewColor(Car& c, std::string new_color) {
		c.color = new_color;
	}

};




int main() {

	std::cout << "..in friendly_class...\n";

	Car c("red");
	std::cout << "..car's original color [" << c.getColor() << "]\n";

	SSSS four_s;
	four_s.paintNewColor(c, "blue");
	std::cout << "..car's new color [" << c.getColor() << "]\n";


	return 0;
}


/*

output


..in friendly_class...
..�вι��캯��...
..car's original color [red]
..car's new color [blue]


*/