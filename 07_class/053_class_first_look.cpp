//Sales_data类
#include <string>

struct Sales_data
{
    std::string isbn() const
    //成员函数有一个隐式的形参this，用来访问当前对象
    //准确来说this存放了调用这个函数的当前的对象的地址，是一个顶层const指针
    //成员函数的()后面跟const，是给this添加底层const,叫做常量成员函数
    //      (因为不能用底层const初始化非底层const,即this不能指向const Sales_data，进而对于一个const对象，用成员函数不能取得成员数据

    {                       //定义在类内部的函数是隐式的inline
        return book_number; //等价于this->book_number
        //虽然book_number在后面，但是整个类都是一个scope
    }

    Sales_data &combine(const Sales_data &); //成员函数声明
    double avg_price() const;                //成员函数声明

    //数据成员：
    std::string book_number;
    unsigned int units_sold = 0;
    double total_income = 0.0;

}; //不要落下分号！

Sales_data add(const Sales_data &, const Sales_data &);  //声明非成员函数，将两条销售记录相加
std::ostream &print(std::ostream &, const Sales_data &); //声明非成员函数，打印输出一条销售记录
std::istream &read(std::istream &, Sales_data &);        //声明非成员函数， 从输入读取一条销售记录
//这些声明和类有关系，应该和类声明放在一个h文件中

//所有成员都必须在类中声明，但是成员函数定义既可以在类中，也可以在类外

//成员函数定义，一定要保持一致, 并且前面加上类名::
double avg_price() //这个函数不是成员函数
{
    return 1.1;
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return total_income / units_sold;
    else
        return 0;
}

//定义返回this对象的函数
Sales_data &Sales_data::combine(const Sales_data &to_be_add)
{
    this->units_sold += to_be_add.units_sold;
    total_income += to_be_add.total_income;
    return *this; //this是指针，*this是引用
}

//非成员函数定义
#include <iostream>
std::istream &read(std::istream &is, Sales_data &item)
{
    std::cout << "Please input an item of sales data: book_number, units_sold, single_price" << std::endl;
    double price = 0;
    is >> item.book_number >> item.units_sold >> price;
    item.total_income = price * item.units_sold;
    return is;
}
//IO类型不能拷贝，所以这里接收引用
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
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data temp;
        while (read(std::cin, temp))
        {
            if (total.isbn() == temp.isbn())
            {
                total.combine(temp);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = temp;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}
