#pragma once

#include "Human.h"
#include "Student.h"


class Teacher : public Human
{

public:

	// �������Ѿ������� name
	std::string subject;

	// ѧ�����͵���ָ�룬��ֹ����ָ�룬ָ�������γ�ʼ��
	std::weak_ptr<Student> wp_student;	

	// Teacher ���캯��
	Teacher();
	Teacher(std::string name, std::string subject);
	~Teacher();

	// ����+��д����
	void work() override;

	// ƥ��ѧ��
	void setStudent(std::shared_ptr<Student> sp_student);

};

