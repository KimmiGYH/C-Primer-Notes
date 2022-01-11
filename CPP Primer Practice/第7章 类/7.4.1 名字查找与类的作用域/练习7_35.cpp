/* 练习7.35：解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。
如果代码存在错误，尝试修改它。

【出题思路】
理解名字查找与类的作用域的关系，包括用于类成员声明的名字查找和成员定义中的名字查找。*/

typedef string Type;        // 声明类型别名 Type 表示 string
Type initVal();             // 声明函数 initVal，返回类型是 Type
class Exercise {            // 定义一个新类 Exercise
public:
    typedef double Type;    // 在内层作用域重新声明类型别名 Type 表示 double
    Type setVal(Type);      // 声明函数 setVal，参数和返回值的类型都是 Type
    Type initVal;           // 在内层作用域重新声明函数 initVal，返回类型是 Type
private:
    int val;                // 声明私有数据成员 val
};
                            // 定义函数 setVal，此时的 Type 显然是外层作用域的
Type Exercise::setVal(Type parm) {
    val = parm + initVal(); // 此处使用的是类内的 initVal 函数
    return val;
}


其中，在 Exercise 类的内部，函数 setVal 和 initVal 用到的 Type 都是 Exercise 内部声明的类型别名，对应的实际类型是 double。

在 Exercise 类的外部，定义 Exercise::setVal 函数时形参类型 Type 用的是 Exercise 内部定义的别名，对应 double；
返回类型 Type 用的是全局作用域的别名，对应 string。
使用的 initVal 函数是 Exercise 类内定义的版本。

编译上述程序时在 setVal 的定义处发生错误，
此处定义的函数形参类型是 double、返回值类型是 string，
而类内声明的同名函数形参类型是 double、返回值类型也是 double，
二者无法匹配。

修改的措施是在定义 setVal 函数时使用作用域运算符强制指定函数的返回值类型。

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal(); // 此处使用的是类内的 initVal 函数
    return val;
}