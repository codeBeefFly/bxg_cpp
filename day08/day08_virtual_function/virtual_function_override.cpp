/*

需求：

*/



#include <iostream>

using namespace std;

/**
 * 虚函数
 *      override   ： 用于检查父子类的同名函数是否是重写的。
 *          如果父子类存在同名函数，一般他们都会加上virtual关键字。
 *
 */

class father {
public:
    virtual void smoke() {
    //void smoke() {  // 没有 virtual 子类 override 函数报错
        cout << "父亲在抽烟" << endl;
    }
};


class son : public father {
public:
    void smoke() override {  //报错的原因是，父类没有这个函数，或者这个函数不是虚函数。
    //void smok() override {  //报错的原因是，父类没有这个函数，或者这个函数不是虚函数。红色下划线报错
        cout << "孩子在抽雪茄" << endl;
    }
};


int main() {

	std::cout << "..in virtual_function_override...\n";

    father* f = new son();
    f->smoke();

	return 0;

}