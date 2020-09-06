/*练习10.4：假定 v 是一个 vector<double>，那么调用 accumulate(v.cbegin(), v.cend(), 0) 有何错误（如果存在的话）？

【解答】accumulate 的第三个参数是和的初值，它还决定了函数的返回类型，以及函数中使用哪个加法运算符。因此，本题中的调用是错误的，第三个参数 0 告知accumulate，和是整型的，使用整型加法运算符。
读者可尝试输入带小数的值．函数返回的是一个整数。

正确的调用方法是将 0.0 作为第三个参数传递给 accumulate。
读者可以修改、运行程序，观察运行结果。*/

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

    vector<double> vd;
    double val;
    while (in >> val)
        vd.push_back(val);
    
    cout << "The sum of the floats in the sequence is: " 
         << accumulate(vd.begin(), vd.end(), 0) << endl;

    return 0;
}