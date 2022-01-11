<!-- TOC -->

- [第4章 类与对象](#第4章-类与对象)
  - [面向对象程序的基本特点](#面向对象程序的基本特点)
    - [抽象](#抽象)
    - [封装](#封装)
    - [继承](#继承)
    - [多态](#多态)
  - [类和对象](#类和对象)
    - [类内初始值举例](#类内初始值举例)
    - [对象定义的语法](#对象定义的语法)
    - [内联成员函数](#内联成员函数)
    - [类和对象的程序举例](#类和对象的程序举例)
  - [构造函数](#构造函数)
    - [构造函数基本概念](#构造函数基本概念)
      - [隐含生成的构造函数](#隐含生成的构造函数)
    - [构造函数例题（1）](#构造函数例题1)
    - [构造函数例题（2）](#构造函数例题2)
    - [委托构造函数](#委托构造函数)
    - [复制构造函数](#复制构造函数)
    - [复制构造函数调用举例](#复制构造函数调用举例)
  - [析构函数](#析构函数)
  - [类的组合](#类的组合)
  - [UML 简介](#uml-简介)
  - [结构体和联合体](#结构体和联合体)
  - [枚举类](#枚举类)
  - [小结](#小结)
- [第十一章 流类库与输入/输出](#第十一章-流类库与输入输出)
  - [I/O流的概念及流类库结构](#io流的概念及流类库结构)
    - [流类库结构](#流类库结构)
    - [流类列表](#流类列表)
  - [输出流](#输出流)
    - [输出流概述](#输出流概述)
    - [构造输出流对象](#构造输出流对象)
    - [文件输出流成员函数](#文件输出流成员函数)
    - [操纵符(manipulator)](#操纵符manipulator)
    - [向文本文件输出](#向文本文件输出)
      - [`setioflags`操纵符](#setioflags操纵符)
      - [`setiosflags`的参数（流的格式标识）](#setiosflags的参数流的格式标识)
      - [精度](#精度)
    - [向二进制文件输出](#向二进制文件输出)
    - [向字符串输出](#向字符串输出)
      - [字符串输出流 (`ostringstream`)](#字符串输出流-ostringstream)
  - [输入流](#输入流)
  - [输入/输出流](#输入输出流)
    - [构造输入流对象](#构造输入流对象)
    - [使用提取运算符从文本文件输入](#使用提取运算符从文本文件输入)
    - [输入流相关函数](#输入流相关函数)
  - [小结](#小结-1)

<!-- /TOC -->

# 第4章 类与对象

## 面向对象程序的基本特点

### 抽象

对同一类对象的共同属性和行为进行概括，形成类。

抽象实例——钟表

- 数据抽象：int `hour`, int `minute`, int `second`
- 代码抽象：`setTime()`, `showTime()`

```cpp
// 抽象实例——钟表
class Clock {
public:
    void setTime(int newH, int newM, int newS);
    void showTime();
private:
    int hour, minute, second;
};
```

### 封装

将抽象出的数据、代码封装在一起，形成类。

- 目的：增强安全性和简化变成，使用者不必了解具体的实现细节，而只需要通过外部接口，以特定的访问权限，来使用类的成员。
- 实现封装：类声明中的`{}`

### 继承

- 在已有类的基础上，进行扩展形成新的类。

### 多态

- 多态：同一名称，不同的功能实现方式。
- 目的：达到行为标识统一，减少程序中标识符的个数。

## 类和对象

```cpp
// 类定义的语法形式
class 类名称
{
public:
    公有成员（外部接口）
private:
    私有成员
protected:
    保护型成员
}
```

- 公有类型成员
  - 在关键字`public`后面声明，它们是类与外部的接口，任何外部函数都可以访问公有类型数据和函数。

- 私有类型成员
  - 在关键字`private`后面声明，只允许本类中的函数访问，而类外部的任何函数都不能访问。(例外：友元)
  - 如果紧跟在类名称的后面声明私有成员，则关键字`private`可以省略。

- 保护类型成员
  - 与`private`类似，其差别表现在继承与派生时对派生类的影响不同。

### 类内初始值举例

```cpp
// 类内初始值举例
class Clock {
public:
    void setTime(int newH, int newM, int newS);
    void showTime();
private:
    int hour = 0, minute = 0, second = 0; // 类内初始值
};
```

### 对象定义的语法

类名 对象名;

例：`Clock myClock;`

类中成员之间直接使用成员名互相访问

从类外访问成员使用 “对象名 成员名” 方式访问 `public` 成员

### 内联成员函数

- 为了提高运行时的效率，对于较简单的函数可以声明为内联形式。
- 内联函数体重不要有复杂结构（如循环语句和`switch`语句）。
- 在类中声明内联成员函数的方式：
  - 将函数体放在类的声明中
  - 使用`inline`关键字

### 类和对象的程序举例

**类的定义：**

```cpp
// 类的定义
#include <iostream>
using namespace std;

class Clock {
public:
    void setTime(int newH = 0, int newM = 0, int newS = 0);
    void showTime();
private:
    int hour, minute, second;
}
```

**成员函数的实现：**

```cpp
// 成员函数的实现
void Clock::setTime(int newH, int newM, int newS) {
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime() {
    cout << hour << "." << minute << ":" << second;
}
```

**对象的使用：**

```cpp
int main() {
    Clock myClock;
    myClock.setTime(8, 30, 30);
    myClock.showTime();
    return 0;
}
```

## 构造函数

### 构造函数基本概念

构造函数：类中的特殊函数，用于描述初始化算法。

**构造函数的作用：**

- 在对象被创建时使用特定的值构造对象，将对象**初始化**为一个特定的初始状态。
- 例如：希望在构造一个`Clock`类对象时，将初始时间设为`0:0:0`，就可以通过构造函数来设置。

**构造函数的形式：**

- 函数名与类名相同
- 不能定义返回值类型，也不能有`return`语句
- 可以有形式参数，也可以没有形式参数
- 可以是内联函数
- 可以重载
- 可以带默认参数值

构造函数的调用时机：

在对象创建时被自动调用，例如：`Clock myClock(0, 0, 0);`

下面两个都是默认构造函数，如在类中同时出现，不是合法的函数重载形式，将产生编译错误：

```cpp
Clock();
Clock(int newH = 0, int newM = 0, int newS = 0);
```

#### 隐含生成的构造函数

- 如果程序中未定义构造函数，编译器将自动生成一个**默认构造函数**；
- 参数列表为空，不为数据成员设置初始值；
- 如果类内定义了成员的初始值，则使用类内定义的初始值；
- 如果没有定义类内的初始值，则以默认方式初始化；
- 基本类型的数据默认初始化的值是不确定的。

`=default`

如果程序中已定义构造函数，默认情况下编译器就不再隐含声称默认构造函数。
如果此时依然希望编译器隐含生成默认构造函数，可以使用"`=default`"。

```cpp
class Clock {
public:
    Clock() = default;  // 指示编译器提供默认构造函数
    Clock(int newH, int newM, int newS); // 构造函数
private:
    int hour, minute, second;
};
```

### 构造函数例题（1）

```cpp
// 类定义
class Clock {
public:
    Clock(int newH, int newM, int newS); // 构造函数
    void setTime(int newH, int newM, int newS);
    void showTime();
private:
    int hour, minute, second;
};

// 构造函数的实现：
Clock::Clock(int newH, int newM, int newS) :
    hour(newH), minute(newM), second(newS) { }
// 其他函数实现同例4_1

int main() {
    Clock c(0, 0, 0);   // 自动调用构造函数
    c.showTime();
    return 0;
}
```

### 构造函数例题（2）

```cpp
class Clock {
public:
    Clock(int newH, int newM, int newS); // 构造函数
    Clock(); // 默认构造函数
    void setTime(int newH, int newM, int newS);
    void showTime();
private:
    int hour, minute, second;
};

Clock::Clock():hour(0), minute(0), second(0) { } // 默认构造函数
// 其他函数实现同前

int main() {
    Clock c1(8, 10, 0); // 滴啊用有参数的构造函数
    Clock c2;   // 调用无参数的构造函数
    // ......
}
```

### 委托构造函数

回顾 `Clock`类的两个构造函数：

```cpp
Clock(int newH, int newM, int newS) :
    hour(newH), minute(newM), second(newS) { }  // 构造函数
Clock::Clock() : hour(0), minute(0), second(0) { } // 默认构造函数
```

委托构造函数：

```cpp
// 委托构造函数使用类的其他构造函数执行初始化过程

Clock(int newH, int newM, int newS) :
    hour(newH), minute(newM), second(newS) { }
Clock(): Clock(0, 0, 0) {}
```

### 复制构造函数

复制构造函数是一种特殊的构造函数，其形参为本来的对象引用。
作用是用一个已存在的对象去初始化同类型的新对象。

```cpp
class 类名 {
public:
    类名 (形参); // 构造函数
    类名 (const 类名 &对象名); // 复制构造函数
    // ...
};

类名::类 ( const 类名 &对象名) // 复制构造函数的实现
{ 函数体 }
```

**复制构造函数被调用的三种情况：**

- 定义一个对象时，以本类另一个对象作为初始值，发生复制构造；
- 如果函数的形参是类的对象，调用函数时，将使用实参对象初始化形参对象，发生复制构造；
- 如果函数的返回值是类的对象，函数执行完成返回主调函数时，将使用`return`语句中的对象初始化一个临时无名对象，传递给主调函数，此时发生复制构造。
  - 这种情况也可以通过移动构造避免不必要的复制

未完待续：https://next.xuetangx.com/learn/THU08091000247/THU08091000247/1515741/video/1358673

### 复制构造函数调用举例

## 析构函数

## 类的组合

## UML 简介

## 结构体和联合体

## 枚举类

## 小结

# 第十一章 流类库与输入/输出

## I/O流的概念及流类库结构

### 流类库结构

![image](https://raw.githubusercontent.com/KimmiGYH/PicBed/master/imgs/%E6%B5%81%E7%B1%BB%E5%BA%93%E7%BB%93%E6%9E%84.png)

### 流类列表

| **类名**          | **说明**                                 | **包含文件** |
| ----------------- | ---------------------------------------- | ------------ |
| **抽象流基类**    |                                          |              |
| `ios`             | 流基类                                   | `ios`        |
| **输入流类**      |                                          |              |
| `istream`         | 通用输入流类和其他输入流的基类           | `istream`    |
| `ifstream`        | 文件输入流类                             | `fstream`    |
| `istringstream`   | 字符串输入流类                           | `sstream`    |
| **输出流类**      |                                          |              |
| `ostream`         | 通用输出流类和其他输出流的基类           | `ostream`    |
| `ofstream`        | 文件输出流类                             | `fstream`    |
| `ostringstream`   | 字符输出流类                             | `sstream`    |
| **输入/输出流类** |                                          |              |
| `iostream`        | 通用输入/输出流类和其他输入/输出流的基类 | `istream`    |
| `fstream`         | 文件输入/输出流类                        | `fstream`    |
| `stringstream`    | 字符串输入/输出流类                      | `sstream`    |
| **流缓冲区类**    |                                          |              |
| `streambuf`       | 抽象流缓冲区基类                         | `streambuf`  |
| `filebuf`         | 磁盘文件的流缓冲区类                     | `fstream`    |
| `stringbuf`       | 字符串的流缓冲区类                       | `sstream`    |

## 输出流

最重要的三个输出流：

- `ostream`
- `ofstream`
- `ostringstream`

预先定义的输出流对象：

- `cout`，标准输出。
- `cerr`，标准错误输出，没有缓冲，发送给它的内容立即被输出。
- `clog`，类似于`cerr`，但是有缓冲，缓冲区满时被输出。

`cout`、`cerr`和`clog`是`ostream`的对象；
`cout`处理标准输出，`cerr`和`clog`都处理标准出错信息，只是`cerr`输出不带缓冲，而`clog`输出带缓冲。

### 输出流概述

标准输出换向

```c++
ofstream fout("b.out");
streambuf* pOld = cout.rdbuff(fout.rdbuf());
//...
cout.rdbuf(pOld);
```

### 构造输出流对象

- `ofstream`类支持磁盘文件输出
- 如果在构造函数中指定一个文件名，当构造这个文件时该文件是自动打开的
  - `ofstream myFile("filename");`
- 可以在调用默认构造函数之后使用`open`成员函数打开文件
  - `ofstream myFile;` // 声明一个静态文件输出流对象
  - `myFile.open("filename");` // 打开文件，使流对象与文件建立联系
- 在构造对象或用`open`打开文件时可以指定模式
  - `ofstream myFile("filename", ios_base::out | ios_base::binary);`

### 文件输出流成员函数

- `open`函数
  - 把流与一个特定的磁盘文件关联起来；
  - 需要指定打开模式
- `put`函数
  - 把一个字符写到输出流中
- `write`函数
  - 将内存中的一块内容写到一个文件输出流中
- `seekp`和`tellp`函数
  - 操作文件流的内部指针
- `close`函数
  - 关闭与一个文件输出流关联的磁盘文件
- 错误处理函数
  - 在写到一个流时进行错误处理

### 操纵符(manipulator)

- 出入运算符和操纵符一起工作
  - 控制输出格式
- 很多操纵符都定义在
  - `ios_base`类中（如`hex()`、`<iomanip>`头文件（如`setprecision()`）。
- 控制输出宽度
  - 在流中放入`setw`操纵符或调用`width`成员函数为每个项指定输出宽度。
- `setw`和`width`仅影响紧随其后的输出项，但其他流格式操纵符保持有效直到发生改变。
- `dec`、`oct`和`hex`操纵符设置输入和输出的默认进制。

### 向文本文件输出

#### `setioflags`操纵符

- 这个程序中，通过使用带参数的`setiosflags`操纵符来设置左对齐，`setiosflags`定义在头文件`iomanip`中。
- 参数`ios_base::left`是`ios_base`的静态常量，因此引用时必须包括`ios_base::`前缀。
- 这里需要用`resetiosflags`操纵符关闭左对齐标志。`setiosflags`不同于`widht`和`setw`，它的影响力是持久的，直到用`resetiosflags`重新恢复默认值时为止。
- `setiosflags`的参数是该流的格式标志值，可用按位或(`|`)运算符进行组合。

#### `setiosflags`的参数（流的格式标识）

- `ios_base::skipws` 在输入中跳过空白。
- `ios_base::left` 左对齐值，用填充字符填充右边。
- `ios_base::right` 右对齐值，用填充字符填充左边（默认对齐方式）。
- `ios_base::internal` 在规定的宽度内，指定前缀符号之后，数值之前，插入指定的填充字符。
- `ios_base::dec` 以十进制形式格式化数值（默认进制）。
- `ios_base::oct` 以八进制形式格式化数值 。
- `ios_base::hex` 以十六进制形式格式化数值。
- `ios_base::showbase` 插入前缀符号以表明整数的数制。
- `ios_base::showpoint` 对浮点数值显示小数点和尾部的`0`。
- `ios_base::uppercase` 对于十六进制数值显示大写字母`A`到`F`，对于科学格式显示大写字母`E` 。
- `ios_base::showpos` 对于非负数显示正号（“`+`”）。
- `ios_base::scientific` 以科学格式显示浮点数值。
- `ios_base::fixed` 以定点格式显示浮点数值（没有指数部分）。
- `ios_base::unitbuf` 在每次插入之后转储并清除缓冲区内容。

#### 精度

浮点数输出精度的默认值是`6`，例如：`3466.98`。

要改变精度：`setprecision`操纵符（定义在头文件`iomanip`中）。

如果不指定`fixed`或`scientific`，精度值表示有效数字位数。

如果设置了`iosbase::fixed`或`iosbase::scientific`精度值表示小数点之后的位数。

**例11-1：使用`width`控制输出宽度**

```c++
// 例11-1：使用 width 控制输出宽度
#include <iostream>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    for (int i = 0; i < 4; i++) {
        cout.width(10);
        cout << values[i] << endl;
    }
    return 0;
}

/*输出：
      1.23
     35.36
     653.7
   4358.24
*/
```

**例11-2：使用 `setw` 操纵符指定宽度**

```cpp
// 例11-2：使用 setw 操纵符指定宽度

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    for (int i = 0; i < 4; i++)
        cout << setw(6) << names[i] << setw(10) << values[i] << endl;
    return 0;
}

/*Output:
  Zoot      1.23
 Jimmy     35.36
    AI     653.7
  Stan   4358.24
*/
```

**例11-3：设置对齐方式：**

```cpp
// 例11-3：设置对齐方式

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    for (int i = 0; i < 4; i++)
        cout << setiosflags(ios_base::left) // 左对齐
             << setw(6) << names[i]
             << resetiosflags(ios_base::left) // 将左对齐的设置取消 将回到右对齐的方式
             << setw(10) << values[i] << endl;
        return 0;
}
/*
Zoot        1.23
Jimmy      35.36
AI         653.7
Stan     4358.24
*/
```

**例11-4 控制输出精度——未指定`fixed`或`scientific`**

```cpp
// 例11-4 控制输出精度——未指定`fixed`或`scientific`

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    for (int i = 0; i < 4; i++)
        cout << setiosflags(ios_base::left)
             << setw(6) << names[i]
             << resetiosflags(ios_base::left) // 清除左对齐设置
             << setw(10) << setprecision(1) << values[i] << endl;
        return 0;
}

/*
Zoot           1
Jimmy     4e+001
AI        7e+002
Stan      4e+003
*/
```

### 向二进制文件输出

- 使用`ofstream`构造函数中的模式参量指定二进制输出模式；
- 以通常方式构造一个流，然后使用`setmode`成员函数，在文件打开后改变模式；
- 通过二进制文件输出流对象完成输出。

**例11-5：向二进制文件输出:**

```cpp
// 例11-5：向二进制文件输出

#include <fstream>
using namespace std;

struct Date {
    int mon, day, year;
};

int main() {
    Date dt = {6, 10, 92};
    ofstream file("date.dat", ios_base::binary);
    file.write(reinterpret_cast<char*>(&dt), sizeof(dt));
    file.close();
    return 0;
}
```

### 向字符串输出

#### 字符串输出流 (`ostringstream`)

- 用于构造字符串
- 功能
  - 支持`ofstream`类的除`open`, `close`外的所有操作
  - `str`函数可以返回当前已构造的字符串
- 典型应用
  - 将数值转换为字符串

## 输入流

- `istream`类最适合用于顺序文本模式输入。`cin`是其实例。
- `ifstream`类支持磁盘文件输入
- `istringstream`

## 输入/输出流

### 构造输入流对象

- 如果在构造函数中指定一个文件名，在构造该对象时该文件便自动打开。`ifstream myFile("filename");`
- 在调用默认构造函数之后使用`open`函数来打开文件。
  
  `ifstream myFile;`  // 建立一个文件流对象
  `myFile.open("filename");`  // 打开文件"filename"
  
- 打开文件时可以指定模式
  `ifstream myFile("filename", ios_base::in | ios_base::binary);`

### 使用提取运算符从文本文件输入

- 提取运算符(`>>`)对于所有标准C++数据类型都是预先设计好的。
- 是从一个输入流对象获取字节最容易的方法。
- `ios`类中的很多操纵符都可以应用于输入流。但是只有少数几个对输入流对象具有实际影响，其中最重要的是进制操纵符`dec`、`oct`和`hex`。

### 输入流相关函数

- `open` 把该流与一个特定磁盘文件相关联。
- `get` 功能与提取运算符（`>>`）很相像，主要的不同点是`get`函数在读入数据时包括空白字符。
- `getline` 功能是从输入流中读取多个字符，并且允许指定输入终止字符，读取完成后，从读取的内容中删除终止字符。
- `read` 从一个文件读字节到一个指定的内存区域，由长度参数确定要读的字节数。当遇到文件结束或者在文本模式文件中遇到文件结束标记字符时结束读取。
- `seekg` 用来设置文件输入流中读取数据位置的指针。
- `tellg` 返回当前文件读指针的位置。
- `close` 关闭与一个文件输入流关联的磁盘文件。

## 小结
