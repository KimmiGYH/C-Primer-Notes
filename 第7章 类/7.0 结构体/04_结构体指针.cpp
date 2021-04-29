#include <iostream>
#include <string>
using namespace std;

//结构体指针
//定义学生结构体
struct Student
{
    string name; //姓名
    int age;     //年龄
    int score;   //分数
};

int main() {
    //1、创建学生结构体变量
    Student s = { "ZhangSan", 18, 100};

    //2、通过指针指向结构体变量
    Student *p = &s;

    //3、通过指针访问结构体变量中的数据
    cout << "Name: " << p->name << " Age: " << p->age << " Score: " << p->score << endl;

    system("pause");

    return 0;
}

/*输出：
Name: ZhangSan Age: 18 Score: 100
*/