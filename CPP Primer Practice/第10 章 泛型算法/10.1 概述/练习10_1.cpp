/* 练习10.1：头文件 algorithm 中定义了一个名为 count 的函数，它类似 find，接受一对迭代器和一个值作为参数。count 返回给定值在序列中出现的次数。
编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。*/

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
    while (in >> val)
        vi.push_back(val);

    cout << "Please enter the integer you want to search: ";
    cin >> val;

    cout << "The sequnce contains " << count(vi.begin(), vi.end(), val) << "个" << val;

    return 0;
}


// 读者可以尝试自己编写计数整数出现次数的代码：

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "Failes to open the file!" << endl;
        exit(1);
    }

    vector<int> vi;
    int val;
    while (in >> val)
        vi.push_back(val);
    
    cout << "请输入要搜索的整数：";
    cin >> val;

    int c = 0;
    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        if (*iter == val)
            c++;
    cout << "序列中包含" << c << "个" << val;

    return 0;
}
