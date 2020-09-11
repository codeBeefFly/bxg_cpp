#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 * 异常的捕获
 *
 *      能捕获的异常，实际上也可以让程序还走。
 *      错误， 直接就终止。
 */
 /*
 class teacher{
 public:
     int age ;
     teacher(int age) {

     }
 };

 class stu{

     int age =18; //  int age;  //0
     teacher t;

     //有初始化列表的话。 上面的成员，仅仅是声明而已。
     stu (int age , teacher t): age(age) , t(t){
     }

     stu (int age , teacher t){
         age = age ;
         t = t ;
     }
     int a = 3 ;
     int b = 4;
     a = b;  //这是初始化吗？不是，这句话是赋值。

 };
 */


int main() {

    int a;

    try {
        vector<int> vi{ 10,20,30 };
        int result = vi.at(30);
        cout << "result =" << result << endl;
    }
    catch (exception e) {       // 可以继续运行
        cout << "角标a越界了" << endl;
    }
    
    
    
    //try {
    //    int a = 3 / 0;
    //    cout << "result = " << a <<endl;
    //}catch (exception e){
    //    cout << "抓到异常了" <<endl;
    //}


    //int a;
    //try {
    //    std::cout << "..in try...\n";
    //    a = 3 / 0;      // 这个异常没有向上抛，所以无法捕获
    //}
    //catch (exception e) {
    //    std::cout << "..in catch...\n";
    //}


    cout << "最后打印的语句！" << endl;
    return 0;
}
