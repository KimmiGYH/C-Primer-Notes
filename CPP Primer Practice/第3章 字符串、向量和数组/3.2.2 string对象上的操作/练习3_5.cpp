/* 练习3.5： 编写人一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。
然后修改上述程序，用空格把输入的多个字符串分隔开来。*/

// 连续多个字符串的程序如下：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char cont = 'y';
    string s, result;
    cout << "Enter the first string: " << endl;
    while (cin >> s)
    {
        result += s;    // 区别所在
        
        cout << "Do you wanna continue (y or n)? " << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "Enter next string: " << endl;
        else
            break;
    }
    cout << "The contacted string is: " << result << endl;
    return 0;
}


// 连接多个字符串并以空格分隔的程序如下：
#include <iostream>
#include <string>

int main()
{
    char cont = 'y';
    string s, result;
    cout << "Enter the first string: " << endl;
    while (cin >> s)
    {
        if (!result.size()) // 第一个拼接的字符串之前不加空格
            result += s;
        else                // 之后拼接的每个字符串之前加一个空格
            result = result + " " + s;
        
        cout << "Do you wanna continue (y or n)? " << endl;
        cin >> cont;
        if (cont == 'y' || cont == 'Y')
            cout << "Enter the next string: " << endl;
        else
            break;
    }
    cout << "The contacted string is: " << result << endl;
    return 0;
}