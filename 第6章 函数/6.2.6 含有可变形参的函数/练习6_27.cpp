/* 练习6.27：编写一个函数，它的参数是 initializer_list<int> 类型的对象，
函数的功能是计算列表中所有元素的和。

【出题思路】掌握 initializer_list 对象的声明和初始化方法，利用 initializer_list 对象设计形参可变的函数。
【解答】注意 iCount 的参数是 initializer_list 对象，在调用该函数时，我们使用了列表初始化的方式生成实参。*/

#include <iostream>
using namespace std;

int iCount(initializer_list<int> il)
{
    int count = 0;
    // 遍历 il 的每一个元素
    for (auto val : il)
        count += val;
    return count;
}

int main()
{
    // 使用列表初始化的方式构建 initializer_list<int> 对象
    // 然后把它作为实参传递给函数 iCount
    cout << "The sum of 1, 6, 9 is: " << iCount({1, 6, 9}) << endl;
    cout << "The sum of 4, 5, 9, 18: " << iCount({4, 5, 9, 18}) << endl;
    cout << "The sum of 10, 10, 10, 10, 10, 10, 10, 10, 10 is: "
         << iCount({10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
    return 0;
}