/*

����

*/



#include <iostream>

using namespace std;

/**
 * �麯��
 *      override   �� ���ڼ�鸸�����ͬ�������Ƿ�����д�ġ�
 *          ������������ͬ��������һ�����Ƕ������virtual�ؼ��֡�
 *
 */

class father {
public:
    virtual void smoke() {
    //void smoke() {  // û�� virtual ���� override ��������
        cout << "�����ڳ���" << endl;
    }
};


class son : public father {
public:
    void smoke() override {  //�����ԭ���ǣ�����û���������������������������麯����
    //void smok() override {  //�����ԭ���ǣ�����û���������������������������麯������ɫ�»��߱���
        cout << "�����ڳ�ѩ��" << endl;
    }
};


int main() {

	std::cout << "..in virtual_function_override...\n";

    father* f = new son();
    f->smoke();

	return 0;

}