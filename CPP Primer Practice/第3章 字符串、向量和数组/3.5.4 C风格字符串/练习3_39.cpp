/* 练习 3.39：编写一段程序，比较两个 string 对象。
再编写一段程序，比较两个 C风格字符串的内容。*/

/*【出题思路】
由于标准库 string 类定义了关系运算符，所以比较两个 string 对象可以直接使用 <、>、==等；
比较两个C风格字符串则必须使用 cstring 头文件中定义的 strcmp 函数。
*/

// 比较两个 string 对象的程序如下所示：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cout << "Please enter two strings: " << endl;
    cin >> str1 >>str2;

    if (str1 > str2)
        cout << "The first string is greater than the second string." << endl;
    else if (str1 < str2)
        cout << "The first string is smaller than the second string." << endl;
    else
        cout << "The two strings are equal." << endl;
    return 0;
}


// 比较两个 C风格字符串的程序如下所示，其中的分支部分选用了 switch-case 语句，其效果与上一个程序的 if-else 语句非常类似。
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[80], str2[80];
    cout << "PLease enter two strings: " << endl;
    cin >> str1 >> str2;
    // 利用 cstring 头文件中定义的 strcmp 函数比较大小
    auto result = strcmp(str1, str2);
    switch(result)
    {
    case 1:
        cout << "The first string is greater than the second string." << endl;
        break;
    case -1:
        cout << "The first string is smaller than the second string." << endl;
        break;
    case 0:
        cout << "The two strings are equal." << endl;
        break;
    default:
        cout << "Undefined result" << endl;
        break;
    }
    return 0;
}