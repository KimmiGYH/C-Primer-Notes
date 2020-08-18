/* 练习5.18：说明下列循环的含义并改正其中的错误。*/

// (a) 应该把循环体的内容用花括号括起来

do {
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
} while (cin);


// (b) do-while 语句不允许在循环条件内定义变量

int ival;
do {
    ival = get_response();
} while (ival);


// (c) 出现在 do-while 语句条件部分的变量必须定义在循环体之外

int ival;
do {
    ival = get_response();
} while (ival);
