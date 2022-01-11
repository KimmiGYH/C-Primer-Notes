/* 练习6.5：编写一个函数输出其实参的绝对值。*/

#include <iostream>
#include <cmath>
using namespace std;

// 第一个函数通过 if-else 语句计算绝对值
double myABS(double val)
{
    if (val < 0)
        return val * -1;
    else
        return val;
}

// 第二函数调用 cmath 头文件的 abs 函数计算绝对值
double myABS2(double val)
{
    return abs(val);
}

int main()
{
    double num;
    cout << "Please enter a number: ";
    cin >> num;
    cout << num <<"'s absolute value is: " << myABS(num) << endl;
    cout << num <<"'s absolute value is: " << myABS2(num) << endl;
    return 0;
}