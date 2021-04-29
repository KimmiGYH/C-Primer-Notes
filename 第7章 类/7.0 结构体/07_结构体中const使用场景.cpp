#include <iostream>
using namespace std;

//const的使用场景
struct Student
{
    string name;
    int age;
    int score;
};

//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
void printStudents(const Student *s)
{
    // s->age = 150; //加入const之后，一旦有修改的操作就会报错，可以防止误操作
    cout << " Name: " << s->name << " Age: " << s->age << " Score: " << s->score << endl;
}

int main()
{
    //创建结构体变量
    struct Student s = { "ZhangSan", 15, 70 };

    //通过函数打印结构体变量信息
    printStudents(&s);

    cout << " Name: " << s.name << " Age: " << s.age << " Score: " << s.score << endl;

    system("pause");
    return 0;
}