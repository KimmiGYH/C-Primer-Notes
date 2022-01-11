/*
**练习 3.3：请说明 `string` 类的输入运算符和 `getline` 函数分别是如何处理空白字符的。**

- 标准库 string 的输入运算符自动忽略字符串开头的空白（包括空格符、换行符、制表符等），从第一个真正的字符开始读起，直到遇见下一处空白为止。
- 如果希望在最终的字符串中保留输入时的空白符，应该使用 getline 函数代替原来的 `>>`运算符，`getline`从给定的输入流中读取数据，直到遇到**换行符**为止，此时换行符也被读取进来，但是并不存储在最后的字符串中。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word, line;
    cout << "Plese choose the way to read string: 1 Read words verbatim 2 Read a whole line" << endl;
    char ch;
    cin >> ch;
    if (ch == '1')
    {
        cout << "Please enter a string:     Welcome to C++ family!     " << endl;
        cin >> word;
        cout << "The effective strings are: " << endl;
        cout << word << endl;
        return 0;
    }

    // 清空输入缓冲区
    cin.clear();
    cin.sync();
    if (ch == '2')
    {
        cout << "Please enter the string:     Welcome to C++ family!     " << endl;
        getline(cin, line);
        cout << "The effective strings are: " << end;
        cout << line << endl;
        return 0;
    }
    cout << "Your entrance has an error!";
    return -1;
}

/* 在上述程序中，如果用户输入 1， 则输出是 Welcome，此时字符串开头打空格和第一个单词之后的所有内容都被忽略掉了；
如果用户输入 2，则输出是 Welcome to C++ family!，字符串开头、中间、结尾的空格都保留了下来。
*/
