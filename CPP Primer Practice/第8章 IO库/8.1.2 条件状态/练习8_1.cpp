/*练习8.1：编写函数，接受一个 istream& 参数，返回值类型也是 istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输 出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。*/

/*【出题思路】本题是流的输入输出的基本练习。此外，本节介绍了流的条件状态，本题还对流的结束状态（本题是遇到文件结束符）、错误状态和数据错误状态（例如要求输入整数时输入了字符）的检测和处理进行了练习。*/

#include <iostream>
#include <stdexcept>
using namespace std;

istream & f(istream & in)
{
    int v;
    while (in >> v, !in.eof()) { // 直到遇到文件结束符才停止读取
        if(in.bad())
            throw runtime_error("IO stream error");
        if (in.fail()) {
            cerr << "Data error, please try again: " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "Please enter some integers, press Ctrl+Z to end." << endl;
    f(cin);
    return 0;
}

/* Output:
Please enter some integers, press Ctrl+Z to end.
1 2 3
1
2
3
7.6
7
Data error, please try again: 
a
Data error, please try again:
4
4
^Z
*/