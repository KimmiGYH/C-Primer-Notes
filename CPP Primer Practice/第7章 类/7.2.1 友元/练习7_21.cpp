/*练习7.21：修改你的 Sales_data 类使其隐藏实现的细节。
你之前编写的关于 Sales_data 操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。

把函数 read、print 和 add 设置为 Sales_data 类的友元，其形式如下所示，
此时即使数据成员的访问说明符是 private 也能编译通过。*/

class Sales_data {
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    private:
        std::string bookNo;         // 书籍编号
        unsigned units_sold = 0;    // 销售量
        double sellingprice = 0.0;  // 原始价格
        double saleprice = 0.0;     // 实售价格
        double discount = 0.0;      // 折扣
};