#include <iostream>
#include <vector>

using namespace std;


/*
 * ������
 *
 *  end();
 */

int main() {

    vector<int> vi{ 10,20,30,40,50 };

    // __gnu_cxx::__normal_iterator<int*, vector<int>> it =  vi.begin();

    //����һ��������������װ�˵�һ��Ԫ�ص�ָ�롣  ������о��Ļ�����ʵ���Դ��ַ��
    auto begin = vi.begin(); //iterator(this->_M_impl._M_start);
    cout << "begin = " << *begin << endl;

    auto end = vi.end(); // iterator(this->_M_impl._M_finish);
    cout << "end = " << *(end - 1) << endl;


    //����� <  �� ++ ʵ�����ǵ�����iterator���������������
    //operator< ()  operator++()
    //�����κ��������涼����  < ����  �п������� !=
    for (auto i = vi.begin(); i != vi.end(); i++) {
        cout << " i = " << *i << endl;
        if (*i == 30) {
            //����Ҫ������������Ҫָ�롣
            vi.erase(i);       // ��bug

        }
    }


    return 0;
}


/*

output

begin = 10
end = 50
 i = 10
 i = 20
 i = 30

*/
