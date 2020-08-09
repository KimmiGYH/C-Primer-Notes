/* 练习3.10：编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。*/

// 思路一：利用范围for语句遍历字符串，逐个输出非标点字符：

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string including punctuations: " << endl;
    getline(cin, s);
    for (auto c : s)
    {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    return 0;
}


// 思路二：利用普通 for 循环遍历字符串，通过下标执行随机访问，把非标点字符拼接成一个新串后输出：

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s, result;
    cout << "Please enter a string including punctuations: " << endl;
    for (decltype(s.size()) i = 0; i < s.size(); i++)
    {
        if (!ispunct(s[i]))
            result += s[i];
    }
    cout << result << endl;
    return 0;
}