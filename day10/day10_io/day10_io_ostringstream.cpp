/*

我们需要格式化一个字符串，但通常并不知道需要多大的缓冲区。
为了保险常常申请大量的缓冲区以防止缓冲区过小造成字符串无法全部存储。
这时我们可以考虑使用`ostringstream`类，
该类能够根据内容自动分配内存，并且其对内存的管理也是相当的到位。

*/


#include <iostream>
#include <sstream>

using namespace std;

/*
 *  字符串的输出流
 *
 */
int main() {

    string data = "我是中国人";
    int a = 3;
    double pi = 3.14;


    ostringstream os;
    os << data << a << " : pi << " << pi << endl;
    string result = os.str();
    cout << "result= " << result << endl;

     string pi2 = "3.1415926";
    //double pi3 =(double) pi2;
     ostringstream  os2;
     os2 << pi2 << endl;
     cout << "result2 = " << os2.str();

     //double pi4 ;
     //os2 >> pi4;


    return 0;
}

/*

result= 我是中国人3 : pi << 3.14

result2 = 3.1415926

*/