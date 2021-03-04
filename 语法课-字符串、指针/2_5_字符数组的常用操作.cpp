#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char s1[100] = "hello world!", s2[100];

    cout << strlen(s1) << endl;

    strcpy(s2, s1); // 把后者复制给前者

    cout << strcmp(s1, s2) << endl;

    return 0;
}