/* 练习5.24：修改你的程序，使得当第二个数是 0 时抛出异常。
先不要设定 catch 子句，运行程序并真的为除数输入 0，看看会发生什么？*/

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    cout << "Please enter the dividend and the divisor: " << endl;
    int ival1, ival2;
    cin >> ival1 >> ival2;
    if (ival2 == 0)
    {
        // cout << "除数不能为0" << endl;
        // return -1;
        throw runtime_error("The divisor can't be 0.");
    }
    cout << "The result is: " << ival1 / ival2 << endl;
    return 0;
}

/*
3 0
terminate called after throwing an instance of 'std::runtime_error'
  what():  The divisor can't be 0.
*/