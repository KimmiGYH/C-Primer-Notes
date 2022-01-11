/* 练习3.20：读入一组整数并把它们存入一个 vector 对象，将每对相邻整数的和输出出来。
改写你的程序，这次要求先输出第 1 个和最后 1 个元素的和，接着输出第 2 个和倒数第 2 个元素的和，以此类推。*/

// 求相邻元素和的程序如下所示：
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "Please enter a group of numbers: " << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "There are no elements." << endl;
        return -1;
    }
    cout << "Adjacent two numbers are: " << endl;
    // 利用 decltype 推断 i 的类型
    for (decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
    {
        // 求相邻两项的和
        cout << vInt[i] + vInt[i+1] << " ";
        // 每行输出 5 个数字
        if ((i + 2) % 10 == 0)
            cout << endl;
    }
    // 如果元素数是奇数，单独处理最后一个元素
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() - 1];
    return 0;
}


// 求首尾元素和的程序如下所示：
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "Please enter a group of numbers: " << endl;
    while (cin >> iVal)
        vInt.push_back(iVal);
    if (vInt.size() == 0)
    {
        cout << "There are no elements." << endl;
        return -1;
    }
    cout << "First and last elements are: " << endl;
    for  (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++)
    {
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " "; // 这步重要
        // 每行输出 5 个数字
        if ((i + 1) % 5 == 0)
            cout << endl;   
    }
    // 如果元素数是奇数，单独处理中间那个元素
    if(vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];
    return 0;
}