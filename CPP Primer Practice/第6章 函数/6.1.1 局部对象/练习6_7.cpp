/* 练习6.7：编写一个函数，当它第一次被调用时返回 0，以后每次被调用返回值加 1。*/

#include <iostream>
using namespace std;

unsigned myCnt()
{
    // (等于初始化为最大值，然后 + 就变成0了)
    static unsigned iCnt = -1;  // iCnt 是静态局部变量
    ++iCnt;
    return iCnt; 
}

int main()
{
    cout << "Please enter any char and press enter to continue." << endl;
    char ch;
    while (cin >> ch)
    {
        cout << "The function myCnt() has been called: " 
        << myCnt() << " times." << endl;
    }
    return 0;
}

/* Output:
Please enter any char and press enter to continue.
s  
The function myCnt() has been called: 0 times.
1
The function myCnt() has been called: 1 times.
t
The function myCnt() has been called: 2 times.
-
The function myCnt() has been called: 3 times.

^Z
*/
