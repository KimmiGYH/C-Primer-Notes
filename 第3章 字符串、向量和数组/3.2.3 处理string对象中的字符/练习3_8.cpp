/* 练习3.8：分别用 while 循环和传统的 for 循环重写第一题的程序。
你觉得哪种形式更好呢？为什么？ */

/*--------------------------*/

// 使用 范围for循环
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string, including space: " << endl;
    getline(cin, s);    // 读取整行，遇回车符结束
    for (auto &c : s)   // 依次处理字符串中的每一个字符
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}

/*--------------------------*/

// 使用传统 for 循环实现的程序如下：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string, including space: " << endl;
    getline(cin, s);
    for (unsigned int i = 0; i < s.size(); i++)   // 使用 unsigned int i
    {
        s[i] = 'X';
    }
    cout << s << endl;
    return 0;
}

/*--------------------------*/

// 使用 while 循环实现的程序如下：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string, including space: " << endl;
    getline(cin, s);
    int i = 0;
    while(s[i] != '\0') // 编译器在每个字符串的结尾处添加一个空字符(`'\0'`)
    {
        s[i] = 'X';
        ++i;
    }
    cout << s << endl;
    return 0;
}

/*在本例中，我们希望处理字符串中的每一个字符，且无需在意字符的处理顺序，
因此与传统的 while 循环和 for 循环相比，使用范围 for 循环更简洁直观。*/