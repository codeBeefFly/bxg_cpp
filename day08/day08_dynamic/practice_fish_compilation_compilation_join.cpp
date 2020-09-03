/*

需求：


 * 一家海洋馆开业了，门口挂着牌子说：欢迎鲨鱼进来游泳。
 * 过了几天，再贴出告示，欢迎鳄鱼也进来游泳，
 * 又过了几天，说欢迎罗非鱼也进来游泳，最后干脆直接说了，
 * 只要是鱼类的都可以进来游泳。请使用面向对象的思想，
 
 * 设计海洋馆馆接收鱼类的过程。 多态。
 


    shark s;            //鲨鱼
    crocodile c;        //鳄鱼
    Tilapia t;          //鲱鱼

    Aquarium

*/


/******************* test code *******************/
//#include <iostream>
//
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
//	void smoke() {		// 如果是 virtual void smoke() 就走孩子的 smoke()
//		std::cout << "..孩子在抽烟...\n";
//	}
//};
//
//
//int main() {
//
//	std::cout << "..in practice_test...\n";
//
//	Father* f = new Son;
//	f->smoke();		//..父亲在抽烟... 因为 父类的 smoke 没有 virtul
//
//
//	return 0;
//}

/*

output

..in practice_test...
..父类无参...
..子类无参...
..父亲在抽烟...

*/

/******************* test code *******************/


/*

需求：


 * 一家海洋馆开业了，门口挂着牌子说：欢迎鲨鱼进来游泳。
 * 过了几天，再贴出告示，欢迎鳄鱼也进来游泳，
 * 又过了几天，说欢迎罗非鱼也进来游泳，最后干脆直接说了，
 * 只要是鱼类的都可以进来游泳。请使用面向对象的思想，

 * 设计海洋馆馆接收鱼类的过程。 多态。



    shark s;            //鲨鱼
    crocodile c;        //鳄鱼
    Tilapia t;          //鲱鱼

    Aquarium


1. 使用动态多态
2. Fish 为父类，swim 为虚函数
3. 子类 Shark，Crocodile，Tilapia 继承 Fish 类
4. Aquarium 类接收鱼类，鱼类通过动态多态区分不同的鱼子类
  

*/


#include <iostream>


class Fish {
public:

    virtual void swim() {
        std::cout << "..鱼在游泳...\n";
    }

};


class Shark : public Fish {     // 没有访问修饰，convert to inaccessible base is not allowed
public:
    void swim() {
        std::cout << "..shark 在游泳...\n";
    }
};


class Crocodile : public Fish {
public:
    void swim() {
        std::cout << "..Crocodile 在游泳...\n";
    }
};


class Tilapia : public Fish {
public:
    void swim() {
        std::cout << "..Tilapia 在游泳...\n";
    }
};


class Aquarim {
public:
    void welcome_to_swim(Fish* f){  // 动态多态
        f->swim();
    }

};

int main() {

    std::cout << "..practice_fish...\n";

    Aquarim aq;

    aq.welcome_to_swim(new Shark);
    aq.welcome_to_swim(new Crocodile);
    aq.welcome_to_swim(new Tilapia);


    return 0;
}


/*

..practice_fish...
..shark 在游泳...
..Crocodile 在游泳...
..Tilapia 在游泳...


*/

