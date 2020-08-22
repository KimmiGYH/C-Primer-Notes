/* 练习6.6：说明形参、局部变量以及局部静态变量的区别。
编写一个函数，同时用到这三种形式。*/

/*【出题思路】理解局部变量的含义，理解自动对象的创建和销毁机制，弄清楚我们为什么需要局部静态变量，应该如何使用局部静态变量。

形参和定义在函数体内部的变量统称为局部变量，它们对函数而言是局部的， 仅在函数的作用域内可见。
函数体内的局部变量又分为普通局部变量和静态局部变量，
对于形参和普通局部变量来说，当函数的控制路径经过变量定义语句时创建该对象，
当到达定义所在的块末尾时销毁它。
我们把只存在于块执行期间的对象称为 自动对象。
这几个概念的区别是： 
- 形参是一种自动对象，函数开始时为形参申请内存空间，我们用调用函数时 提供的实参初始化形参对应的自动对象。 
- 普通变量对应的自动对象也容易理解，我们在定义该变量的语句处创建自动对象，如果定义语句提供了初始值，则用该值初始化；
  否则，执行默认初始化。当该变量所在的块结束后，变量失效。
- 局部静态变量比较特殊，它的生命周期贯穿函数调用及之后的时间．局部静态变量对应的对象称为局部静态对象，它的生命周期从定义语句处开始，直到程序结束才终止。
*/

#include <iostream>
using namespace std;

double myADD(double val1, double val2)  // val1 和 val2 是形参
{
    double result = val1 + val2;    // result 是普通局部变量
    static unsigned iCnt = 0;       // iCnt 是静态局部变量
    ++iCnt;
    cout << "This function has been called: " << iCnt << " times." << endl;
    return result;
}

int main()
{
    double num1, num2;
    cout << "Please enter two numbers: ";
    while (cin >> num1 >> num2)
    {
        cout << num1 << " and " << num2 << " sum result is: " 
             << myADD(num1, num2) << endl;
    }
    return 0;
}

