/*

����

��̬���� �� ��̬����

*/


#include <iostream>
#include <string>

using namespace std;

/*
 *  ��̬���ͺͶ�̬����
 *      ֻ�м̳й�ϵ�£�����Ҫ��ô���ǡ�
 *
 */

class father {
public:

    father() {
        std::cout << "..�����޲ι���...\n";
    }
    ~father() {
        std::cout << "..������������...\n";
    }

};

class son : public father {
public:

    son() {
        std::cout << "..�����޲ι���...\n";
    }
    ~son() {
        std::cout << "..������������...\n";
    }

};


father* createObj() {
    return new son();
}

int main() {

    //����׶ξ��Ѿ���ȷ�����͡�

    std::cout << "..1..\n";
    int a = 3;
    string b = "bb";
    son s;

    //�������е�ʱ���֪�����ݵ�������ʲô��

    std::cout << "..2..\n";

    father* f = createObj();

    std::cout << "..3..\n";

    return 0;
}



/*

..1..
..�����޲ι���...
..�����޲ι���...
..2..
..�����޲ι���...
..�����޲ι���...
..3..
..������������...
..������������...

*/