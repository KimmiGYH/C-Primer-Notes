/* 练习7.3：修改 7.1.1节（第229页）的交易处理程序，令其使用这些成员。

【出题思路】
该程序的作用是累加相同编号的书籍销售记录并输出，直至遇到下一个编号为止。
改写程序时，用上一题定义的 isbn 函数获取书籍的编号，用 combine 函数把两条销售记录相加。
*/

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    cout << "请输入交易记录（ISBN、销售量、原价、实际售价：）" << endl;
    Sales_data total;                           // 保存下一条交易记录的变量
    // 读入第一条交易记录，并确保有数据可以处理
    if (cin >> total)
    {
        Sales_data trans;                       // 保存和的变量
        // 读入并处理剩余交易记录
        while (cin >> trans)
        {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total.combine(trans);           // 更新总销售额
            else
            {
                // 打印前一本书的结果
                cout << total << endl;
                total = trans;                  // total 现在表示下一本书的销售额
            }
        }
        cout << total << endl;                  // 打印最后一本书的结果
    }
    else
    {
        // 没有输入！警告读者
        cerr << "No data?!" << endl;
        return -1;                              // 表示失败
    }
    return 0;    
}