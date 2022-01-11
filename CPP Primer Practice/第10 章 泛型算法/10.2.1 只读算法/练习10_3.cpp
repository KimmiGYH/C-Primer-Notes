/* 练习10.3：用 accumulate 求一个 vector<int> 中的元素之和。

【解答】Accumulate的前两个参数仍然是指定范围的一对迭代器，第三个参数是和的初值。*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    while (in >> val)
        vi.push_back(val);
    
    cout << "The sum of the integers in the sequence is: "
         << accumulate(vi.begin(), vi.end(), 0) << endl;
    
    return 0;
}