#include <iostream>
#include <vector>

using namespace std;

/*
 *  ����
 *      �Զ�������  ��int����
 */
template <typename T>
class my_vector {
    typedef  T value_type;
public:
    //�ڲ�����Ҫ��vector���档
    vector<T> vi;

    my_vector() {}
    my_vector(T a) {
        vi.push_back(a);
    }

    my_vector(initializer_list<T> list) {
        for (auto i = list.begin(); i < list.end(); ++i) {
            vi.push_back(*i);
        }
    }

    size_t size() {
        return vi.size();
    }

    void push_back(value_type&& a) {
        vi.push_back(a);
    }

    void push_back(value_type& a) {
        vi.push_back(a);
    }

    T operator[](size_t i) {
        return vi[i];
    }

    ~my_vector() {}
};


int main() {


    vector<double> v;
    v.push_back(3.4);

    my_vector<string> mv;
    mv.push_back("aa");

    try {
        int a = 3 / 0;
    }
    catch (exception e) {
        std::cout << "..here...\n";
    }

    std::cout << "hello\n" << "...\n";

    return 0;
}
