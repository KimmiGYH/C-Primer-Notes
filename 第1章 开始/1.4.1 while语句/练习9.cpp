/*编写程序，使用 while 循环将 50 到 100 的整数相加*/

#include <iostream>

int main()
{
    int val = 50, sum = 0;
    while (val < 101)
    {
        sum += val;
        ++val;
    }
    std::cout << "50 到 100 之间的整数之和为" << sum << std::endl;
    return 0;
}
// The sum is 3825