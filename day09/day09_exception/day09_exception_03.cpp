
#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *异常
 *      noexcept ：用于表示不会出现异常。
 *          一般出现在拷贝构造和移动构造。
 */

int calc_div(int a, int b) noexcept {   // 表示函数不会出现异常，所以函数有异常就不会上抛

    if (b == 1) {
        throw logic_error("除数不能为1");    // 报错，没有上抛
    }
    return a / b;
}

int main() {
    try {
        calc_div(3, 1);
    }
    catch (logic_error l) { //逻辑错误的异常
        cout << "捕获到逻辑异常" << endl;
    }
    catch (bad_alloc b) { //分配空间出错的异常，内存不够空。
        cout << "捕获申请空间失败的异常" << endl;
    }
    catch (exception e) { //所有的异常都可以捕获。
        cout << "捕获到异常了2" << endl;
        cout << e.what() << endl;
    }
    cout << "这是最后打印的语句" << endl;
    return 0;
}
