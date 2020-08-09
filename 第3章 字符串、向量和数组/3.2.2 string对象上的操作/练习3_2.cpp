/* 练习3.2：编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。

【思路】：常用的字符串读取方式有两种：
(1) 使用`getline`函数一次读入一整行；
行的结束标识是回车符，如果一开始输入的就是回车符，则`getline`直接结束本次读取，所得的结果是一个空字符串
while (getline(cin, line))

(2) 使用`cin`一次读入一个词，遇空白停止。
while (cin >> word)
*/

// (1) 使用 getline 一次读入一整行，遇回车结束
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cout << "Please enter a string including space key: " << endl;
    while (getline(cin, line))
        cout << line << endl;
    return 0;
}

// (2) 使用 cin 一次读入一个词，遇空白结束
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cout << "Please enter a word, without space: " << endl;
    while (cin >> word)
        cout << word << endl;
    return 0;
}