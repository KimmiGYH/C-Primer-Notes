/*用if语句写一个程序，来统计在输入中每个值连续出现了多少次*/

#include <iostream>

int main()
{
    int currVal = 0, val = 0;
    // 读取第一个数，并确保确实有数据可以处理
    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) { // 读取剩余的数
            if (val == currVal)
                ++cnt;
            else { // 否则，打印一个值的个数
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val; // 记住新值
                cnt = 1; // 重置计数器
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}

/* Output:
1 1 1 1 1^Z
1 occurs 5 times

1 2 3 4 5^Z
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
*/