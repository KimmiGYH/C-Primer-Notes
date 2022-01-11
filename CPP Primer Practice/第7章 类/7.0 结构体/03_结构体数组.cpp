#include <iostream>
#include <string>
using namespace std;

// 结构体数组
// 1、定义结构体
struct Student
{
    string name;
    int age;
    int score;
};

int main() {    
    // 2、创建结构体数组
    struct Student stuArray[3] =
    {
        {"ZhangSan", 18, 100},
        {"LiSi", 28, 99},
        {"WangWu", 38, 66}
    };

    // 3、给结构体数组中的元素赋值
    stuArray[2].name = "ZhaoLiu";
    stuArray[2].age = 80;
    stuArray[2].score = 60;

    // 4、遍历结构体数组
    for (int i = 0; i < 3; i ++)
    {
        cout << "Name: " << stuArray[i].name
             << " Age: " << stuArray[i].age
             << " Score: " << stuArray[i].score << endl;
    }

    system("pause");

    return 0;
}

/*输出：
Name: ZhangSan Age: 18 Score: 100
Name: LiSi Age: 28 Score: 99     
Name: ZhaoLiu Age: 80 Score: 60  
*/