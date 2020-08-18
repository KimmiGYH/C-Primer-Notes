string buf;
while (cin >> buf && !buf.empty()) {
    switch(buf[0]) {
        case '-':
            // 处理到第一个空白为止
            for (auto it = buf.begin()+1; it != buf.end(); ++it) {
                if (*it == ' ')
                    break;  // #1，离开for循环
                // ...
            }
            // break #1 将控制权转移到这里
            // 剩余的'-'处理：
            break;  // #2，离开switch 语句
        case '+':
            // ...
    }   // 结束 switch
    // 结束 switch: break #2 将控制权转移到这里
} // 结束 while