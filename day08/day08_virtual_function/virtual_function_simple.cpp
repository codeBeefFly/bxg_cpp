/*

需求：

简单的 虚函数


有了虚函数就可以在父类的指针或者引用指向子类的实例的前提下，
然后通过父类的指针或者引用调用实际子类的成员函数。

*/


#include <iostream>
#include <string>

using namespace std;

/**
 * 虚函数
 */
class father {
public:
    virtual void smoke() {              // 父类指针解引用调用子类函数
        cout << "父亲在抽烟" << endl;
    }

};

class son : public father {
public:
    void smoke() {
        cout << "孩子在雪茄" << endl;
    }
};

int main() {

    std::cout << "..in virutal_function_simple...\n";

    //父类的指针接收子类对象
    father* fp = new son();
    fp->smoke();  //父亲的函数  //调用的是孩子的函数

    return 0;
}


/*

output:

..in virutal_function_simple...
孩子在雪茄

*/
