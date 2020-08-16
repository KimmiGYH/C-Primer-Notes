/* 练习4.33：根据4.12节中的表(第147页)说明下面这条表达式的含义。

someValue ? ++x, ++y : --x, --y
*/

#include <iostream>

using namespace std;

int main()
{
    int x = 10, y = 20;
    // 检验条件为真的情况
    bool someValue = true;
    someValue ? ++x, ++y : --x, --y;
    cout << x << endl;
    cout << y << endl;
    cout << someValue << endl;

    x = 10, y = 20;
    // 检验条件为假的情况
    someValue = false;
    someValue ? ++x, ++y : --x, --y;
    cout << x << endl;
    cout << y << endl;
    cout << someValue << endl;

    return 0;
}

/* Output:
11
20
1
9
19
0
*/