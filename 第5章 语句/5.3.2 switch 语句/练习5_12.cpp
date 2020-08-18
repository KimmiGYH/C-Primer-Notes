/* 练习5.12：修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量：ff、fl 和 fi。

【解答】
我们的设定是一个字符只会被统计一次。
如果用户输入的序列是 xxxxxfflxxx，则统计结果是ff: 1次、fl: 0次、fi: 0次。
如果用户输入的序列是 xxxxxfiffffflxxx，则统计结果是 ff:2次、fl:1次、fi:1次。
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    cout << "Please enter a text: " << endl;
    while (cin >> ch)
    {
        bool bl = true;
        if (prech == 'f')
        {
            switch(ch)
            {
            case 'f':
                ++ffCnt;
                bl = false;
                break;
            case 'l':
                ++flCnt;
                break;
            case 'i':
                ++fiCnt;
                break;
            }
        }
        if (!bl)
            prech = '\0';
        else
            prech = ch;
    }
    cout << "The number of ff is: " << ffCnt << endl;
    cout << "The number of fl is: " << flCnt << endl;
    cout << "The number of fi is: " << fiCnt << endl;
    return 0;
}
