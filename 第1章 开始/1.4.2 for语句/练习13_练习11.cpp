/*编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。*/

#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two integers: ";
    std::cin >> v1 >> v2;
    if (v1 < v2) {
        for (int i = v1; i <= v2; i++)
            std::cout << i << " ";
        std::cout << std::endl;
    } else {
        for (int i = v2; i <= v1; i++)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}