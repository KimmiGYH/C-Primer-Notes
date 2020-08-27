/*练习7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员吗，提供一组合理的构造函数并阐明这样做的原因。

(a) Book    (b) Data    (c) Employee
(d) Vehicle (e) Object  (f) Tree

【出题思路】掌握创类类型的方法，理解不同构造函数的区别。*/

/*首先选择(a) Book，
一本书通常包含书名、ISBN 编号、定价、作者、出版社等信息，
因此令其数据成员为：Name、ISBN、Price、Author、Publisher，
其中 Price 是 double 类型，其他都是 string 类型。
Book 的构造函数有三个：
一个默认构造函数、
一个包含完整书籍信息的构造函数、
一个接受用户输入的构造函数。
其定义如下： */

class Book
{
private:
    string Name, ISBN, Author, Publisher;
    double Price = 0;
public:
    Book() = default;
    Book(const string &n, const string &I, double pr, const string &a, const string &p)
    {
        Name = n;
        ISBN = I;
        Price = pr;
        Author = a;
        Publisher = p;
    }
    Book(std::istream &is) { is >> *this; }
};

/*也可以选择(f) Tree，一棵树通常包含树的名称、存活年份、树高等信息，因此令其数据成员为：Name、Age、Height，

其中 Name 是 string 类型，Age 是 unsigned 类型，Height 是 double 类型。

假如我们不希望由用户输入 Tree 的信息，则可以去掉接受 std::istream& 形参的构造函数，只保留默认构造函数和接受全部信息的构造函数。

其定义如下：*/

class Tree
{
private:
    string Name;
    unsigned Age = 0;
    double Height = 0;
public:
    Tree() = default;
    /* Tree(const string &n, unsigned a, double h)
        : Name(n), Age(a), Height(h); 错误代码 可能是typo*/
    
    Tree(const string &n, unsigned a, double h)
        : Name(n), Age(a), Height(h) { }
};
