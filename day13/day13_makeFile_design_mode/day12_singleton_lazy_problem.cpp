#include <iostream>
#include <mutex>

using namespace std;

/*
 * ����ģʽ
 *
 *      ����ʽ�����⣺
 */


class bank {
private:
    static mutex* m;
    //1. ����˽�С�  �����˼Ҵ�������
    bank() = default;
public:
    //2. �Լ�����ʵ��
    static  bank* b;  //�Լ�����

    //3. �Ѵ����õ�ʵ������ȥ��
    //����̲߳����������������
    static bank* getInstance() {
        /*
        if(money >= 100){
            money -= 100;
        }
        */
        m->lock();
        if (b == nullptr) {
            //ֻ�еȺŵ��ұ߹��������֮��  b ָ�����ָ���ǿ�ռ䡣
            // 1. �ڶ��ڴ��п��ٿռ�
            //2.  ����һ������ �Ѷ���ŵ�����ռ�����ȥ
            //3. �����֮���� ָ��b ָ�����ռ䡣
            b = new bank();
        }
        m->unlock();
        return  b;
    }
};

mutex* bank::m = new mutex();
bank* bank::b = nullptr;

int main() {
    cout << "main��ʼ��~~" << endl;
    bank* b1 = bank::getInstance();
    bank* b2 = bank::getInstance();

    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();

    cout << "b1�ĵ�ַ : " << b1 << endl;
    cout << "b2�ĵ�ַ : " << b2 << endl;

    return 0;

}


/*

output

main��ʼ��~~
b1�ĵ�ַ : 0000016E5581E0D0
b2�ĵ�ַ : 0000016E5581E0D0


*/