/*

����

����ͬ������

*/

#include <iostream>
#include <string>

using namespace std;

/*
 *  ���ʸ���ͬ������
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

int main() {


    std::cout << "..1..\n";
    father* f = new father();
    f->smoke(); // ���׵ĺ���

    std::cout << "..2..\n";
    son* s = new son();
    s->smoke(); // ���ӵĺ�����

    //�����ָ�� |���� ���Խ�������Ķ���
    std::cout << "..3..\n";
    father* fp = new son();

    //ִ�е��Ǹ��׵ĺ��� ������Ӧ���ߺ��ӵĺ�������Ϊ�������Ǻ��ӵĶ���
    std::cout << "..4..\n";
    fp->smoke();
    
    std::cout << "..5..\n";
    (new son())->smoke(); // ���ӡ�

    std::cout << "..6..\n";

    return 0;
}



/*

..1..
..�����޲�...
�����ڳ���
..2..
..�����޲�...
..�����޲�...
�����ڳ�ѩ��
..3..
..�����޲�...
..�����޲�...
..4..
�����ڳ���
..5..
..�����޲�...
..�����޲�...
�����ڳ�ѩ��
..6..

*/