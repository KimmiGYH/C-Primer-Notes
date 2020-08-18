/* 练习5.11：修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。

练习5.10：我们之前实现的统计元音字母的程序存在一个问题：
如果元音字母以大写形式出现，不会被统计在内。
编写一段程序，既统计元音字母的小写形式，也统计大写形式，
也就是说，新程序遇到 'a'和'A'都应该递增 aCnt 的值，以此类推。*/

/* 【出题思路】
继续扩充 case 标签即可。
其中，读入字符的语句应该使用 cin.get(ch)，而不能使用 >>，
因为后者会忽略本体索要统计的特殊符号。
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch;
    cout << "Please enter a text: " << endl;
    while (cin.get(ch))
    {
        switch (ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
        }
    }
    cout << "The number of letter a is: " << aCnt << endl;
    cout << "The number of letter e is: " << eCnt << endl;
    cout << "The number of letter i is: " << iCnt << endl;
    cout << "The number of letter o is: " << oCnt << endl;
    cout << "The number of letter u is: " << uCnt << endl;
    cout << "The number of letter space is: " << spaceCnt << endl;
    cout << "The number of letter tab is: " << tabCnt << endl;
    cout << "The number of letter newline is: " << newlineCnt << endl;
    return 0;
}