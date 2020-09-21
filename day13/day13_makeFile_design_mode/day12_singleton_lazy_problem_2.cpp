#include <iostream>
#include <mutex>
#include <functional>
#include <thread>
#include <future>

using namespace std;

/*
 * 单例模式
 *
 *      双锁检查
 *          能够避免每次获取实例的时候，都经过加锁和解锁的操作。但是每次还是要经过判断的，
 *          这个判断是避免不了的，只要使用懒汉式，必须得有判断。如果连一个判断
 *          都不想要，那么请使用，饿汉式。
 *
 *      懒汉式和饿汉式其实就是时间和效率上的博弈。
 *
 *      饿汉式是：一上来就创建对象了，那么可能会让程序在启动的时候，稍微花费的时间更长，
 *              但是后面调用函数获取实例的时候，效率更高。
 *
 *      懒汉式是：程序的启动，不用创建对象，那么程序启动就很快，但是每次来获取实例的时候
 *              都需要经过判断， 这就降低了程序的运行效率。
 *
 *      从安全角度来说，饿汉式是解决了所有(至少99%)的问题。
 */


class bank {
private:
    static mutex* m;
    //1. 构造私有。  不让人家创建对象。
    bank() = default;
public:
    //2. 自己创建实例
    static  bank* b;  //自己创建

    //3. 把创建好的实例丢出去。
    //如果线程并发访问这个函数。 可以使用mutex来解决
    //但是有一个问题： 以后的每一次来获取实例，都得加锁和解锁，哪怕不是在并发的情况下，也得这么做。

    //解决这个问题，就是要再套上一层if判断
    static bank* getInstance() {
        //也不对呀，每一次来获取实例，不还是得判断吗？怎么才能避免这个判断？
        if (b == nullptr) {
            m->lock();
            if (b == nullptr) {
                //只有等号的右边工作完成了之后，  b 指针才能指向那块空间。
                // 1. 在堆内存中开辟空间
                //2.  创建一个对象。 把对象放到这个空间里面去
                //3. 完成了之后，让 指针b 指向这块空间。
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
//    cout << "main开始啦~~" << endl;
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
//    cout << "b1的地址 : " << b1 << endl;
//    cout << "b2的地址 : " << b2 << endl;
//
//    return 0;
//}


/*

output:

main开始啦~~
b1的地址 : 00000225D0314FC0
b2的地址 : 00000225D0314FC0

*/