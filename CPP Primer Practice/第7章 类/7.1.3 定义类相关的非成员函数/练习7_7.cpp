/* 练习7.7：使用这些新函数重写 7.1.2节(p233) 练习中的交易处理程序。

【出题思路】用 read 函数替代 >>，print 函数替代 <<，add 函数替代 combine 函数。
*/

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    cout << "请输入交易记录（ISBN、销售量、原价、实际售价：）" << endl;
    Sales_data total;
    // 读入第一条交易记录，并确保有数据可以处理
    if ( read(cin, total))
    {
        Sales_data trans;           // 保存和的变量
        while(read(cin, trans))     // 读入并处理剩余交易记录
        {
            if (total.isbn() == trans.isbn())   // 如果我们仍在处理相同的书
                total = add(total, trans);      // 更新总销售额
            else
            {
                print(cout, total); // 打印前一本书的结果
                cout << endl;
                total = trans;      // total 现在表示下一本书的销售额
            }
        }
        print(cout, total);         // 打印最后一本书的结果
        cout << endl;
    }
    else
    {
        cerr << "No data?!" << endl;// 没有输入！警告读者
        return -1;                  // 表示失败
    }
    return 0;    
}
