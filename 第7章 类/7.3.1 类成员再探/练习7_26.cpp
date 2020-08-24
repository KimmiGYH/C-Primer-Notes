/* 练习7.26：将 Sales_data::avg_price 定义成内联函数。
【出题思路】
要想把类的成员函数定义成内联函数，有几种不同的途径。
第一种是直接把函数定义放在类的内部，
第二种是把函数定义放在类的外部，并且在定义之前显式地指定 inline。*/

// 隐式内联，把 avg_price 函数的定义放在类的内部：
class Sales_data
{
    public:
    double avg_price() const
    {
        if (units_sold)
            return revenue / units_sold;
        else
            return 0;
    }
};

// 显示内联，把 avg_price 函数的定义放在类的外部，并且指定 inline：
class Sales_data
{
    double avg_price() const;
}
inline double Sales_data:: avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}