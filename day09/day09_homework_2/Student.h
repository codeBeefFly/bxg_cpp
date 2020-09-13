#pragma once

#include <memory>
#include "Human.h"
#include "Teacher.h"


class Student : public Human
{

public:

	// �̳��� �����ж���� name
	// ������û�ж��� gender��ͷ�ļ�����
	std::string id;
	Gender gender;

	// Teacher ���Ͷ���Ĺ���ָ�룬ָ�������γ�ʼ��
	std::shared_ptr<Teacher> sp_teacher;

	// Student ����+��������
	Student();
	Student(std::string name, std::string id, Gender gender);
	~Student();

	// Student �������캯��
	//Student(const Student& stu);
	Student(Student& stu);

	// ����+��д����Ĵ��麯��
	void work() override;	// override �ؼ��������ⲿ�ĺ��������в���Ҫд

	// ѧ��������ʦ
	void setTeacher(std::shared_ptr<Teacher> sp_teacher);

};

