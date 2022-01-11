/* 练习3.15：改写上题的程序，不过这次读入的是字符串。*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vString;     // 元素类型为 string 的 vector 对象
    string s;                   // 记录用户的输入值
    char cont = 'y';            // 与用户交互，决定是否继续输入
    while (cin >> s)
    {
        vString.push_back(s);   // 向 vector 对象中添加元素
        cout << "Do you wanna continue? (y or n)? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : vString)    // 使用范围 for 循环语句遍历 vString 中的每个元素
        cout << mem << " ";
    cout << endl;
    return 0;
}
/* Output:
hiatus
Do you wanna continue? (y or n)?
y
long
Do you wanna continue? (y or n)?
y
holiday
Do you wanna continue? (y or n)?
n
hiatus long holiday
*/