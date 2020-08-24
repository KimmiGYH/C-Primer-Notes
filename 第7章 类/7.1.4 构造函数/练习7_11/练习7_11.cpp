/* 练习7.11：在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。

【出题思路】在不同情况下，初始化 Sales_data 对象所需的数据有所不同，分别为其设计构造函数，
同时也利用C++11新标准提供的 =default 定义默认构造函数。*/

#include <iostream>
using namespace std;

class Sales_data
{
public:                         // 构造函数的 4 种形式
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) { }
    Sales_data(const std::string &book, const unsigned num,
               const double sellp, const double salep);
    Sales_data(std::istream &is);
public:
    std::string bookNo;         // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;    // 销售量，显式初始化为 0
    double sellingprice = 0.0;  // 原始价格，显式初始化为 0.0
    double saleprice = 0.0;     // 实售价格，显式初始化为 0.0
    double discount = 0.0;      // 折扣，显式初始化为 0.0
};

Sales_data::Sales_data(const std::string &book, const unsigned num,
                    const double sellp, const double salep)
{
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if(sellingprice != 0)
        discount = saleprice / sellingprice; // 计算实际折扣
}

Sales_data::Sales_data(std::istream &is)
{
    is >> *this;
}

/* 在类的定义中，我们设计了 4 个构造函数。
第一个构造函数是默认构造函数，它使用了 C++11 新标准提供的 =default。它的参数列表为空，即不需要我们提供任何数据也能构造一个对象。

第二个构造函数只接受一个 const string&，表示书籍的 ISBN编号，编译器赋予其他数据成员类内初始值。

第三个构造函数接受完整的销售记录信息，const string& 表示书籍的 ISBN 编号，
const unsigned 表示销售量，后面两个 const double 分别表示书籍的原价和实际售价。

最后一个构造函数接受 istream& 并从中读取书籍的销售信息。*/

int main()
{
    Sales_data data1;
    Sales_data data2("978-7-121-15535-2");
    Sales_data data3("978-7-121-15535-2", 100, 128, 109);
    Sales_data data4(cin);

    cout << "The books' sales status is: " << endl;

    cout << data1 << "\n" << data2 << "\n" << data3 << "\n" << data4 << "\n";
    return 0;
}