/*写一段程序，求 1 到 10 这10个数之和*/
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
// Sum of 1 to 10 inclusive is 55