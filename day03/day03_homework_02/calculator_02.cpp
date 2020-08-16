/*

��ҵ��
һ�� ���һ�������������мӼ��˳�����������һ������operator���ܹ�Ҫ����5��������
�ú������������������ֱ��ǣ� a, b  ������ִ�еľ������������ָ�롣
����ͨ��operator�����ö�Ӧ�������������������£�
operator(3,4 , add) ; // ִ�мӷ�����
operator(3,4 , sub) ; //ִ�м�������
operator(3,4 , mul); //ִ�г˷�����
operator(3,4 , div) ; //�������㡣
���е������������Ǻ���ָ�롣

��. �����Ӽ��˳����ܣ��ĸ�������ÿ������ֻҪ�����������ɡ�
���мӷ��ͼ�������������ֵ���ã����˷��ͳ�������������ֵ���á�
add(int &a , int &b)
...
...
...

main(){
	int num1 = 3;
	int num2 = 4;


}


�ж���ֵ����ֵ��
��ȡ��ַ�ľ�����ֵ ��
��һ�������Ϊ��ֵʱ��ʹ�õ�������ֵ�����ݣ� �� ����Ϊ��ֵʱ��ʹ�õ���������ݣ����ڴ��е�λ�ã���

*/


#include <iostream>
#include <vector>


typedef float(*fun_ptr_LR)(int&, int&);
typedef float(*fun_ptr_RR)(int&&, int&&);


float op_add(int&, int&);		// ������ֵ����
float op_sub(int&, int&);		// ������ֵ����
float op_mul(int&&, int&&);		// ������ֵ����
float op_div(int&&, int&&);		// ������ֵ����


float calculator_api_fptr_LR(int, int, fun_ptr_LR);
float calculator_api_fptr_RR(int, int, fun_ptr_RR);

float calculator_api_LR(int, int, float(*fun_ptr)(int&, int&));
float calculator_api_RR(int, int, float(*fun_ptr)(int&&, int&&));


void helper() {
	std::cout << "..operation choice...\n"
		<< "..1-addition\n"
		<< "..2-subtraction\n"
		<< "..3-multiplication\n"
		<< "..4-division\n";
}


//int exit_program() {
//	std::cout << "..exit calculator...\n";
//	return 0;
//}

int main() {

	helper();

	bool flag = true;
	while (flag) {
		std::cout << "\n..enter your choice::\t";
		int choice;
		std::cin >> choice;
		if (choice == 0) {
			std::cout << "..exit calculator...\n";
			return 0;
		}
		std::cout << "..enter operand a, b inorder::\t";
		int a, b;
		std::cin >> a >> b;		// a, b ����ֵ

		//op_add(a, b);
		std::cout << "5 / 3 = " << op_div(5, 3)
			<< "\n";
		int x = 5, y = 3;
		std::cout << "5 / 3 = " << op_div(std::move(x), std::move(y))
			<< "\n";
		std::cout << "5 / 3 = " << calculator_api_fptr_RR(std::move(x), std::move(y), op_div)
			<< "\n";
		std::cout << a << " / " << b << " = " << calculator_api_fptr_RR(std::move(a), std::move(b), op_div)			// ������ 1.25
			<< "\n";


		switch (choice)
		{
		case 1:
			std::cout << a << " + " << b << " = " << calculator_api_fptr_LR(a, b, op_add);
			break;
		case 2:
			std::cout << a << " - " << b << " = " << calculator_api_fptr_LR(a, b, op_sub);
			break;
		case 3:
			std::cout << a << " * " << b << " = " << calculator_api_fptr_RR(std::move(a), std::move(a), op_mul);	// move ����ֵת������ֵ
			break;
		case 4:
			std::cout << a << " / " << b << " = " << calculator_api_fptr_RR(std::move(a), std::move(a), op_div);	// Ϊʲô�� 1 ���� 1.25
			break;
		default:
			break;
		}
	}
	

	return 0;
}


float op_add(int& a, int& b) {
	return a + b;
}


float op_sub(int& a, int& b) {
	return a - b;
}


float op_mul(int&& a, int&& b) {
	return a * b;
}


float op_div(int&& a, int&& b) {
	if (b == 0) {
		std::cout << "..error::divide by 0...\n";
		return -1;
	}
	else {
		return (float)a / (float)b;
	}
}


float calculator_api_fptr_LR(int a, int b, fun_ptr_LR fun_ptr) {
	return fun_ptr(a, b);
}


float calculator_api_fptr_RR(int a, int b, fun_ptr_RR fun_ptr) {
	return fun_ptr(std::move(a), std::move(b));
}


float calculator_api_LR(int a, int b, float(*fun_ptr)(int&, int&)) {
	return fun_ptr(a, b);
}


float calculator_api_RR(int a, int b, float(*fun_ptr)(int&&, int&&)) {
	return fun_ptr(std::move(a), std::move(b));
}



/*

output:


..operation choice...
..1-addition
..2-subtraction
..3-multiplication
..4-division

..enter your choice::   4
..enter operand a, b inorder::  9 8
5 / 3 = 1.66667
5 / 3 = 1.66667
5 / 3 = 1.66667
9 / 8 = 1.125
9 / 8 = 1
9 / 8 = 1
..enter your choice::   0
..exit calculator...

D:\W_workPlace\bxg_cpp\day03\build\Debug\day03_homework_calculator_02.exe (process 5640) exited with code 0.
Press any key to close this window . . .

*/