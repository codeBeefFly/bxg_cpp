/*

����

��̬���࣬��̬����

*/


#include <iostream>
#include <string>

using namespace std;

/*
 *  ��̬����Ͷ�̬����
 *     1. ��̬���ࣺ �ڱ���׶ξ�֪��Ҫ���ĸ������ˡ� C++ Ĭ�ϲ��õ����ࣺ ��̬���ࡣ
 *     2. ��̬���ࣺ ���н׶β�֪��Ҫ���ĸ�������
 *
 */

class father {

public:

    father() {
        std::cout << "..�����޲�...\n";
    }
    ~father() {
        std::cout << "..��������...\n";
    }

    void smoke() {
        cout << "�����ڳ���" << endl;
    }
};

class son : public father {
public:

    son() {
        std::cout << "..�����޲�...\n";
    }
    ~son() {
        std::cout << "..��������...\n";
    }


    void smoke() {
        cout << "�����ڳ�ѩ��" << endl;
    }
};

int add(int a, int b) {     // ��̬
    return a + b;
}

int add(int a, double b) {  // ��̬
    return a + b;
}



int main() {
    add(3, 4);
    add(3, 4.5);

    
    std::cout << "..1..\n";
    son s;
    s.smoke(); //���ӵĳ��̺�����

    std::cout << "..2..\n";
    father f;
    f.smoke(); // ���׵ĳ��̺���

    std::cout << "..3..\n";
    son* sp = new son();
    sp->smoke(); // ���ӵĺ���

    std::cout << "..4..\n";
    father* fp = new father();
    fp->smoke(); // ���׵ĺ���

    std::cout << "..5..\n";
    //�ڱ���׶Σ��Ѿ���ȷ�����fs�� father�������͡�
    //����ֱ�Ӿ����˸��׵�smoke������
    father* fs = new son();
    fs->smoke();

    std::cout << "..6..\n";

    return 0;
}



/*

output

..1..
..�����޲�...
..�����޲�...
�����ڳ�ѩ��
..2..
..�����޲�...
�����ڳ���
..3..
..�����޲�...
..�����޲�...
�����ڳ�ѩ��
..4..
..�����޲�...
�����ڳ���
..5..
..�����޲�...
..�����޲�...
�����ڳ���
..6..
..��������...
..��������...
..��������...


*/

