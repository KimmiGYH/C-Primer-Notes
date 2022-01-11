#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    std::cout << typeid(i).name() << std::endl; // i 是整型常量
    std::cout << typeid(j).name() << std::endl; // j 是整数
    std::cout << typeid(k).name() << std::endl; // k 是整型常量
    std::cout << typeid(p).name() << std::endl; // p 是指向整型常量的指针
    std::cout << typeid(j2).name() << std::endl;// j2 是整数
    std::cout << typeid(k2).name() << std::endl;// k2 是整数
    return 0;
}

/* Output:
i
i
i
PKi
i
i
*/

/*备注：`i` 表示 "int"；`PK` 表示 "pointer to const" */
