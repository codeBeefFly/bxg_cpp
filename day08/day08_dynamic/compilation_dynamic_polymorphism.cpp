/*

需求：

动态编译：

动态多态

发生在继承关系下，子类重写了父类的同名函数。父类的函数还是虚函数


*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 多态
 *      动态多态，发生在继承关系下，子类重写了父类的同名函数。父类的函数还是虚函数
 */

class father {
public:
    virtual void smoke() {
        cout << "..父亲抽烟..." << endl;
    }
};

class son : public father {
public:
    void smoke() {
        cout << "...孩子抽雪茄..." << endl;
    }
};


//class Father {
//public:
//	Father() {
//		std::cout << "..父类无参...\n";
//	}
//	~Father() {
//		std::cout << "..父类有参...\n";
//	}
//
//	void smoke() {
//		std::cout << "..父亲在抽烟...\n";
//	}
//};
//
//class Son : public Father {
//public:
//	Son() {
//		std::cout << "..子类无参...\n";
//	}
//	~Son() {
//		std::cout << "..子类有参...\n";
//	}
//
//	void smoke() {
//		std::cout << "..孩子在抽烟...\n";
//	}
//};


int main() {

/*    father f;
    f.smoke();

    son s;
    s.smoke();

    father* f1 = new father();
    f1->smoke();

    son* s1 = new son();
    s1->smoke()*/;

    //父类的指针指向子类对象
    father* f2 = new son();
    f2->smoke();                // 抽雪茄，为什么呢，因为父类smoke是virtual

    return 0;
}


/*

抽烟
抽雪茄
抽烟
抽雪茄
抽雪茄


*/
