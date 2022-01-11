/* 练习5.25：修改上一题的程序，使用 try 语句块去捕获异常。
catch 子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行 try 语句块的内容。

【出题思路】使用 try-catch 结构实现完整的异常处理机制。
*/

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << "Please enter the dividend and the divisor: " << endl;
    int ival1, ival2;
    while (cin >> ival1 >> ival2)
    {
        try
        {
            if (ival2 == 0)
            {
                throw runtime_error("The divisor can't be 0.");
            }
            cout << "The result is: " << ival1 / ival2 << endl;
        }
        catch(runtime_error err)
        {
            cout << err.what() << endl;
            cout << "Do you want to continue (y or n)? ";
            char ch;
            cin >> ch;
            if (ch != 'y' && ch != 'Y')
                break;
        }
    }
    return 0;
}
