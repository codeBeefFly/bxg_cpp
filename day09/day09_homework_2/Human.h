#pragma once


#include <iostream>


// �޶���Χ��ö��
enum class Gender
{
	MALE,
	FEMAL,
};


class Human {
public:


	std::string name;
	virtual void work() = 0;	// ʹ���Ϊ�����࣬�����趨�壬��ȻҲ�ǳ����࣬������û�ж���


	Human() = default;

	// ��ʾ��ʼ������ explicit
	explicit Human(std::string name) : name{ move(name) } {	// ʹ����ֵ��ʼ��
		std::cout << "..log::Human �вι��캯��...\n";
	}

};
