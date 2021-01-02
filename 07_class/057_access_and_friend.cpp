//访问和封装控制
#include <string>
#include <iostream>
class Sales_data //用class，在第一个访问说明符之前的都是private
//struct Sales_data //用struct，在第一个访问说明符之前的都是public
{
    friend std::istream &read(std::istream &is, Sales_data &item);        //声明为友元函数，就可以不受访问限制
    friend std::ostream &print(std::ostream &os, const Sales_data &item); //类内任何位置声明都可以
    friend Sales_data add(const Sales_data &s1, const Sales_data &s2);

public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double single_price) : book_number(s), units_sold(n), total_income(single_price * n){};
    Sales_data(const std::string &s) : book_number(s){};
    Sales_data(std::istream &is) { is >> book_number >> units_sold >> total_income; }

    std::string isbn() const { return book_number; }
    Sales_data &combine(const Sales_data &s)
    {
        this->units_sold += s.units_sold;
        this->total_income += s.total_income;
        return *this;
    }

private:
    double avg_price() const { return units_sold ? total_income / units_sold : 0; }
    std::string book_number;
    unsigned int units_sold = 0;
    double total_income = 0.0;
};

//除了类内部的友元函数声明，函数还需要在类外声明
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &sd1, const Sales_data &sd2);
//非成员函数定义
std::istream &read(std::istream &is, Sales_data &item)
{
    std::cout << "Please input an item of sales data: book_number, units_sold, single_price" << std::endl;
    double price = 0;
    is >> item.book_number >> item.units_sold >> price;
    item.total_income = price * item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << "ISBN: " << item.isbn() << ", units_sold: " << item.units_sold << " total_income: " << item.total_income << ", avg_price: " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &sd1, const Sales_data &sd2)
{
    Sales_data ret = sd1; //拷贝
    ret.combine(sd2);
    return ret;
}
int main(int argc, char const *argv[])
{
    Sales_data s1;
    Sales_data s2("3123", 3, 1.5);
    Sales_data s3(std::cin);

    // std::cout << s1.book_number << std::endl;//不能访问private
    print(std::cout, s1);
    std::cout << std::endl;
    print(std::cout, s2);
    std::cout << std::endl;
    print(std::cout, s3);
    std::cout << std::endl;
    return 0;
}
