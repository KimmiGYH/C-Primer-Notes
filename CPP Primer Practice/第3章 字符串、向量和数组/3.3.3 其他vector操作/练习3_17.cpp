/* 练习 3.17：从 cin 读入一组词并把它们存入一个 vector 对象，
然后设法把所有词都改写为大写形式。
输出改变后的结果，每个词占一行。*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vString;
    string word;
    char cont = 'y';
    cout << "Enter the first word: " << endl;
    while (cin >> word)
    {
        vString.push_back(word);
        cout << "Do you wanna continue (y or n)? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
        cout << "Please enter the next word: " << endl;
    }
    cout << "The converted result is: " << endl;
    for (auto &mem : vString) { // 使用范围for循环语句遍历vString中的每个元素
        for (auto &c : mem)     // 使用范围for循环语句遍历mem中的每个字符
            c = toupper(c);     // 改写为大写字母形式
        cout << mem << endl;
    }
    return 0;
}

/* Output:
Enter the first word: 
Meow
Do you wanna continue (y or n)? 
y
Please enter the next word: 
Alex
Do you wanna continue (y or n)? 
Y
Please enter the next word: 
Bordora
Do you wanna continue (y or n)? 
n
The converted result is:
MEOW
ALEX
BORDORA
*/