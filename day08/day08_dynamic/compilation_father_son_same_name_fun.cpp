/*

需求：

父子同名函数

*/

#include <iostream>
#include <string>

using namespace std;

/*
 *  访问父子同名函数
 *
 */

class father {

public:

    father() {
        std::cout << "..父类无参...\n";
    }
    ~father() {
        std::cout << "..父类析构...\n";
    }

    void smoke() {
        cout << "父亲在抽烟" << endl;
    }
};

class son : public father {
public:

    son() {
        std::cout << "..子类无参...\n";
    }
    ~son() {
        std::cout << "..子类析构...\n";
    }


    void smoke() {
        cout << "孩子在抽雪茄" << endl;
    }
};

int main() {


    std::cout << "..1..\n";
    father* f = new father();
    f->smoke(); // 父亲的函数

    std::cout << "..2..\n";
    son* s = new son();
    s->smoke(); // 孩子的函数、

    //父类的指针 |引用 可以接受子类的对象
    std::cout << "..3..\n";
    father* fp = new son();

    //执行的是父亲的函数 理论上应该走孩子的函数，因为创建的是孩子的对象。
    std::cout << "..4..\n";
    fp->smoke();
    
    std::cout << "..5..\n";
    (new son())->smoke(); // 孩子。

    std::cout << "..6..\n";

    return 0;
}



/*

..1..
..父类无参...
父亲在抽烟
..2..
..父类无参...
..子类无参...
孩子在抽雪茄
..3..
..父类无参...
..子类无参...
..4..
父亲在抽烟
..5..
..父类无参...
..子类无参...
孩子在抽雪茄
..6..

*/