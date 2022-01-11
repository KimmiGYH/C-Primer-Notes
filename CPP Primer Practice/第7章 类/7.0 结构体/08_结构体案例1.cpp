#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//学生的结构体定义
struct Student
{
    string sName;
    int score;
};


//老师的结构体定义
struct Teacher
{
    string tName;
    struct Student sArray[5];
};

//给老师和学生赋值的函数
void allocateSpace (struct Teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i ++) {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        //通过循环给每名老师所带的学生赋值
        for (int j = 0; j < 5; j ++)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            int random = rand() % 61 + 40; //分数在40~100分之间的随机数
            tArray[i].sArray[j].score = random;
        }
    }

}

//打印所有的信息
void printInfo(struct Teacher tArray[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        cout << "Teacher Name: " << tArray[i].tName << endl;

        for (int j = 0; j < 5; j ++)
        {
            cout << "\tStudent Name: " << tArray[i].sArray[j].sName
                 << " Score: " << tArray[i].sArray[j].score << endl;
        }
    }
}

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));

    //1、创建3名老师的数组
    struct Teacher tArray[3];

    //2、通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);

    //3、打印所有老师及所带的学生信息
    printInfo(tArray, len);
    
    return 0;
}

/*输出：
Teacher Name: Teacher_A
        Student Name: Student_A Score: 97
        Student Name: Student_B Score: 61
        Student Name: Student_C Score: 73
        Student Name: Student_D Score: 63
        Student Name: Student_E Score: 94
Teacher Name: Teacher_B
        Student Name: Student_A Score: 58
        Student Name: Student_B Score: 71
        Student Name: Student_C Score: 86
        Student Name: Student_D Score: 42
        Student Name: Student_E Score: 96
Teacher Name: Teacher_C
        Student Name: Student_A Score: 87
        Student Name: Student_B Score: 84
        Student Name: Student_C Score: 73
        Student Name: Student_D Score: 57
        Student Name: Student_E Score: 80
*/