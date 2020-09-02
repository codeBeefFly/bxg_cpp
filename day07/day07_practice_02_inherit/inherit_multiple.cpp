/*

����

���ؼ̳� + ����


������ؼ̳еĶ���������
�̳еĳ�Աͬ���������Ķ�����(ambiguous)���⡣

����취��ʹ�÷�Χ���η� ::



*/

#include <iostream>


class Mother {
public:
	std::string name;

	Mother(std::string name) : name{ name } {
		std::cout << "..mother ���캯��...\n";
	};
	~Mother() {
		std::cout << "..mother ��������...\n";
	};

	void say() {
		std::cout << "..mother " << this->name << " do housework...\n";
	}
};



class Father {
public:
	std::string name;

	Father(std::string name) : name{ name } {
		std::cout << "..father ���캯��...\n";
	};
	~Father() {
		std::cout << "..father ��������...\n";
	};

	void say() {
		std::cout << "..Father " << this->name << " earn money...\n";
	}
};


class Son : public Father, public Mother {	// ͬʱ�̳��� ͬ���� name �������

public:
	
	std::string name;

	// ������вι��캯�����̳�����������ĳ�Ա�����Կ���ͨ���вι����ʼ����������Ա
	// ע����������ͨ���вι���ĳ�ʼ���б�ʽ��ʼ��
	// ��ǰ�࣬����ĳ�Ա
	// ��ʼ�������Աͨ�� ����Ĺ��캯���ķ�ʽ
	Son(std::string name, std::string f_name, std::string m_name) : name{ name }, Father(f_name), Mother(m_name) {
		std::cout << "..Child ���캯��...\n";
	}
	~Son() {
		std::cout << "..Chile ��������...\n";
	}

	void say() {
		Father::say();
		Mother::say();
		
		std::cout << "..Child's Father " << Father::name << ", Mother " << Mother::name << ", and Child " << this->name << " live together.\n";
	}

};


int main() {

	std::cout << "..in inherit_multiple...\n";

	Son s("jacob", "Lee", "Jin");
	s.say();

	return 0;

}



/*

..in inherit_multiple...
..father ���캯��...
..mother ���캯��...
..Child ���캯��...
..Father Lee earn money...
..mother Jin do housework...
..Child's Father Lee, Mother Jin, and Child jacob live together.
..Chile ��������...
..mother ��������...
..father ��������...

*/