#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>  //���ļ�������ص�ͷ

using namespace std;

/*
 *  �ļ��Ķ�ȡ��
 *      ��ȡ��������(��)�� ��, ���
 */
int main() {

    std::cout << "..in day10_io_basic_fread_matrix_dot_ex...\n";


    /*
        string line1 = "12, 6, 2, 10.5";
        // ���տո��и  12    6,    2,   10.5
        //double data = 12
        //double data = 6
        stringstream ss1(line1); //1, 6, 2, 10.5
    */



    //������һ������
 /*   cout << "peek: " << ss1.peek() <<endl;
    ss1.ignore();
    cout << "peek: " << ss1.peek() <<endl;
*/
/*   double data ;
   while(ss1 >> data){
       if(ss1.peek() == ',' || ss1.peek() == ' '){
           ss1.ignore();
       }
       cout << "data =" << data<<endl;
   }
*/


    cout << "***************" << endl;

    //1. ���ļ�
    //fstream fs("../01_io/matrix2");

    // ��������ʼ���ļ���
    std::string relative_path = "..\\day10_io\\test_file_matrix.txt";

    std::fstream fs(relative_path, std::ios::in);

    //2 . ���ļ�
    if (fs.is_open()) {
        string line;

        vector< vector<double> > matrix_vector;

        //ѭ����ȡÿһ�� ��
        while (getline(fs, line)) {
            cout << "line =" << line << endl;
            //����һ�о���һ��vector
            vector<double> line_vector;

            //����һ�е����ݽ���ss
            stringstream ss(line); //1, 6, 2, 10.5

            //���տո��и�ÿһ�е����֣�һ���ܹ���4�����֣��и����֮�󣬴洢���е�vector����ȥ��
            double data = 0;
            while (ss >> data) {
                //cout << "data=" <<data <<endl;

                //ss.peek() ���ص����ַ���ASCIIֵ
                if (ss.peek() == ',' || ss.peek() == ' ') {
                    //��ss��Ҫȥ����, �Ϳո�
                    ss.ignore();
                }


                line_vector.push_back(data);
            }

            //��ÿһ�е�vector�����ܵ�vectorȥ��
            matrix_vector.push_back(line_vector);
        }



        for (vector<double> vd : matrix_vector) {
            for (double d : vd) {
                cout << d << "\t";
            }

            cout << endl;
        }







    }



    return 0;
}


/*

output


..in day10_io_basic_fread_matrix_dot_ex...
***************
line =1�� 2�� 3�� 4
line =5�� 6�� 7�� 8
line =9�� 10�� 11.5�� 12
1
5
9


*/
