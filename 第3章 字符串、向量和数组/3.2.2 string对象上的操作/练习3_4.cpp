/* 练习3.4：编写一段程序读入两个字符串，比较其是否相等并输出结果。如果相等，输出较大的那个字符串。
改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。*/


// 比较字符串大小的程序：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Please enter two strings: " << endl;
    cin >> s1 >> s2;
    if (s1 == s2)
        cout << " The two strings are of same length." << endl;
    else if (s1 > s2)
        cout << s1 << " is bigger than " << s2 << endl;
    else
        cout << s2 << " is bigger than " << s1 << endl;
    return 0;
}

// 比较字符串长度：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Please enter two strings: " << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2)
        cout << s1 << " and " << s2 << " are of same length: " << len1 << endl;
    else if (len1 > len2)
        cout << s1 << " is longer than " << s2 << " by " << len1 - len2 << endl;
    else
        cout << s1 << " is shorter than " << s2 << " by " << len2 - len1 << endl;
    return 0;
}