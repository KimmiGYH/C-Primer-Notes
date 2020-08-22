/* 练习6.23：参考本节介绍的几个 print 函数，根据理解编写你自己的版本。
依次调用每个函数使其输入下面定义的 i 和 j：
    int i = 0, j[2] = {0, 1};

【出题思路】根据参数的不同，为 print 函数设计几个版本。版本的区别主要体现在对指针参数的管理方式不同。
第一个版本不控制指针的边界，
第二个版本由调用者指定数组的维度，
第三个版本新规定的 begin 和 end 函数限定数组边界。
*/


#include <iostream>
using namespace std;

// 参数是常量整型指针
void print1(const int *p)
{
    cout << *p << endl;
}

// 参数有两个，分别是常量整型指针和数组的容量
void print2(const int *p, const int sz)
{
    int i = 0;
    while(i != sz)
    {
        cout << *p++ << endl;
        ++i;
    }
}

// 参数有两个，分别是数组的首尾边界
void print3(const int *b, const int *e)
{
    for (auto q = b; q != e; ++q)
        cout << *q << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print1(&i);     // 0
    print1(j);      // 0
    print2(&i, 1);  // 0
    // 计算得到数组 j 的容量
    cout << (sizeof(j)/sizeof(*j)) << endl; // 2
    print2(j, sizeof(j)/sizeof(*j)); // 0, 1
    auto b = begin(j);
    auto e = end(j);
    print3(b, e);   // 0, 1
    return 0;
}