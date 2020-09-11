#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  基本输入输出  ????
 *
 */
int main() {


    char c11[]{ 'a' };
    *(c11 + 1) = 'b';
    *(c11 + 2) = 'c';
    *(c11 + 3) = 'd';

    /*a

        //1. 输出浮点数
        double pi = 3.14159265312123124532;

        //cout .precision(80);
        cout<<setprecision(15) <<"pi -= " << pi <<endl;

        //2. 禁止忽而空白符
        char c ;
        cin >> noskipws;
        while(cin >> c) {
            cout <<"c =" << c <<endl;
        }
        cin >> skipws;
    */

    return 0;
}
