/* 练习7.41：使用委托构造函数重新编写你的Sales data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建Sales data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。*/

#include <iostream>
#include <string>
using namespace std;

class Sales_data {
friend std::istream &read(std::istream &is, Sales_data &item);
friend std::ostream &print(std::ostream &os, const Sales_data &item);
public:
    // First
    Sales_data(const string &book, unsigned num, double sellp, double salep)
    : bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
    {
        if (sellingprice)
            discount = saleprice / sellingprice;
        cout << "This constructor accepts four pieces of info: BookNo, UnitsSold, SellingPrice, Salesprice." << endl;
    }
    // Second
    Sales_data() : Sales_data("", 0, 0, 0)
    {
        cout << "This constructor accepts no info." << endl;
    }
    // Third
    Sales_data(const string &book) : Sales_data(book, 0, 0, 0)
    {
        cout << "This constructor accepts BookNo. " << endl;
    }
    // Last
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is, *this);
        cout << "This constructor accepts users' inputs. " << endl;
    }
private:
    std::string bookNo;         // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;    // 销售量，显式初始化为 0
    double sellingprice = 0.0;  // 原始价格，显式初始化为 0.0
    double saleprice = 0.0;     // 实售价格，显式初始化为 0.0
    double discount = 0.0;      // 折扣，显式初始化为 0.0
};

std::istream &read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.bookNo << " " << item.units_sold << " " << item.sellingprice
       << " " << item.saleprice << " " << item.discount;
    return os;
}

int main()
{
    Sales_data first("978-7-121-15535-2", 85, 128, 109);
    // This constructor accepts four pieces of info: BookNo, UnitsSold, SellingPrice, Salesprice.
    Sales_data second;
    // This constructor accepts four pieces of info: BookNo, UnitsSold, SellingPrice, Salesprice.
    // This constructor accepts no info.
    Sales_data third("978-7-121-15535-2");
    // This constructor accepts four pieces of info: BookNo, UnitsSold, SellingPrice, Salesprice.
    // This constructor accepts BookNo. 
    Sales_data last(cin);
    // This constructor accepts users' inputs. 
    return 0;
}
