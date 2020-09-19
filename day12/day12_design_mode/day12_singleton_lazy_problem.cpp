#include <iostream>
#include <mutex>

using namespace std;

/*
 * 单例模式
 *
 *      懒汉式的问题：
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
    //如果线程并发访问这个函数。
    static bank* getInstance() {
        /*
        if(money >= 100){
            money -= 100;
        }
        */
        m->lock();
        if (b == nullptr) {
            //只有等号的右边工作完成了之后，  b 指针才能指向那块空间。
            // 1. 在堆内存中开辟空间
            //2.  创建一个对象。 把对象放到这个空间里面去
            //3. 完成了之后，让 指针b 指向这块空间。
            b = new bank();
        }
        m->unlock();
        return  b;
    }
};

mutex* bank::m = new mutex();
bank* bank::b = nullptr;

int main() {
    cout << "main开始啦~~" << endl;
    bank* b1 = bank::getInstance();
    bank* b2 = bank::getInstance();

    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();
    bank::getInstance();

    cout << "b1的地址 : " << b1 << endl;
    cout << "b2的地址 : " << b2 << endl;

    return 0;

}


/*

output

main开始啦~~
b1的地址 : 0000016E5581E0D0
b2的地址 : 0000016E5581E0D0


*/