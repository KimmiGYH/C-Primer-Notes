/* 练习6.50：对于下面的每一个调用列出可行函数。
其中哪个函数是最佳匹配？
如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？

(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
*/


/* 练习6.51：编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一个练习的答案。*/

#include <iostream>
using namespace std;

void f()
{
    cout << "The function doesn't have parameters." << endl;
}
void f(int)
{
    cout << "The function has one parameter." << endl;
}
void f(int, int)
{
    cout << "The function has two integer parameters." << endl;
}
void f(double a, double b = 3.14)
{
    cout << "The function has two double parameters." << endl;
}

int main()
{
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}

/*Output:
error: call of overloaded 'f(double, int)' is ambiguous
The function has one parameter.
The function has two integer parameters.
The function has two double parameters.
*/