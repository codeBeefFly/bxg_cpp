/*

需求：

final 表示这个类是最终类，禁止被继承

*/

#include <iostream>

using namespace std;

/**
 *   final :最终
 *      1. 作用于类上。 这个类是最终类，禁止被继承。
 *      2. 作用于函数上。 这个函数是最终版本的函数，禁止子类重写。
 */
class father {

public:

    //virtual void smoke() final {    // 子类 重写 smoke 函数: can not override final function father smoke
    virtual void smoke() /*final*/ {
        cout << "父亲在抽烟" << endl;
    }
};

class son : public father {
public:
    void smoke() {
        cout << "孩子在抽雪茄" << endl;
    }
};    


class A final {
public:

    A() {}
    ~A() {}
};


//class B : public A {    // final class type cannot be used as a base class 
//
//};


int main() {

    father* f = new son();
    f->smoke();

    return 0;
}
