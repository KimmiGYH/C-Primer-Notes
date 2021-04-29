#include <iostream>
#include <string>
using namespace std;

//1、设计英雄结构体
struct Hero
{
    string name;
    int age;
    string gender;
};

//3、冒泡排序 实现年龄升序排列
void bubbleSort(struct Hero heroArray[], int len)
{
    for (int i = 0; i < len - 1; i ++)
    {
        for (int j = 0; j < len - i - 1; j ++)
        {
            //如果 j 下标的元素年龄 大于 j+1 下标的元素的年龄，交换两个元素
            if (heroArray[j].age > heroArray[j + 1].age)
            {
                struct Hero temp = heroArray[j];
                heroArray[j] = heroArray[j + 1];
                heroArray[j + 1] = temp;
            }
        }
    }
}

//4、打印排序后数组中的信息
void printHero(struct Hero heroArray[], int len)
{
    cout << "排序后的打印：" << endl;
    for (int i = 0; i < len; i ++)
    {
        cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age
             << " 性别：" << heroArray[i].gender << endl;
    }
}

int main() {
    //2、创建数组存放 5 名英雄
    struct Hero heroArray[5] = 
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 20, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}
    };

    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    cout << "排序前的打印：" << endl;
    for (int i = 0; i < len; i ++) {
        cout << "姓名：" << heroArray[i].name << " 年龄：" << heroArray[i].age
             << " 性别：" << heroArray[i].gender << endl;
    }

    //3、对数组进行排序，按照年龄进行升序排序
    bubbleSort(heroArray, len);

    //4、将排序后的结果打印输出
    printHero(heroArray, len);

    system("pause");

    return 0;
}
/*输出：

排序前的打印：
姓名：刘备 年龄：23 性别：男
姓名：关羽 年龄：22 性别：男
姓名：张飞 年龄：20 性别：男
姓名：赵云 年龄：21 性别：男
姓名：貂蝉 年龄：19 性别：女

排序后的打印：
姓名：貂蝉 年龄：19 性别：女
姓名：张飞 年龄：20 性别：男
姓名：赵云 年龄：21 性别：男
姓名：关羽 年龄：22 性别：男
姓名：刘备 年龄：23 性别：男

*/