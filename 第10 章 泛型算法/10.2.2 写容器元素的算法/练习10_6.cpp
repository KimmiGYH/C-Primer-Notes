/* 练习10.6：编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "Fails to open the file!" << endl;
        exit(1);
    }

    vector<int> vi;
    int val;
    while (in >> val) {
        vi.push_back(val);
        cout << val << " ";
    }
    cout << endl;

    fill_n(vi.begin(), vi.size(), 0);
    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        cout << *iter << " ";
    
    return 0;
}