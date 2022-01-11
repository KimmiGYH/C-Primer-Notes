while (cin >> item1 >> item2)
{
    try {
        // 执行添加两个 Sales_item 对象的代码
        // 如果添加失败，代码抛出一个 runtime_error 异常
    } catch (runtime_error err) {
        // 提醒用户两个 ISBN 必须一致，询问是否重新输入
        cout << err.what() << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c == 'n')
            break;  // 跳出 while 循环
    }
}

`runtime_error`的`what`成员返回的是初始化一个具体对象时所用的`string`对象的副本。
如果上一节编写的代码抛出异常，则本节的`catch`子句输出：

Data must refer to same ISBN
Try Again? Enter y or n