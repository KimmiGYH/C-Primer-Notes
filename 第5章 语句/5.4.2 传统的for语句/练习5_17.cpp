/*练习 5.17：假设有两个包含整数的vector对象，编写一段程序，检验其中一 个 vector 对象是否是另一个的前缀。
为了实现这一目标，对于两个不等长的 vector 对象，只需挑出长度较短的那个，把它的所有元素和另一个 vector 对象比较即可。
例如如果两个 vector 对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果应该为真。  */

// 【出题思路】：使用 while 循环实现两个 vector 对象的逐元素比较。

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {0,1,1,2};
    vector<int> v2 = {0,1,1,2,3,5,8};
    vector<int> v3 = {3,5,8};
    vector<int> v4 = {3,5,0,0,2,7};

    auto it1 = v1.cbegin();
    auto it2 = v2.cbegin();
    auto it3 = v3.cbegin();
    auto it4 = v4.cbegin();

    while (it1 != v1.cend() && it2 != v2.cend())
    {
        if (*it1 != *it2)
        {
            cout << "v1 和 v2 之间不存在前缀关系" << endl;
            break;
        }
        ++it1;
        ++it2;
    }

    if (it1 == v1.cend())    // 如果 v1 较短
    {
        cout << "v1 是 v2 的前缀" << endl;
    }
    if (it2 == v2.cend())   // 如果 v2 较短
    {
        cout << "v2 是 v1 的前缀" << endl;
    }
    return 0;
}
// Output: 1 是 v2 的前缀

/* 程序的输出结果是：v1 是 v2 的前缀。
如果更新程序使其处理 v3 和 v4，则程序将显示：v3 和 v4 之间不存在前缀关系。*/