#include <iostream>
using namespace std;

//定义学生结构体
struct Student
{
    string name;
    int age;
    int score;
};

//打印学生信息函数
//1、值传递
void printStudent1(struct Student s)
{
    s.age = 100; //在函数体内将年龄改成100岁看结果
    cout << "[1st] Name: " << s.name << " Age: " << s.age << " Score: " << s.score << endl;
}

//2、地址传递
void printStudent2(struct Student *p)
{
    p->age = 200; //在函数体内将年龄改成200岁看结果
    cout << "[2nd] Name: " << p->name << " Age: " << p->age << " Score: " << p->score << endl;
}

int main() {

    //结构体做函数参数
    //将学生传入到一个参数中，打印学生身上的所有信息

    struct Student s;
    s.name = "ZhangSan";
    s.age = 20;
    s.score = 85;

    printStudent1(s);
    printStudent2(&s);

    cout << "Inside Main Fuction, Name: " << s.name << " Age: " << s.age << " Score: " << s.score << endl;

    system("pause");
    return 0;
}
/*输出：
//1.值传递，主函数里的没被影响
[1st] Name: ZhangSan Age: 100 Score: 85
Inside Main Fuction, Name: ZhangSan Age: 20 Score: 85

//2.地址传递，主函数中的值也被改变成了200岁
[2nd] Name: ZhangSan Age: 200 Score: 85
Inside Main Fuction, Name: ZhangSan Age: 200 Score: 85
*/