/*

����

�򵥵� �麯��


�����麯���Ϳ����ڸ����ָ���������ָ�������ʵ����ǰ���£�
Ȼ��ͨ�������ָ��������õ���ʵ������ĳ�Ա������

*/


#include <iostream>
#include <string>

using namespace std;

/**
 * �麯��
 */
class father {
public:
    virtual void smoke() {              // ����ָ������õ������ຯ��
        cout << "�����ڳ���" << endl;
    }

};

class son : public father {
public:
    void smoke() {
        cout << "������ѩ��" << endl;
    }
};

int main() {

    std::cout << "..in virutal_function_simple...\n";

    //�����ָ������������
    father* fp = new son();
    fp->smoke();  //���׵ĺ���  //���õ��Ǻ��ӵĺ���

    return 0;
}


/*

output:

..in virutal_function_simple...
������ѩ��

*/
