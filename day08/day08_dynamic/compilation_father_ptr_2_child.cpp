/*

����

����ָ��ָ���������

*/


#include <iostream>
#include <string>


using namespace std;


/*
 * ����ָ��ָ���������
 */


class father {
public:

    father() {
        std::cout << "..���๹��...\n";
    }
    ~father() {
        std::cout << "..��������...\n";
    }

};

class son : public father {

public:
    
    son() {
        std::cout << "..���๹��...\n";
    }
    ~son() {
        std::cout << "..��������...\n";
    }

};


int main() {

    //1. �����ָ��ָ����Ķ���
    std::cout << "..1..\n";
    father* f = new father();


    //2. �����ָ��ָ������Ķ���
    std::cout << "..2..\n";
    son* s = new son();

    //3. �����ָ��ָ������Ķ���  : �̳й�ϵ�¿�����ôд��
    //���ֻ���Ǳ��ұ߸�������͡�
    std::cout << "..3..\n";
    father* fs = new son();
    //son *sf = new father();

    std::cout << "..4..\n";
    son s1;
    son& ss1 = s1;  //��������ã�ָ���������
    father& fs1 = s1; //���������ָ���������


    //����Ӷ���Ҳ���ԡ� �����ᴴ�����׵Ķ���
    std::cout << "..5..\n";
    father ffff = s1;

    std::cout << "..6..\n";

    //father f1;
    //son &sfssss = f1;


    return 0;
}



/*


..1..
..���๹��...

..2..
..���๹��...
..���๹��...

..3..
..���๹��...
..���๹��...

..4..
..���๹��...
..���๹��...

..5..

..6..
..��������...
..��������...
..��������...

*/