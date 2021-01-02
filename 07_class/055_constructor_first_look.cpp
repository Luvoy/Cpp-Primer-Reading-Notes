//构造函数
//没有构造函数时，编译器会自动合成默认构造函数
//此时，有初始值的成员用初始值，没有初始值的成员默认初始化（块内的基本类型，初始化是未定义的）
#include <string>
struct Sales_data
{

    Sales_data() = default; //默认构造函数, 这里是声明+定义，也可以只声明，放在外面定义
    // Sales_data(); //只声明默认构造函数
    Sales_data(const std::string &s) : book_number(s) {} //声明+定义，没给的成员，和默认构造函数一样的方式去初始化
    Sales_data(const std::string &s, unsigned int n, double p) : book_number(s), units_sold(n), total_income(p * n) {}
    Sales_data(std::istream &);

    std::string isbn() const
    // std::string Sales_data::isbn() const//类内就不要加Sales_data::了
    {
        return book_number;
    }
    Sales_data &combine(const Sales_data &to_be_add)
    {
        this->units_sold += to_be_add.units_sold;
        total_income += to_be_add.total_income;
        return *this; //this是指针，*this是引用
    }
    double avg_price() const
    {
        if (units_sold)
            return total_income / units_sold;
        else
            return 0;
    }

    std::string book_number;
    unsigned int units_sold = 0;
    double total_income = 0.0;
};

// Sales_data::Sales_data() = default;//定义默认构造函数
//定义构造函数
#include <iostream>
Sales_data::Sales_data(std::istream &is)
{
    double price = 0.0;
    is >> (this->book_number) >> (this->units_sold) >> price;
    this->total_income = price * (this->units_sold);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
