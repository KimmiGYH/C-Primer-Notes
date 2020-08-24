/* 练习7.14：编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

【出题思路】构造函数初始值列表负责为新创建的对象的一个或几个数据成员赋初值。
构造函数初始值是成员名字的一个列表，每个名字后面紧跟括号括起来的成员初始值，
不同成员的初始化通过逗号分隔开。 */

Sales_data (const std::string &book)
    : bookNo(book), units_sold(0), sellingprice(0), saleprice(0), discount(0) {}