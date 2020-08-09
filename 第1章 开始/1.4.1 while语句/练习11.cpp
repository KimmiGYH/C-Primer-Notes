/*编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。*/

#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two integers: " << std::endl;
    std::cin >> v1 >> v2;
    if (v1 <= v2) {
        while (v1 <= v2) {
            std::cout << v1 << " ";
            v1++;
        }
    }
    else if (v1 > v2) {
        while (v1 >= v2) {
            std::cout << v1 << " ";
            v1--;
        }
    }
    std::cout << std::endl;
    return 0;
}
