/*

����

��������������̳е��麯��

*/


#include <iostream>
#include <string>

using namespace std;

/**
 * �麯��
 */
class person {
public:
    string name = "������";
    virtual void eat() {
        std::cout << "..���׳Է�...\n";
    }
    virtual void sleep() = 0;   // ���麯�� need overrider
};

class stu : public person {
public:
    string school = "����ѧԺ";
    virtual void eat() {    // ����̳еĺ���Ҳ����д�� virtual
        std::cout << "..ѧ���Է�...\n";
    }
    virtual void read() {
        std::cout << "..ѧ������...\n";
    }

    virtual void sleep() override {     // ���Ǹ��ി�麯������Ҫ�������ж���
        std::cout << "..ѧ��˯��...\n";
    }
};

int main() {
    //�����ָ������������
    person* p = new stu();
    p->eat();
    return 0;
}


/*

output:

..ѧ���Է�...

*/