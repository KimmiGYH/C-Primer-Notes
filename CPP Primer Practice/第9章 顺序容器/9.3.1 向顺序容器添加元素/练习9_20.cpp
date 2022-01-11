/* 练习9.20：编写程序，从一个 `list<int>` 拷贝元素到两个 `deque` 中。
值为偶数的所有元素都拷贝到一个 `deque` 中，而奇数值元素都拷贝到另一个 `deque` 中。

【出题思路】练习多个容器间数据的处理、拷贝。*/

#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7, 8}; // 初始化整数 list
    deque<int> odd_d, even_d;

    // 遍历整数 list
    for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
        if (*iter & 1)      // 查看最低位，1：奇数， 0：偶数
            odd_d.push_back(*iter);
        else even_d.push_back(*iter);
    
    cout << "The odd numbers are: ";
    for (auto iter = odd_d.cbegin(); iter != odd_d.cend(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "The even numbers are: ";
    for (auto iter = even_d.cbegin(); iter != even_d.cend(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}

/*Output:
The odd numbers are: 1 3 5 7 
The even numbers are: 2 4 6 8 

【其他解题思路】对于奇偶性判定，可用模2运算“%2”代替位与运算，两者是等价的。*/