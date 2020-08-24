/* 练习7.12：把只接受一个 istream 作为参数的构造函数定义移到类的内部。

【出题思路】构造函数既可以定义在类的外部，也可以定义在类的内部。*/

#include <iostream>
using namespace std;

class Sales_data
{
public:                         // 构造函数的 4 种形式
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) { }
    Sales_data(const std::string &book, const unsigned num,
               const double sellp, const double salep);
    Sales_data(std::istream &is) { is >> *this; }
public:
    std::string bookNo;         // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;    // 销售量，显式初始化为 0
    double sellingprice = 0.0;  // 原始价格，显式初始化为 0.0
    double saleprice = 0.0;     // 实售价格，显式初始化为 0.0
    double discount = 0.0;      // 折扣，显式初始化为 0.0
};