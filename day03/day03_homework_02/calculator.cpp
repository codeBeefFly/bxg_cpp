/*

���һ�������������мӼ��˳�����������һ������operator��
�ú������������������ֱ��ǣ� a, b  �� 
������ִ�еľ������������ָ�롣����ͨ��operator�����ö�Ӧ�������������������£�

operator( 3, 4, , add) ; // ִ�мӷ�����

operator(3,4 , sub) ; //ִ�м�������

operator(3,4 , mul); //ִ�г˷�����

operator(3,4,div) ; //�������㡣

���е������������Ǻ���ָ�롣

Ϊ����ϰ typedef ȫ��ʹ�� typedef �ѻ�������+����ָ�������������

*/


#include <iostream>
#include <vector>


typedef int my_int;
typedef float my_float;
typedef void my_void;
typedef my_float(*fun_ptr)(my_int, my_int);		// fun_ptr �����������ĺ���ָ������


my_float op_add(my_int, my_int);
my_float op_sub(my_int, my_int);
my_float op_mul(my_int, my_int);
my_float op_div(my_int, my_int);


my_float operator_api(my_int, my_int, fun_ptr);


int main() {

	std::cout << "..calculator choice options ::\n"
		<< "..1-addition\n"
		<< "..2-subtraction\n"
		<< "..3-multiplication\n"
		<< "..4-division\n"
		<< "..0-exit\n";
	
	bool flag = true;
	while (flag) {

		std::cout << "\n..enter choice ::\t";
		int choice;
		std::cin >> choice;
		if (choice == 0) {
			std::cout << "..exit calculator...\n";
			return 0;
		}
		std::cout << "..enter oprand a b in order ::\t";
		int a, b;
		std::cin >> a >> b;

		fun_ptr fptr;
		switch (choice)
		{
		case 1:
			fptr = op_add;
			std::cout << a << " + " << b << " = " << operator_api(a, b, op_add);
			break;
		case 2:
			fptr = op_sub;
			std::cout << a << " - " << b << " = " << operator_api(a, b, fptr);
			break;
		case 3:
			fptr = op_mul;
			std::cout << a << " * " << b << " = " << operator_api(a, b, fptr);
			break;
		case 4:
			fptr = op_div;
			std::cout << a << " / " << b << " = " << operator_api(a, b, fptr);
			break;
		case 0:
			flag = false;
			std::cout << "..exit calculator...\n";
			return 0;
			break;
		default:
			break;
		}
	
	}

	return 0;										  
}


my_float op_add(my_int a, my_int b) {
	return a + b;
}


my_float op_sub(my_int a, my_int b) {
	return a - b;
}


my_float op_mul(my_int a, my_int b) {
	return a * b;
}


my_float op_div(my_int a, my_int b) {
	if (b == 0) {
		std::cout << "..error::divided by 0...\n";
		return -1;
	}
	else {
		return (float)a / (float)b;
	}
}


my_float operator_api(my_int a, my_int b, fun_ptr input_fun) {
	return input_fun(a, b);
}