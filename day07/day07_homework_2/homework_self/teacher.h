#ifndef DAY07_HOMEWORK_TEACHER_H
#define DAY07_HOMEWORK_TEACHER_H


#include <iostream>

class Teacher {
public:

	std::string name;
	int age;
	std::string subject;

	Teacher() = default;
	Teacher(std::string name, int age, std::string subject);
	~Teacher();

};



#endif // !DAY07_HOMEWORK_TEACHER_H
