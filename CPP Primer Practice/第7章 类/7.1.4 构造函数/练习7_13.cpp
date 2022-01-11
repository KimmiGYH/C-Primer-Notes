/*练习7.13：使用 istream 构造函数重写第 229 页的程序。

【出题思路】原来的程序使用 Sales_data类的默认构造函数，本题改为使用接受 istream的构造函数。*/

// p229 程序：
Sales_data total;                   // 保存当前求和结果的变量
if (read(cin, total)) {             // 读入第一笔交易
    Sales_data trans;               // 保存下一条交易数据的变量
    while(read(cin, trans)) {       // 读入剩余的交易
        if (total.isbn() == trans.isbn())   // 检查 isbn
            total.combine(trans);   // 更新变量 total 当前的值
        else {
            print(cout, total) << endl; // 输出结果
            total = trans;          // 把trans赋给total，处理下一本书
        }
    }
    print(cout, total) << endl;     // 输出最后一条交易
} else {                            // 没有输入任何信息
    cerr << "No data?!" << endl;    // 通知用户
}


// 改写后的程序

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data total(cin);                      // 保存当前求和结果的变量
    if (cin)
    {                                           // 读入第一笔交易
        Sales_data trans(cin);                  // 保存下一条交易数据的变量
        do
        {                                       // 读入剩余的交易
            if (total.isbn() == trans.isbn())   // 检查 isbn
                total.combine(trans);           // 更新变量 total 当前的值
            else
            {
                print(cout, total) << endl;     // 输出结果
                total = trans;                  // 处理下一本书
            }
            
        } while (read(cin, trans));
        print(cout, total) << endl;             // 输出最后一条交易
    }
    else
    {                                           // 没有输入任何信息
        cerr << "No data?!" << endl;            // 通知用户
    }
    return 0;
}