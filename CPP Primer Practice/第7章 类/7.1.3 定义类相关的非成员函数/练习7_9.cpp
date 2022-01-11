/* 练习7.9：对于7.1.2节(p233)练习中的代码，添加读取和打印Person对象的操作。

【出题思路】仿照 Sales_data类，为 Person 类添加相应的 read 和 print 函数。*/

std::istream &read(std::istream &is, Person &per)
{
    is >> per.strName >> per.strAddress;
    return is;
}

std::ostream &print(std::ostream &os, const Person &per)
{
    os << per.getName() << per.getAddress();
    return os;
}


/* 练习7.5：在你的 Person 类中提供一些操作使其能够返回姓名和住址。
这些函数是否应该是 const 的呢？解释原因。*/

class Person
{
private:
    string strName;
    string strAddress;
public:
    string getName() const { return strName; }          // 返回姓名
    string getAddress() const { return strAddress; }    // 返回地址
};