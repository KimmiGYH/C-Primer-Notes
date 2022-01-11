/* 练习7.2：曾在2.6.2节的练习中编写了一个 Sales_data类，请向这个类添加 combine 和 isbn 成员。*/

// 添加 combine 和 isbn 成员后的 Sales_data 类是：
class Sales_data
{
private:                        // 定义私有数据成员
    string bookNo;              // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;    // 销售量，显式初始化为 0
    double sellingprice = 0.0;  // 原始价格
    double saleprice = 0.0;     // 实售价格
    double discount = 0.0;      // 折扣
public:                         // 定义公有函数成员
    // isbn 函数只有一条语句，返回 bookNo
    string isbn () const { return bookNo; }
    // combine 函数 用于把两个 ISBN 相同的销售记录合并在一起
    Sales_data& combine( const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
                    / (rhs.units_sold + units_sold);    // 重新计算世纪销售价格
        if (sellingprice != 0)
            discount = saleprice / sellingprice;        // 重新计算实际折扣
        return *this;                                   // 返回合并后的结果
    }
}