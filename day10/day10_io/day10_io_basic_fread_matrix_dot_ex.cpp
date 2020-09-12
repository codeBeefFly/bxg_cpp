#include <iostream>
#include <vector>

#include <sstream>
#include <fstream>  //和文件操作相关的头

using namespace std;

/*
 *  文件的读取。
 *      读取矩阵数据(二)， 有, 间隔
 */
int main() {

    std::cout << "..in day10_io_basic_fread_matrix_dot_ex...\n";


    /*
        string line1 = "12, 6, 2, 10.5";
        // 按照空格切割：  12    6,    2,   10.5
        //double data = 12
        //double data = 6
        stringstream ss1(line1); //1, 6, 2, 10.5
    */



    //单独的一个函数
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

    //1. 打开文件
    //fstream fs("../01_io/matrix2");

    // 创建并初始化文件流
    std::string relative_path = "..\\day10_io\\test_file_matrix.txt";

    std::fstream fs(relative_path, std::ios::in);

    //2 . 读文件
    if (fs.is_open()) {
        string line;

        vector< vector<double> > matrix_vector;

        //循环读取每一行 。
        while (getline(fs, line)) {
            cout << "line =" << line << endl;
            //遍历一行就有一个vector
            vector<double> line_vector;

            //把这一行的数据交给ss
            stringstream ss(line); //1, 6, 2, 10.5

            //按照空格切割每一行的数字，一行总共有4个数字，切割出来之后，存储到行的vector容器去。
            double data = 0;
            while (ss >> data) {
                //cout << "data=" <<data <<endl;

                //ss.peek() 返回的是字符的ASCII值
                if (ss.peek() == ',' || ss.peek() == ' ') {
                    //让ss不要去处理, 和空格。
                    ss.ignore();
                }


                line_vector.push_back(data);
            }

            //把每一行的vector丢到总的vector去。
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
line =1， 2， 3， 4
line =5， 6， 7， 8
line =9， 10， 11.5， 12
1
5
9


*/
