#include <iostream>
#include <string>
using namespace std;

//定义学生的结构体
struct Student
{
    string name;
    int age;
    int score;
};

//定义老师的结构体
struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu; //辅导的学生
};

int main() {

    //结构体嵌套结构体
    //创建老师
    Teacher t;
    t.id = 10000;
    t.name = "LaoWang";
    t.age = 50;
    t.stu.name = "XiaoWang";
    t.stu.age = 20;
    t.stu.score = 60;

    cout << "Teacher's name: " << t.name << "\nTeacher's ID: " << t.age
         << "\nHis student's name: " << t.stu.name << "\nStudent's age: " << t.stu.age
         << "\nStudent's score: " << t.stu.score << endl;

    system("pause");
    return 0;
}

/*输出：
Teacher's name: LaoWang     
Teacher's ID: 50
His student's name: XiaoWang
Student's age: 20
Student's score: 60
*/