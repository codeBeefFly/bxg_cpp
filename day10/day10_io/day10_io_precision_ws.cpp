/*

需求：

练习
1. 设置浮点数精度
2. 设置如何操作 空白符


默认情况下，获取键盘的输入内容时会自动忽略空白符（空格符 、制表符、换行符、回车符） ， 
若不想忽略可以使用 `noskipws` 禁止忽略空白符， 使用 `skipws` 还原忽略即可。

*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  基本输入输出
 *
 */
int main() {


    //1. 输出浮点数
    double pi = 3.14159265312123124532;

    //cout .precision(80);
    cout << setprecision(15) << "pi -= " << pi << endl;

    //2. 禁止忽略空白符
    char c;
    //cin >> noskipws;
    //while (cin >> c) {
    //    if (c == 'q') break;
    //    cout << "c =" << c << endl;
    //}
    
    cin >> skipws;
    while (cin >> c) {
        if (c == 'q') break;
        cout << "c =" << c << endl;
    }

    return 0;
}


/*

output

pi -= 3.14159265312123
a bd hello, !123
c =a
c =
c =b
c =d
c =
c =h
c =e
c =l
c =l
c =o
c =,
c =
c =!
c =1
c =2
c =3
c =

q

q


pi -= 3.14159265312123
a bd h191,23
c =a
c =b
c =d
c =h
c =1
c =9
c =1
c =,
c =2
c =3


*/