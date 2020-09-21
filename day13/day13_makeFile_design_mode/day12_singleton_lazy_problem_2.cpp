#include <iostream>
#include <mutex>
#include <functional>
#include <thread>
#include <future>

using namespace std;

/*
 * ����ģʽ
 *
 *      ˫�����
 *          �ܹ�����ÿ�λ�ȡʵ����ʱ�򣬶����������ͽ����Ĳ���������ÿ�λ���Ҫ�����жϵģ�
 *          ����ж��Ǳ��ⲻ�˵ģ�ֻҪʹ������ʽ����������жϡ������һ���ж�
 *          ������Ҫ����ô��ʹ�ã�����ʽ��
 *
 *      ����ʽ�Ͷ���ʽ��ʵ����ʱ���Ч���ϵĲ��ġ�
 *
 *      ����ʽ�ǣ�һ�����ʹ��������ˣ���ô���ܻ��ó�����������ʱ����΢���ѵ�ʱ�������
 *              ���Ǻ�����ú�����ȡʵ����ʱ��Ч�ʸ��ߡ�
 *
 *      ����ʽ�ǣ���������������ô���������ô���������ͺܿ죬����ÿ������ȡʵ����ʱ��
 *              ����Ҫ�����жϣ� ��ͽ����˳��������Ч�ʡ�
 *
 *      �Ӱ�ȫ�Ƕ���˵������ʽ�ǽ��������(����99%)�����⡣
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
    //����̲߳���������������� ����ʹ��mutex�����
    //������һ�����⣺ �Ժ��ÿһ������ȡʵ�������ü����ͽ��������²����ڲ���������£�Ҳ����ô����

    //���������⣬����Ҫ������һ��if�ж�
    static bank* getInstance() {
        //Ҳ����ѽ��ÿһ������ȡʵ���������ǵ��ж�����ô���ܱ�������жϣ�
        if (b == nullptr) {
            m->lock();
            if (b == nullptr) {
                //ֻ�еȺŵ��ұ߹��������֮��  b ָ�����ָ���ǿ�ռ䡣
                // 1. �ڶ��ڴ��п��ٿռ�
                //2.  ����һ������ �Ѷ���ŵ�����ռ�����ȥ
                //3. �����֮���� ָ��b ָ�����ռ䡣
                b = new bank();
            }
            m->unlock();
        }
        return  b;
    }
};

mutex* bank::m = new mutex();
bank* bank::b = nullptr;


void async_fun() {
    while (true) {
        std::future<bank*> f = std::async(&bank::getInstance);
        //int result = f.get();
        //std::cout << "result2 = " << result << "\n";

        bank* b = f.get();
        std::cout << "..b = " << b << "\n";
    }
}


int main() {

    std::thread t1(async_fun);
    std::thread t2(async_fun);

    t1.join();
    t2.join();


    return 0;
}


//int main() {
//    cout << "main��ʼ��~~" << endl;
//    bank* b1 = bank::getInstance();
//    bank* b2 = bank::getInstance();
//
//    bank::getInstance();
//    bank::getInstance();
//    bank::getInstance();
//    bank::getInstance();
//    bank::getInstance();
//    bank::getInstance();
//    bank::getInstance();
//
//    cout << "b1�ĵ�ַ : " << b1 << endl;
//    cout << "b2�ĵ�ַ : " << b2 << endl;
//
//    return 0;
//}


/*

output:

main��ʼ��~~
b1�ĵ�ַ : 00000225D0314FC0
b2�ĵ�ַ : 00000225D0314FC0

*/