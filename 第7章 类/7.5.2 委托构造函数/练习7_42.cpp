/* 练习7.42：对于你在练习 7.40 中编写的类，确定哪些构造函数可以使用委托。
如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

【出题思路】
委托构造函数是指使用它所属类的其他构造函数执行它自己的初始化过程，因此在类中应该设计一些构造函数使其具备自主的构造函数功能，而把另外一些设计成委托构造函数。*/

class Book
{
private:
    string Name, ISBN, Author, Publisher;
    double Price = 0;
public:
    Book(const string &n, const string &I, double pr, const string &a, const string &p)
        : Name(n), ISBN(I), Price(pr), Author(a), Publisher(p) { }
    Book() : Book("", "", 0, "", "") { }
    Book(std::istream &is) : Book() { is >> *this; }
}