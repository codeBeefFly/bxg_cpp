/*

����

������������ģ�庯������ӷ�


ģ�庯���﷨

template <typename T, typename H> 


*/


#include <iostream>


template <typename T>
T add_00(T a, T b) {
	return a + b;
}

template <typename T, typename H>
int add_01(T a, H b) {
	return a + b;
}

template <typename T, typename H>
T add_02(T a, H b) {
	return a + b;
}


int main() {

	std::cout << "..in template_01...\n";

	std::cout << add_00(3.0, 4.5) << "\n";
	std::cout << add_01(3.0, 4.5) << "\n";
	std::cout << add_02(3.0, 4.5) << "\n";

	return 0;

}


/*

output


..in template_01...
7.5
7
7.5

*/