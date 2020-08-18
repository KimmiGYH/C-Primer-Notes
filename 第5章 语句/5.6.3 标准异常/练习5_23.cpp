/* 练习5.23：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。

【出题思路】对于整数除法来说，我们必须检查除数是否为 0.在这个版本的程序中，暂时不使用 try-catch 机制，而是直接输出错误信息。

*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter the dividend and the divisor: " << endl;
    int ival1, ival2;
    cin >> ival1 >> ival2;
    if (ival2 == 0) 
    {
        cout << "The divisor can't be 0." << endl;
        return -1;
    }
    cout << "The result is: " << ival1 / ival2 << endl;
    return 0;
}