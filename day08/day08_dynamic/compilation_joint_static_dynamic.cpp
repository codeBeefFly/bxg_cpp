/*

需求：

静态联编，动态联编

*/


#include <iostream>
#include <string>

using namespace std;

/*
 *  静态联编和动态联编
 *     1. 静态联编： 在编译阶段就知道要走哪个函数了。 C++ 默认采用的联编： 静态联编。
 *     2. 动态联编： 运行阶段才知道要走哪个函数。
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

int add(int a, int b) {     // 静态
    return a + b;
}

int add(int a, double b) {  // 静态
    return a + b;
}



int main() {
    add(3, 4);
    add(3, 4.5);

    
    std::cout << "..1..\n";
    son s;
    s.smoke(); //孩子的抽烟函数。

    std::cout << "..2..\n";
    father f;
    f.smoke(); // 父亲的抽烟函数

    std::cout << "..3..\n";
    son* sp = new son();
    sp->smoke(); // 孩子的函数

    std::cout << "..4..\n";
    father* fp = new father();
    fp->smoke(); // 父亲的函数

    std::cout << "..5..\n";
    //在编译阶段，已经明确了这个fs是 father这种类型。
    //所以直接就走了父亲的smoke函数。
    father* fs = new son();
    fs->smoke();

    std::cout << "..6..\n";

    return 0;
}



/*

output

..1..
..父类无参...
..子类无参...
孩子在抽雪茄
..2..
..父类无参...
父亲在抽烟
..3..
..父类无参...
..子类无参...
孩子在抽雪茄
..4..
..父类无参...
父亲在抽烟
..5..
..父类无参...
..子类无参...
父亲在抽烟
..6..
..父类析构...
..子类析构...
..父类析构...


*/

