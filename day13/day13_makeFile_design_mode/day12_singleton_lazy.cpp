/*

需求：

单例模式


*/


#include <iostream>

using namespace std;

/*
 * 单例模式
 *     饿汉式
 *          在还没有去获取对象之前，就已经创建好对象了。
 *
 *     1. 禁止别人创建实例  ---> 构造私有
 *
 *     2. 自己要创建实例
 *
 *     3. 把自己创建好的实例暴露出去，给别人使用。  静态成员函数。
 *
 *    c++ 里面的单例都是返回指针。
 */


class bank {
private:
    //1. 构造私有。  不让人家创建对象。
    bank() {
        cout << "构建bank对象" << endl;
    }
public:
    //2. 自己创建实例
    static  bank* b;  //自己创建

    //3. 把创建好的实例丢出去。
    static bank* getInstance() {
        return  b;
    }
};

bank* bank::b = new bank();

int main() {



    cout << "main开始啦~~" << endl;
    bank* b1 = bank::getInstance();
    bank* b2 = bank::getInstance();

    cout << "b1的地址 : " << b1 << endl;
    cout << "b2的地址 : " << b2 << endl;




    return 0;
}

/*

output

构建bank对象
main开始啦~~
b1的地址 : 00000210D3AB5100
b2的地址 : 00000210D3AB5100

*/