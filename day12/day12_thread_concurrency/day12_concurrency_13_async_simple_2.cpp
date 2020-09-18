#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <future>

using namespace std;

/*
 * async 的启动策略
 *
 *  async的作用：
 *      如果以后有一部分复杂的逻辑，或者是运算的功能，
 *      并且等它执行结束之后，还想拿到返回值
 *      又不想让它干扰主线程的向下运行，那么可以使用async函数来实现。
 *
 *
 */

int add(int a, int b) {
    cout << "函数的线程id = " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "add函数打印了：" << i << endl;
        Sleep(1000);
    }
    return a + b;
}



int main() {

    //或运算
    cout << (1 | 2) << endl;
    cout << "main的线程id = " << this_thread::get_id() << endl;

    /*
     * enum class launch{
        async = 1,
        deferred = 2
      }
     * 默认的启动策略是：  launch::async|launch::deferred   1 | 2
     * 默认启动策略是3 ： 在主线程里面执行， 然后主线程还得阻塞。
     *
     * launch::async ： 会开启子线程
     * launch::deferred ： 不会开启子线程，并且子线程运行的函数还会延迟执行
     *      延迟到什么时候呢？延迟到： get函数的调用。
     */
      //future<int> f = async(launch::async|launch::deferred, add , 3,4 );
    //future<int> f = async(launch::async, add, 3, 4);
    future<int> f = async(launch::deferred, add , 3,4 );

    for (int i = 0; i < 10; ++i) {
        cout << "main::函数打印了--->：" << i << endl;
        Sleep(500);
    }
    cout << "async之后~~ " << endl;
    cout << "async之后~~ " << endl;
    cout << "async之后~~ " << endl;
    cout << "async之后~~ " << endl;

    // 使用 launch::deferred 模式后，不会另外开辟子线程，只有主线程，
    //这个函数调用绑定的函数，在主线程上
    //在这之前，主线程运行
    cout << "结果：" << f.get() << endl;   


    return 0;
}

/*

output:     launch::async | launch::deferred

3
main的线程id = 33040
main::函数打印了--->：0
函数的线程id = 30624
add函数打印了：0
main::函数打印了--->：1
add函数打印了：1
main::函数打印了--->：2
main::函数打印了--->：3
add函数打印了：2
main::函数打印了--->：4
main::函数打印了--->：5
add函数打印了：3
main::函数打印了--->：6
main::函数打印了--->：7
add函数打印了：4
main::函数打印了--->：8
main::函数打印了--->：9
add函数打印了：5
async之后~~
async之后~~
async之后~~
async之后~~
add函数打印了：6
add函数打印了：7
add函数打印了：8
add函数打印了：9
结果：7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 24480) exited with code 0.
Press any key to close this window . . .



*/

/*

output:     launch::async

3
main的线程id = 22696
main::函数打印了--->：0
函数的线程id = 11340
add函数打印了：0
main::函数打印了--->：1
add函数打印了：1
main::函数打印了--->：2
main::函数打印了--->：3
add函数打印了：2
main::函数打印了--->：4
main::函数打印了--->：5
add函数打印了：3
main::函数打印了--->：6
main::函数打印了--->：7
add函数打印了：4
main::函数打印了--->：8
main::函数打印了--->：9
add函数打印了：5
async之后~~
async之后~~
async之后~~
async之后~~
add函数打印了：6
add函数打印了：7
add函数打印了：8
add函数打印了：9
结果：7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 12612) exited with code 0.
Press any key to close this window . . .



*/

/*

output:         launch::deferred

3
main的线程id = 30104
main::函数打印了--->：0
main::函数打印了--->：1
main::函数打印了--->：2
main::函数打印了--->：3
main::函数打印了--->：4
main::函数打印了--->：5
main::函数打印了--->：6
main::函数打印了--->：7
main::函数打印了--->：8
main::函数打印了--->：9
async之后~~
async之后~~
async之后~~
async之后~~
函数的线程id = 30104
add函数打印了：0
add函数打印了：1
add函数打印了：2
add函数打印了：3
add函数打印了：4
add函数打印了：5
add函数打印了：6
add函数打印了：7
add函数打印了：8
add函数打印了：9
结果：7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 25248) exited with code 0.
Press any key to close this window . . .


*/
