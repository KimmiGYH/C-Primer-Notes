/* 练习5.9：编写一段程序使用一系列 if 语句统计从 cin 读入的文本中有多少元音字母。*/

#include <iostream>
using namespace std;

int main()
{
    unsigned int vowelCnt = 0;
    char ch;
    cout << "Please enter a text: " << endl;
    while (cin >> ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++vowelCnt;
    }
    cout << "The text you enter have in total " << vowelCnt << " vowels." << endl;
    
    return 0;
}

/* Output:
Please enter a text: 
I really miss you Mr Meow!
^Z
The text you enter have in total 7 vowels.
*/