#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char a[100] = "hello world";

    for (int i = 0, len = strlen(a); i < len; i++)
        cout << a[i] << endl;

    return 0;
}

/*注意：如果没先存 len 而写成 i < strlen(a)，那么就两重循环了。*/