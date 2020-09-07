/*

����

�ƻ����������Ρ����Ρ�Բ�Σ������ܳ�
ʹ���������˼����Ƴ�����ͼ�Σ�
ʹ�ü̳У����麯��


���� 

Geometry �࣬�д��麯�� cal_perimeter

���弸�����࣬override ���麯��

triangle -->  perimeter = a + b + c

rectangle --> 2 * (a + b)

circle	--> 2 * pi * r


*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


class Geometry {

public:
	virtual float cal_perimeter() = 0;

};


class Rectangle : public Geometry {

public:

	float base, height;

	Rectangle() = default;
	Rectangle(float base, float height) : base{ base }, height{ height } {}
	~Rectangle() {}

	float cal_perimeter() override {	// override �����麯���Ĳ����б�Ҳ����ƥ��
		return base * height;
	}

};


class Triangle : public Geometry {

public:

	float edge_1, edge_2, edge_3;

	Triangle() = default;
	Triangle(float edge_1, float edge_2, float edge_3) : edge_1{ edge_1 }, edge_2{ edge_2 }, edge_3{ edge_3 } {}
	~Triangle() {}

	float cal_perimeter() override {
		return edge_1 + edge_2 + edge_3;
	}

};


class Circle : public Geometry {

public:

	float radius;

	Circle() = default;
	Circle(float radius) : radius{ radius } {}
	~Circle() {}

	float cal_perimeter() override {
		return 2 * M_PI * radius;
	}

};


int main() {

	std::cout << "..in virtual_function_practice_geometry...\n";

	Geometry* g_1 = new Circle(6);

	std::cout << "..circle perimeter = " << g_1->cal_perimeter() << "\n";

	return 0;
}


/*

..in virtual_function_practice_geometry...
..circle perimeter = 37.6991

*/
