/*

����

��̬���룺

��̬��̬

�����ڼ̳й�ϵ�£�������д�˸����ͬ������������ĺ��������麯��


*/

#include <iostream>
#include <string>

using namespace std;

/*
 * ��̬
 *      ��̬��̬�������ڼ̳й�ϵ�£�������д�˸����ͬ������������ĺ��������麯��
 */

class father {
public:
    virtual void smoke() {
        cout << "..���׳���..." << endl;
    }
};

class son : public father {
public:
    void smoke() {
        cout << "...���ӳ�ѩ��..." << endl;
    }
};


//class Father {
//public:
//	Father() {
//		std::cout << "..�����޲�...\n";
//	}
//	~Father() {
//		std::cout << "..�����в�...\n";
//	}
//
//	void smoke() {
//		std::cout << "..�����ڳ���...\n";
//	}
//};
//
//class Son : public Father {
//public:
//	Son() {
//		std::cout << "..�����޲�...\n";
//	}
//	~Son() {
//		std::cout << "..�����в�...\n";
//	}
//
//	void smoke() {
//		std::cout << "..�����ڳ���...\n";
//	}
//};


int main() {

/*    father f;
    f.smoke();

    son s;
    s.smoke();

    father* f1 = new father();
    f1->smoke();

    son* s1 = new son();
    s1->smoke()*/;

    //�����ָ��ָ���������
    father* f2 = new son();
    f2->smoke();                // ��ѩ�ѣ�Ϊʲô�أ���Ϊ����smoke��virtual

    return 0;
}


/*

����
��ѩ��
����
��ѩ��
��ѩ��


*/
