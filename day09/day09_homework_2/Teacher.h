#pragma once

#include "Human.h"
#include "Student.h"


class Teacher : public Human
{

public:

	// 父类中已经定义了 name
	std::string subject;

	// 学生类型的弱指针，防止连环指针，指针变量如何初始化
	std::weak_ptr<Student> wp_student;	

	// Teacher 构造函数
	Teacher();
	Teacher(std::string name, std::string subject);
	~Teacher();

	// 定义+重写父类
	void work() override;

	// 匹配学生
	void setStudent(std::shared_ptr<Student> sp_student);

};

