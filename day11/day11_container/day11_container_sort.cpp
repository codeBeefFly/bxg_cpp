#include <iostream>
/*

A() {
  // output P
}

B(fn) {
  fn();  // B knows only fn, not A
         // B treats fn as a variable
}

B(A);  // B called at T
       // B calling fn() (i.e. calling A())



���� A ��Ϊ���� fn ���� ���� B
B ��֪�� A �Ĵ��ڣ�ֻ֪�� fn
B �� fn ����һ�����뺯���ľֲ���������
���� B ͨ�� fn() ���﷨������ ���� A
B �� ����ʱ�� T������ fn
B ���� fn ��������Ϊ�˵õ���� P


*/



#include <vector>
#include <algorithm>

using  namespace std;

//�ص���������sort�ڲ����ã�����Ҫ�󷵻ؽ����
bool mysort(const string & a, const string & b) {
    return a.size() < b.size();
}


int main() {

    vector<string> vv{ "ab","bc","aa","abc","ac" };

    //Ĭ��ʹ����ĸ��˳������ �������ǹ涨�������㷨����
    sort(vv.begin(), vv.end(), mysort);

    //�������һ��������һ������ô�ٰ���ĸ��˳�����򣬿���ʹ��stable_sort
    stable_sort(vv.begin(), vv.end(), mysort);


    for (string ss : vv) {
        cout << "===>" << ss << endl;
    }
    return 0;
}



/*

output


===>ab
===>bc
===>aa
===>ac
===>abc

*/