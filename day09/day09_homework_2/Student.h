#pragma once

#include <memory>
#include "Human.h"
#include "Teacher.h"


class Student : public Human
{

public:

	// 继承了 父类中定义的 name
	// 父类中没有定义 gender，头文件中有
	std::string id;
	Gender gender;

	// Teacher 类型对象的共享指针，指针变量如何初始化
	std::shared_ptr<Teacher> sp_teacher;

	// Student 构造+析构函数
	Student();
	Student(std::string name, std::string id, Gender gender);
	~Student();

	// Student 拷贝构造函数
	//Student(const Student& stu);
	Student(Student& stu);

	// 定义+重写父类的纯虚函数
	void work() override;	// override 关键字在类外部的函数定义中不需要写

	// 学生分配老师
	void setTeacher(std::shared_ptr<Teacher> sp_teacher);

};

