/*

需求：

父类指针指向子类对象

*/


#include <iostream>
#include <string>


using namespace std;


/*
 * 父类指针指向子类对象
 */


class father {
public:

    father() {
        std::cout << "..父类构造...\n";
    }
    ~father() {
        std::cout << "..父类析构...\n";
    }

};

class son : public father {

public:
    
    son() {
        std::cout << "..子类构造...\n";
    }
    ~son() {
        std::cout << "..子类析构...\n";
    }

};


int main() {

    //1. 父类的指针指向父类的对象
    std::cout << "..1..\n";
    father* f = new father();


    //2. 子类的指针指向子类的对象
    std::cout << "..2..\n";
    son* s = new son();

    //3. 父类的指针指向子类的对象  : 继承关系下可以这么写。
    //左边只能是比右边更大的类型。
    std::cout << "..3..\n";
    father* fs = new son();
    //son *sf = new father();

    std::cout << "..4..\n";
    son s1;
    son& ss1 = s1;  //子类的引用，指向子类对象
    father& fs1 = s1; //父类的引用指向子类对象。


    //对象接对象，也可以。 这样会创建父亲的对象。
    std::cout << "..5..\n";
    father ffff = s1;

    std::cout << "..6..\n";

    //father f1;
    //son &sfssss = f1;


    return 0;
}



/*


..1..
..父类构造...

..2..
..父类构造...
..子类构造...

..3..
..父类构造...
..子类构造...

..4..
..父类构造...
..子类构造...

..5..

..6..
..父类析构...
..子类析构...
..父类析构...

*/