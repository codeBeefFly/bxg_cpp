/*

����

final ��ʾ������������࣬��ֹ���̳�

*/

#include <iostream>

using namespace std;

/**
 *   final :����
 *      1. ���������ϡ� ������������࣬��ֹ���̳С�
 *      2. �����ں����ϡ� ������������հ汾�ĺ�������ֹ������д��
 */
class father {

public:

    //virtual void smoke() final {    // ���� ��д smoke ����: can not override final function father smoke
    virtual void smoke() /*final*/ {
        cout << "�����ڳ���" << endl;
    }
};

class son : public father {
public:
    void smoke() {
        cout << "�����ڳ�ѩ��" << endl;
    }
};    


class A final {
public:

    A() {}
    ~A() {}
};


//class B : public A {    // final class type cannot be used as a base class 
//
//};


int main() {

    father* f = new son();
    f->smoke();

    return 0;
}
