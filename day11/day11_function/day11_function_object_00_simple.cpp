/*

需求：
函数对象

1. 函数指针
int add(int, int)

int (*p_add)(int, int) = add;
p_add(3, 4);


2. function 接收全局函数 头 <functional>

void print(int a, string b);

function<返回类型 (参数类型, ...)> function对象 = 函数名;


3, function 接收 lambda 

function<返回类型 (参数类型, ...)> function对象 = [](变量类型 变量, ...){ return ...; };


4. 接收静态成员函数

class Stu{
public:
	static int run(string name, int age);
}

function<int (string, int)> f = stu::run;


5. 接收成员函数

class Stu{
public:
	int run(string name, int age);

}


function<int (Stu, string, age)> f1 = &Stu::run;	// &-取地址	// 第一个参数是类对象
function<int (Stu&, string, age)> f1 = &Stu::run;	// 第一个参数是类对象引用
function<int (Stu*, string, age)> f1 = &Stu::run;	// 第一个参数是类对象指针

*/



/*

两种函数的调用


除了能使用函数指针来调用函数之外，其实也可以声明一个`function`的对象，
接收某一个函数，直接调用function的对象，也等同于调用函数。

*/

#include <iostream>
#include <functional>

using namespace std;

/*
 * function
 */

int add(int a, int b) {
    return a + b;
}

void sayHi() {
    cout << "你好世界" << endl;
}

int main() {

    //直接调用
    cout << add(3, 4) << endl;

    //函数指针方式调用
    int(*padd)(int, int) = add;
    cout << padd(3, 4) << endl;


    //<> 用于修饰函数的返回值和函数的参数
    // 第一个int是函数的返回值
    //() 用于表示函数的参数， 参数有两个，都是int类型。
    function <int(int, int)>f2 = add;


    function<int(int, int)> f = add;
    cout << f(3, 4) << endl;

    //无参，无返回值，也要带上() 和 void
    void (*psayHi)() = sayHi;
    function<void()> f3 = sayHi;



    return 0;
}

/*

output


7
7
7

*/