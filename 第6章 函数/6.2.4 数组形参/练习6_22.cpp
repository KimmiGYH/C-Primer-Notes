/* 练习6.22：编写一个函数，令其交换两个 int 指针。

【出题思路】有两种理解：
一种是交换指针本身的值，即指针所指的内存地址；另一种是交换指针所指的内容。*/

#include <iostream>
using namespace std;

/* 第一个函数以值传递的方式使用指针，所有改变都局限于函数内部，
当函数执行完毕后既不会改变指针本身的值，也不会改变指针所指的内容。*/
// 该函数既不交换指针，也不交换指针所指的内容
void SwapPointer1(int *p, int *q)
{
    int *temp = p;
    p = q;
    q = temp;
}

/* 第二个函数同样以值传递的方式使用指针，
但是在函数内部通过 解引用 的方式直接访问内存并修改了指针所指的内容。*/
// 该函数交换指针所指的内容
void SwapPointer2(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

/* 第三个函数的参数形式是 int *&，其含义是，该参数是一个引用，引用的对象是内存中的一个 int 指针，
使用这种方式可以把指针当成对象，交换指针本身的值。
需要注意的是，最后一个函数既然交换了指针，当然解引用该指针所得的结果也会相应发生改变。*/
// 该函数交换指针本身的值，即交换指针所指的内存地址
void SwapPointer3(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
}


int main()
{
    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "Before the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;
    SwapPointer1(p, q);
    cout << "After the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;

    /*
    Before the exchange: 
    The value of p is: 0x61ff04, the value of q is: 0x61ff00
    p is pointing to: 5, q is pointing to: 10
    After the exchange: 
    The value of p is: 0x61ff04, the value of q is: 0x61ff00
    p is pointing to: 5, q is pointing to: 10
    */


    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "Before the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;
    SwapPointer2(p, q);
    cout << "After the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;

    /*
    Before the exchange: 
    The value of p is: 0x61ff04, the value of q is: 0x61ff00
    p is pointing to: 5, q is pointing to: 10
    After the exchange: 
    The value of p is: 0x61ff04, the value of q is: 0x61ff00
    p is pointing to: 10, q is pointing to: 5
    */


    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "Before the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;
    SwapPointer3(p, q);
    cout << "After the exchange: " << endl;
    cout <<"The value of p is: " << p << ", the value of q is: " << q << endl;
    cout << "p is pointing to: " << *p << ", q is pointing to: " << *q << endl;

    /*
    Before the exchange: 
    The value of p is: 0x61ff0c, the value of q is: 0x61ff08
    p is pointing to: 5, q is pointing to: 10
    After the exchange: 
    The value of p is: 0x61ff08, the value of q is: 0x61ff0c
    p is pointing to: 10, q is pointing to: 5
    */

    return 0;
}