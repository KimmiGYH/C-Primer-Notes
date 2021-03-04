/* 输入一行字符，统计出其中数字字符的个数，以及字母字符的个数。*/

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char c;
    int nums = 0, chars = 0;
    while (cin >> c)
    {
        if (c >= '0' && c <= '9') nums++;
        else if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') chars++;
    }
    printf("nums: %d\nchars: %d\n", nums, chars);
    
    return 0;
}
