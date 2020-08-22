/* 练习6.47：改写练习中使用递归输出 vector 内容的程序，
使其有条件地输出与执行过程有关的信息。
例如，每次调用时输出 vector 对象的大小。
分别在打开和关闭调试器的情况下编译并执行这个程序。*/

#include <iostream>
#include <vector>
using namespace std;

/* 【出题思路】考查如何在程序中打开和关闭调试器

打开调试器时，每次递归条用 print 函数都会输出“vector对象的大小是：8”；
关闭调试器时，程序只输出 vector 对象的内容，不再输出其大小。*/

// 递归函数输出 vector<int> 的内容
void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();
    // 设置在此处输出调试信息
    #ifndef NDEBUG
    cout << "The size of vector object is: " << sz << endl;
    #endif // NDEBUG

    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    return 0;
}

/*Output:
The size of vector object is: 8
1
The size of vector object is: 8
3
The size of vector object is: 8
5
The size of vector object is: 8
7
The size of vector object is: 8
9
The size of vector object is: 8
11
The size of vector object is: 8
13
The size of vector object is: 8
15
The size of vector object is: 8
*/

/*-------------------------------------------------*/

/* 练习6.34：编写一个递归函数，输出 vector 对象的内容。*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> vInt, unsigned index)
{
    unsigned sz = vInt.size();
    if (!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    return 0;
}

/* Output:
1
3
5
7
9
11
13
15
*/