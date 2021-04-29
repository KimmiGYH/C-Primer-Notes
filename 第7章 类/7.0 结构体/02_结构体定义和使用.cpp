#include <iostream>
#include <string>
using namespace std;

// 1、创建学生数据类型 ： 学生包括（姓名，年龄，分数）
struct Student
{
    string name;
    int age;
    int score;
}s3;

// 2、通过学生类型创建具体学生
int main() {
    // 注意：struct 的关键字可以省略
    // 2.1 struct Student s1
    struct Student s1;
    s1.name = "ZhangSan";
    s1.age = 18;
    s1.score = 100;
    cout << "Name: " << s1.name << " Age: " << s1.age << " Score: " << s1.score << endl;

    // 2.2 struct Student s2 = { ... }
    struct Student s2 = {"LiSi", 19, 80};
    cout << "Name: " << s2.name << " Age: " << s2.age << " Score: " << s2.score << endl;

    // 2.3 在定义结构体时顺便创建结构体变量
    s3.name = "WangWu";
    s3.age = 20;
    s3.score = 60;
    cout << "Name: " << s3.name << " Age: " << s3.age << " Score: " << s3.score << endl;

    system("pause");

    return 0;
}

/*输出：
Name: ZhangSan Age: 18 Score: 100
Name: LiSi Age: 19 Score: 80     
Name: WangWu Age: 20 Score: 60   
*/