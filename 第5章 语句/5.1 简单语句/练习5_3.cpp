// 练习5.3：使用逗号运算符的 while 循环，使它不再需要块。

#include <iostream>
int main()
{
    int sum = 0, val = 1;
    /*
    while (val <= 10) {
        sum += val; // 将 sum + val 赋予 sum
        ++val;      // 将 val 加 1
    }
    */

    // 利用逗号运算符改写之后的形式如下所示：
    while (val <= 10)
        sum += val, ++val;

    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
    return 0;
}