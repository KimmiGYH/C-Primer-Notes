/* 练习6.17：编写一个函数，判断 string 对象中是否含有大写字母。
编写另一个函数，把 string 对象全都改成小写形式。
在这两个函数中你使用的形参类型相同吗？为什么？*/

#include <iostream>
#include <string>
using namespace std;

bool HasUpper(const string &str)    // 判断字符串是否含有大写字母
{
    for (auto c : str)
        if (isupper(c))
            return true;
    return false;
}


void ChangeToLower(string &str)     // 把字符串中的所有大写字母转成小写
{
    for (auto &c : str)
        c = tolower(c);
}

int main()
{
    cout << "Please enter a string: " << endl;
    string str;
    cin >> str;
    if (HasUpper(str))
    {
        ChangeToLower(str);
        cout << "The converted string is: " << str << endl;
    }
    else
        cout << "The string doesn't have capital letter, no need to convert. " << endl;
    return 0;
} 