/* 练习 3.28：下列数组中元素的值是什么？ */

// string sa[10];
// int ia[10];
// int main()
// {
//     string sa2[10];
//     int ia[10];
// }

// 出题思路
/*
考查数组默认初始化的几种不同情况，如全局变量和局部变量的区别、内置类型和复合类型的区别。

对于 string 类型的数组来说，因为 string 类本身接受五参数的初始化方式，所以不论数组定义在函数内还是函数外都被默认初始化为空串。

对于内置类型 int 来说，数组 ia 定义在所有函数体之外，ia 的所有元素默认初始化为 0；
而数组 ia2 定义在 main 函数的内部，将不被初始化，如果程序试图拷贝或输出未初始化的变量，将遇到未定义的奇异值。
*/


#include <iostream>

using namespace std;

// 定义在全局作用域中的数组
string sa[10];
int ia[10];

int main()
{
    // 定义在局部作用域中的数组
    string sa2[10];
    int ia2[10];
    
    for (auto c : sa)
        cout << c << " ";
    cout << endl;

    for (auto c : ia)
        cout << c << " ";
    cout << endl;

    for (auto c : sa2)
        cout << c << " ";
    cout << endl;

    for (auto c : ia2)
        cout << c << " ";
    return 0;
}
