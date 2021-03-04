#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    for (int i = 0; i< 128; i++)
        printf("%d: %c\n", i, (char)i);

    return 0;
}