/* 练习4.21：编写一段程序，使用条件运算符从 vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vInt;
    const int sz = 10;              // 使用 sz 作为数组的维度
    srand( (unsigned) time (NULL)); // 生成随机数种子

    // 使用普通 for 循环为数组赋初值
    cout << "The inital value of the array is: " << endl;
    for (int i = 0; i != sz; ++i)
    {
        vInt.push_back(rand() % 100);   // 生成 100 以内的随机数
        cout << vInt[i] << " ";         // 使用下标运算符输出数组内容
    }
    cout << endl;

    // 使用范围 for 循环把数组中的奇数翻倍
    for (auto &val : vInt)
        val = (val % 2 != 0) ? val*2 : val; // 条件表达式
    
    // 使用范围for循环和迭代器输出数组的当前值
    cout << "The adjusted array is: " << endl;
    for (auto it = vInt.cbegin(); it != vInt.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
