/* 练习7.15：为你的 Person 类添加正确的构造函数。

【出题思路】仿照 Sales_data 类，为 Person 类添加默认构造函数、
接受两个实参的构造函数和从标准输入流中读取数据的构造函数。*/

class Person
{
private:
    string strName;
    string strAddress;
public:
    Person() = default;
    Person(const string &name, const string &add)
    {
        strName = name;
        strAddress = add;
    }
Person(std::istream &is) { is >> *this; }
public:
    string getName() const { return strName; }          // 返回姓名
    string getAddress() const { return strAddress; }    // 返回地址
};
