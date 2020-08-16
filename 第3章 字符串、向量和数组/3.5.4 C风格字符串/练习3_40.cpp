/* 练习 3.40：编写一段程序，定义两个字符数组并用字符串字面值初始化它们；
接着再定义一个字符数组存放前两个数组连接后的结果。
使用 strcpy 和 strcat 把前两个数组的内容拷贝到第三个数组中。*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[] = "Welcome to ";
    char str2[] = "C++ family!";
    // 利用 strlen 函数计算两个字符串的长度，并求得结果字符串的长度
    char result[strlen(str1) + strlen(str2) - 1];

    strcpy(result, str1);   // 把第一个字符串拷贝到结果字符串中
    strcat(result, str2);   // 把第二个字符串拼接到结果字符串中

    cout << "The first string is: " << str1 << endl;
    cout << "The second string is: " << str2 << endl;
    cout << "The concatenated string is: " << result << endl;
    return 0;

/* Output:
The first string is: Welcome to 
The second string is: C++ family!
The concatenated string is: Welcome to C++ family!
*/
}