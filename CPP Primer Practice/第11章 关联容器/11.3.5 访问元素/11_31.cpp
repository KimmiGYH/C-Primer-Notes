#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void remove_authors(multimap<string, string>& books, const string& author)
{
    auto pos = books.equal_range(author);   // 查找给定作者范围
    if (pos.first == pos.second)            // 空范围，没有该作者
        cout << "This author " << author << " doesn't exist." << endl << endl;
    else
        books.erase(pos.first, pos.second); // 删除该作者所有著作
}

void print_books(multimap<string, string>& books)
{
    cout << "The current books include: " << endl;
    for (auto& book : books)                // 遍历所有书籍，打印之
        cout << book.first << ", <<" << book.second << ">> " << endl;
    cout << endl;
}

int main(int argc, char* argv[])
{
    multimap<string, string> books;
    books.insert({"Barth, John", "Sot-Weed Factor"});
    books.insert({"Barth, John", "Lost in the Funhouse"});
    books.insert({"Jin Yong", "She Diao Yin Xiong Zhuan"});
    books.insert({"Jin Yong", "Tian Long Ba Bu"});

    print_books(books);
    remove_authors(books, "Zhang San");
    remove_authors(books, "Barth, John");
    print_books(books);

    return 0;
}
