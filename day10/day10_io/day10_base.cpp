/*

需求

了解 进制输出的用法

*/


#include <iostream>
//#include <memory>
//#include <vector>
using  namespace std;
/*
 * 基本输出
 */
int main() {

    //1. 输出bool
    bool flag = false;
    bool flag2 = true;
    cout << boolalpha << "flag = " << flag << endl;  //打印true | false;
    cout << noboolalpha << "flag2 = " << flag2 << endl; //换成打印 1 | 0

    //2. 输出十进制 、 八进制、十六进制
    int num = 2309;

    cout << showbase << "十进制 : " << dec << num << endl;  // 9
    cout << "八进制 : " << oct << num << endl; // A 11
    cout << "十六进制 : " << hex << num << endl; // B 9
    cout << noshowbase;

    cout << dec << 18 << endl;


    return 0;
}


/*

flag = false
flag2 = 1
十进制 : 2309
八进制 : 04405
十六进制 : 0x905
18

*/
