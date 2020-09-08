#include <iostream>
#include <vector>

using namespace std;

/*
 *  �ɱ�����ĺ���ģ�壬����ʹ��initializer_list
 *
 *  �����ǿɱ�������ǿɱ�����ĺ���ģ�壬�ͼ����� initializer_list ���ɡ�
 */

 //AA
int add1(int a) {
    return a;
}

// BB ���Խ��ܿɱ������
int add2(initializer_list<int> list) {
    // ֱ�Ӵ�ӡԪ��
    for (auto i = list.begin(); i < list.end(); i++) {
        // ����ָ��
        std::cout << "..Ԫ�� = " << *i << "\t";
    }
    return 0;
}

// CC ģ�塣
template <typename  T>
T add3(initializer_list<T> list) {
    int total = 0;
    for (auto i = list.begin(); i < list.end(); i++) {
        total += *i;
    }
    return total;
}

int main() {
    cout << add3({ 1,2,3 }) << endl;
    add2({ 4, 5, 6, 7, 8 });

    return 0;
}


/*

output:


6
..Ԫ�� = 4      ..Ԫ�� = 5      ..Ԫ�� = 6      ..Ԫ�� = 7      ..Ԫ�� = 8

*/
