# C++编程

## 1. 简介

### Object Based (基于对象) vs. Object Oriented (面向对象)

**基于对象 Object Based：**

(面对的是单一 class 的设计)

- 以良好的方式编写 C++ class
  - class without pointer members
    - Complex
  - class with pointer members
    - String

**面向对象 Object Oriented：**

(面对的是多重 classes 的设计，classes 和 classes 之间的关系。)

- 学习 Classes 之间的关系
  - 继承 (inheritance)
  - 复合 (composition)
  - 委托 (delegation)

## 2. 头文件与类的声明

### 2.1 Output, C++ vs. C

```cpp
// C++ 程序
#include <iostream>
using namespace std;

int main()
{
    int i = 7;
    cout << "i=" << i << endl;

    return 0;
}
```

```c
// C 程序
#include <cstdio>
// #include <stdio.h>

int main()
{
    int i = 7;
    printf("i=%d \n", i);

    return 0;
}
```

### 2.2 `Heder`(头文件)中的防卫式声明

写任何一个头文件都要加防卫式声明。

```cpp
// complex.h
#ifndef __COMPLEX__
#define __COMPLEX__

/*...*/

#endif
```

```cpp
// complex-test.h
#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex c1(2, 1);
    complex c2;
    cout << c1 << endl;
    cout << c2 << endl;

    c2 = c1 + 5;
    c2 = 7 + c1;
    c2 = c1 + c2;
    c2 += c1;
    c2 += 3;
    c2 = -c1;

    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    cout << conj(c1) << endl;
    return 0;
}
```

### 2.3 `Header`(头文件)的布局

```cpp
#ifndef __COMPLEX__
#define __COMPLEX__

// 0: forward declarations (前置声明)
#include <cmath>

class ostream;
class complex;

complex&
  __doapl (complex* ths, const complex& r);

// 1: class declarations (类 - 声明)
class complex
{
    /*...*/
};

// 2: class definition
complex::function...

#endif
```

## 3. 构造函数

### 3.1 class 的声明 (declaration)

```cpp
class complex   // class head
{               // class body
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

{
    complex c1(2, 1);
    complex c2;
    // ...
}
```

### 3.2 class template (模板)简介

```cpp
template<typename T>
class complex
{
public:
    compolex (T r = 0, T i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    T real () const { return re; }
    T imag () const { return im; }
private:
    T re, im;

    friend complex& __doapl (complex*, const complex&);
};

{
    complex<double> c1(2.5, 1.5);
    complex<int> c2(2, 6);
    // ...
}
```

### 3.3 inline (内联)函数

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    // 函数若在 class body 内定义完成，便自动成为 inline 候选人
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

inline double
imag(const complex& x)
{
    return x.imag ();
}
```

### 3.4 access level (访问级别)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    // 函数若在 class body 内定义完成，便自动成为 inline 候选人
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

// 不合法，因为 re 和 im 都在 private 里面
{
    complex c1(2,1);
    cout << c1.re;
    cout << c1.im;
}

// 合法
{
    complex c1(2, 1);
    cout << c1.real();
    cout << c1.imag();
}
```

### 3.5 constructor (ctor, 构造函数)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)  // default argument (默认实参)
        : re (r), im (i)    // initialization list (初值列，初始列)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

{
    complex c1(2, 1);
    complex c2;
    complex* p = new complex(4);
    // ...
}
```

注意，下面的写法虽然也对，但是不够好：
上面的初始化了，而下面的虽然可以但效率上差一些。

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)    // assignment (赋初值)
    { }
    // ...
};
// ...
```

### 3.6 ctor(构造函数) 可以有很多个 -overloading (重载)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex () : re(0), im(0) { } // ?!
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

void real(double r) { re = r; }

{
    complex c1;
    complex c2();
    // ...
}
```

## 4. 参数传递与返回值

### 4.1 `ctor`放在`private`区

```cpp
// // Singleton 把构造函数放在 Singleton 里
class A {
public:
    static A& getInstance();
    setup() { ... }
private:
    A();
    A(const A& rhs);
    // ...
};

A& A::getInstance()
{
    static A a;
    return a;
}
```

### 4.2 const member functions (常量成员函数)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl(complex*, const complex);
};

{ // O 可以
    complex c1(2, 1);
    cout << c1.real();
    cout << c1.imag();
}
```

```cpp
// ?! 一定要在前面加 const 修饰函数
{
    const complex c1(2, 1);
    cout << c1.real();
    cout << c1.imag();
}
```

### 4.3 参数传递：pass by value vs. pass by reference (to const)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    doulbe re, im;

    friend complex& __doapl (complex*, const complex&);
};

ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real (x) << ','
              << imag (x) << ')';
}

{
    complex c1(2, 1);
    complex c2;

    c2 += c1;
    cout << c2;
}
```

### 4.4 friend (友元)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

// 自由取得 friend 的 private 成员
inline complex&
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
```

### 4.5 相同 class 的各个 objects 互为 friends (友元)

```cpp
class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }

    int func(const complex& param)
    { return param.re + param.im; }

private:
    double re, im;
};

{
    complex c1(2, 1);
    complex c2;

    c2.func(c1);
}
```

### 4.6 class body 外的各种定义(definitions)

什么情况下可以 pass by reference
什么情况下可以 return by reference

**do assignment plus:**

```cpp
inline complex&
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;    // 第一参数将会被改动
    ths->im += r.im;    // 第二参数不会被改动
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl (this, r);
}
```

## 5. 操作符重载与临时对象

### 5.1 operator overloading (操作符重载-1，成员函数) `this`

```cpp
inline complex&
__doapl(complex* ths, const complex& r)
{
    ths->re ++ r.re;
    ths->im ++ r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
// complex::operator += (this, const complex& r)
// 其实隐藏了 this
{
    return __doapl (this, r);
}

{
    complex c1(2,1);
    complex c2(5);

    c2 += c1;
}
```

### 5.2 return by reference 语法分析

传递着无须知道接受者是以`reference`形式接收

```cpp
inline complex&
__doapl(complex* ths, const complex& r)
{
    // ...
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl(this, r);
}

{
    complex c1(2,1);
    complex c2(5);
    c2 += c1;
}
// 连串加上去
{
    c3 += c2 += c1;
}
```

### 5.3 class body 之外的各种定义(definitions)

```cpp
inline double
imag(const complex& x)
{
    return x.imag ();
}

inline double
real(const complex& x)
{
    return x.real ();
}

{
    complex c1(2, 1);
    cout << imag(c1);
    cout << real(c1);
}
```

### 5.4 operator overloading (操作符重载-2，非成员函数) (无 this)

```cpp
inline complex
operator + (const complex& x, const complex& y)
{
    return complex (real (x) + real (y),
                    imag (x) + imag (y));
}

inline complex
operator + (const complex&, double y)
{
    return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real (y), imag (y));
}

{
    complex c1(2, 1);
    complex c2;

    c2 = c1 + c2;
    c2 = c1 + 5;
    c2 = 7 + c1;
}
```

### 5.5 temp object (临时对象) typename();

下面这些函数绝不可 return by reference，因为它们返回的必定是个 local object

```cpp
inline complex
operator + (const complex& x, const complex& y)
{
    return complex (real (x) + real (y),
                    imag (x) + imag (y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real (y), imag (y));
}

{
    int(7);

    complex c1(2,1);
    complex c2;
    complex();
    complex(4,5);

    cout << complex(2);
}
```

### 5.6 class body 之外的各种定义 (definitions)

```cpp
// inline complex
inline complex&
operator + (const complex& x)
{
    return x;
}

inline complex
operator - (const complex& x)
// 这个函数绝不可 return by reference, 因为其返回的必定是个 local object
{
    return complex (-real (x), -imag (x)); // 临时对象
}

{
    complex c1(2, 1);
    complex c2;
    cout << -c1;
    cout << +c1;
}
```

### 5.7 operator overloading (操作符重载)，非成员函数

```cpp
inline bool
operator == (const complex& x,
            const complex& y)
{
    return real (x) == real (y)
        && imag (x) == imag (y);
}

inline bool
operator == (const complex& x, double y)
{
    return real (x) == y && imag (x) == 0;
}

inline bool
operator == (double x, const complex& y)
{
    return x == real (y) && imag (y) == 0;
}

{
    complex c1(2, 1);
    complex c2;

    cout << (c1 == c2);
    cout << (c1 == 2);
    cout << (0 == c2);
}
```

```cpp
inline bool
operator != (const complex& x,
            const complex& y)
{
    return real (x) == real (y)
        && imag (x) == imag (y);
}

inline bool
operator != (const complex& x, double y)
{
    return real (x) == y && imag (x) == 0;
}

inline bool
operator != (double x, const complex& y)
{
    return x == real (y) && imag (y) == 0;
}

{
    complex c1(2, 1);
    complex c2;

    cout << (c1 != c2);
    cout << (c1 != 2);
    cout << (0 != c2);
}
```

```cpp
// 共轭复数：实部相等，虚部正负号相反
inline complex
conj (const complex& x)
{
    return complex (real (x), -imag (x));
}

#include <iostream.h>
ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real (x) << ','
              << imag (x) << ')';
}

{
    complex c1(2, 1);
    cout << conj(c1);
    cout << c1 << conj(c1);
}
```

## 6. 复习`Complex`类的实现过程

```cpp
#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
public:
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    { }
    complex& operator += (const complex&);
    double real () { return re; }
    double imag () { return im; }
private:
    double re, im;

    friend complex& __doapl (complex*, const complex&);
};

inline complex&
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl (this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex ( real (x) + real (y),
                     imag (x) + imag (y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex (rela (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real (y), imag (y));
}

#include <iostream>

ostream&
operator << (ostream& os,
             const complex& x)
{
    return os << '(' << real (x) << ',' << imag (x) << ')';
}

complex c1(9, 8);
cout << c1;

cout << c1 << endl;

#endif
```
