#include <iostream>
#include "calc.h"

int op_add(int oprand1, int oprand2) {
	return oprand1 + oprand2;
}

int op_sub(int oprand1, int oprand2) {
	return oprand1 - oprand2;
}

int op_mul(int oprand1, int oprand2) {
	return oprand1 * oprand2;
}

float op_div(int oprand1, int oprand2) {
	if (oprand2 != 0)
		return (float)oprand1 / (float)oprand2;
	else {
		std::cout << "..divide by 0...\n";
		return -1;
	}
}