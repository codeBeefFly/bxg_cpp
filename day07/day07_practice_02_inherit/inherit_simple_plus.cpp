/*

����

���� person ��
public
��Ա��name
private
��Ա��age
protect��
������
eat


���� student �࣬�̳� person��
public:
��չ�� read ����

*/





#include <iostream>

class Person {
public:
	std::string name;

private:
	int age;

protected:
	void eat() {
		std::cout << name << " eat food\n";
	}

 };


class Student : public Person{

public:
	void read() {
		std::cout << name << " read book\n";
	}

 };





int main() {

	std::cout << "..in inherit_simple_plus...\n";

	Person p;
	p.name = "person";
	//p.age // ����
	//p.eat()

	Student s;
	s.name = "student";
	s.read();


	return 0;
}