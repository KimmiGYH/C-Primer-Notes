/* 练习6.13：假设 T 是某种类型的名字，说明以下两个函数声明的区别：
一个是 void f(T)，另一个是 void f(&T)。*/

#include <iostream>
using namespace std;

void a(int);    // 传值参数
void b(int &);  // 传引用参数

int main()
{
    int s = 0, t = 10;
    a(s);
    cout << s << endl;
    b(t);
    cout << t << endl;
    return 0;
}

void a(int i)
{
    ++i;
    cout << i << endl;
}

void b(int &j)
{
    ++j;
    cout << j << endl;
}

/*Output:
1
0
11
11
*/