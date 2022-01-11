/*编写程序，使用 for 循环将 50 到 100 的整数相加*/

#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 50; val <= 100; val++)
        sum += val;
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}
// The sum is 3825