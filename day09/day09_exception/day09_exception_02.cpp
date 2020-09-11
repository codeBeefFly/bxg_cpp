/*

throw

try catch 语法


fun(){
    throw exception("excetpion type x");
}

main(){

    try{
        fun();
    }
    catch(exception e){
        cout << e.what() << "\n";   // e.what() 打印 exception 中的提示
    }

}


*/


#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *异常的处理：
 *      抛出异常。
 */


int calc_div(int a, int b) {
    if (b == 0) {
        //抛出异常。throw 抛
        //throw logic_error("除数不能为0！");   // 有些异常需要先抛出，再用 try catch 捕获
        throw exception("除数不能为0！");         // 这个写法太牛逼了
    }
    cout << "函数内部：抛出异常之后" << endl;
    return a / b;
}
int main() {

    try {
        calc_div(3, 0);
    }
    catch (bad_alloc e) { //这里可以写logic_error 也可以写 exectpion
        cout << e.what() << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }


    cout << "这是最后打印的语句" << endl;
    return 0;

}


/*

output

除数不能为0！
这是最后打印的语句

*/

