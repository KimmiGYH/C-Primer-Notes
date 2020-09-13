// 例11-4: 控制输出精度——指定 `scientific`

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 623.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    cout << setiosflags(ios_base::scientific);
    for (int i = 0; i < 4; i++)
        cout << setiosflags(ios_base::left)
             << setw(6) << names[i]
             << resetiosflags(ios_base::left) // 清除左对齐设置
             << setw(10) << setprecision(1) << values[i] << endl;
    return 0;
}
/* Output:
Zoot    1.2e+000
Jimmy   3.5e+001
AI      6.2e+002
Stan    4.4e+003
*/