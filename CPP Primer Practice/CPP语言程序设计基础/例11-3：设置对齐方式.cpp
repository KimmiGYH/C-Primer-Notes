// 例11-3：设置对齐方式

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    for (int i = 0; i < 4; i++)
        cout << setiosflags(ios_base::left) // 左对齐
             << setw(6) << names[i]
             << resetiosflags(ios_base::left) // 将左对齐的设置取消 将回到右对齐的方式
             << setw(10) << values[i] << endl;
        return 0;
}
/*
Zoot        1.23
Jimmy      35.36
AI         653.7
Stan     4358.24
*/