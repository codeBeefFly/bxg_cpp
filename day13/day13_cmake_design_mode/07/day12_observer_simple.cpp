#include <iostream>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;

//观察者：如果被观察者的状态发生了改变，那么这边需要收到通知。
class observer {

public:
    //用于接收通知。
    void update() {
        cout << "观察者收到通知了" << endl;
    }
};

//被观察者
//被观察者的状态发生了改变，那么就需要去通知观察者
class subject {
    //被观察需要知道现在被谁观察者。
    observer ob;
public:
    //通过函数来设置，到底subject被谁观察
    void setObserver(observer ob) {
        this->ob = ob;
    }

    //以后状态到了，就调用这个函数，用来通知观察者。
    void notify() {
        cout << "被观察者达到了状态，要去通知观察者了" << endl;
        ob.update();
    }
};

int main() {
    observer ob;
    subject sj;

    //设置目标对象被谁观察，以便一会出现了状态，就通知观察者
    sj.setObserver(ob);


    //模拟一下：遍历， 打印到了5，就等于目标对象达到了某种状态。
    for (int i = 0; i < 20; ++i) {
        cout << " i ===" << i << endl;
        if (i == 5) {
            //谁观察我这个对象，谁就能收到通知。
            sj.notify();
        }

        Sleep(1000);
    }


    return 0;
}

/*

output:


...getInstance 函数线程:: 32544
...创建对象后睡眠1000ms...
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...
...async_bank instance address: 00000182000E5190
...getInstance 函数线程:: 28652
...返回对象前睡眠3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance 函数线程:: 32544
...返回对象前睡眠3000ms...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_designMode_singleton_lazy_problem_2_self.exe (process 32992) exited with code -1073741510.
Press any key to close this window . . .


*/