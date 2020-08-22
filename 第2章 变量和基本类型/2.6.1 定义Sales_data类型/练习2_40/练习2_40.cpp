/* 练习2.40：根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。*/

struct Sales_data {
    std::string bookNo;         // 书籍编号
    unsigned units_sold = 0;    // 销售量
    double sellingprice = 0.0;  // 零售价
    double saleprice = 0.0;     // 实售价
    double discount;            // 折扣
};