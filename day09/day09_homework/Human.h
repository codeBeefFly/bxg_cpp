#pragma once


#include <iostream>


enum class Gender { MALE, FEMAL };

class Human {
public:

	std::string name;

	virtual void work() = 0;


	//�����������ܲ��ܶ��幹�캯����
	//�����й��캯���� ���ǻ��ǲ��ܴ�������
	//�������� ---> ���캯��
	//���캯�� ----> һ������������
	
	// ���캯����������ʼ�����ݵģ����Ը��������ڵ��ó�ʼ��ѽ��
	// explicit���캯����������ֹ��ʽת���ġ� 
	// ��ʽ���� T t1 = 12;
	// ��ʽ���� T t1(12);
	Human() = default;
	explicit Human(std::string name) : name{ move(name) } {
		std::cout << "..log::Human �вι���...\n";
	}

};