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

## 输出流

最重要的三个输出流：

- `ostream`
- `ofstream`
- `ostringstream`

预先定义的输出流对象：

- `cout`，标准输出。
- `cerr`，标准错误输出，没有缓冲，发送给它的内容立即被输出。
- `clog`，类似于`cerr`，但是有缓冲，缓冲区满时被输出。

### 输出流概述



## 输入流

## 输入/输出流

## 小结