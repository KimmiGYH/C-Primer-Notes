/* 练习7.1：使用2.6.1节练习定义的 Sales_data类为 1.6节的交易处理程序编写一个新版本。

程序的思路是：只要ISBN相同，就不断累积啊销量并重新计算平均售价，直至输入新的书籍为止。*/

#include <iostream>
#include "Sales_data.h"
using namespace std;

int main()
{
    cout << "请输入交易记录(ISBN、销售量、原价、实际售价)：" << endl;
    Sales_data total;
    
    if (cin >> total)       // 读入第一条交易记录，并确保有数据可以处理
    {
        Sales_data trans;       // 保存和的变量
        while (cin >> trans)    // 读入并处理剩余交易记录
        {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total += trans; // 更新总销售额
            else
            {
                cout << total << endl;  // 打印前一本书的结果
                total = trans;  // total 现在表示下一本书的销售额
            }
        }
        cout << total << endl;  // 打印最后一本书的结果
    }
    else
    {
        // 没有输入！警告读者
        cerr << "No data?!" << endl;
        return -1;              // 表示失败
    }
    return 0;
}
