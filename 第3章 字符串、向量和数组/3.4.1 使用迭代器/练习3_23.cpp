/* 练习3.23：编写一段程序，创建一个含有 10 个整数的 vector 对象，然后使用迭代器将所有元素的值都变成原来的两倍。
输出 vector 对象的内容，检验程序是否正确。*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vInt;
    srand((unsigned)time(NULL));    // 生成随机数种子
    for (int i = 0; i < 10; i++)
    {
        vInt.push_back(rand() % 1000);  // 每次循环生成一个1000以内的随机数并添加到vInt中
    }

    cout << "The 10 randomly generated numbers are: " << endl;
    // 利用常量迭代器读取原始数据
    for(auto it = vInt.cbegin(); it != vInt.cend(); it++)
    {
        cout << *it << " ";     // 输出当前数字
    }
    cout << endl;

    cout << "The 10 doubled numbers are: " << endl;
    // 利用非常量迭代器修改 vInt 内容并输出
    for (auto it = vInt.begin(); it != vInt.end(); it++)
    {
        *it *= 2;
        cout << *it << " ";     // 输出当前数字
    }
    cout << endl;

    return 0;
}