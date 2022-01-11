#include <iostream>

using namespace std;

char a, b;

int main()
{
    char c;
    int a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)  cout << *(a + i) << ' '; //输出1 2 3 4 5
    cout << endl;

    cout << (void*) &c << endl; //0x61ff07
    cout << a << endl;//0x61fef0
    for (int i = 0; i < 5; i++)
        cout << (void*)&a[i] << endl;
        /*
        0x61fef0
        0x61fef4
        0x61fef8
        0x61fefc
        0x61ff00
        */
    return 0;
}