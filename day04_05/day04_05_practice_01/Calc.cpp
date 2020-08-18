#include "Calc.h"
#include <iostream>


float Calc::op_add(int a, int b){
	return a + b;
}


float Calc::op_sub(int a, int b){
	return a - b;
}


float Calc::op_mul(int a, int b){
	return a * b;
}


float Calc::op_div(int a, int b) {
	if (b == 0) {
		std::cout << "..error::divided by 0...\n";
		return -1;
	}
	else {
		return (float)a / (float)b;
	}
}
