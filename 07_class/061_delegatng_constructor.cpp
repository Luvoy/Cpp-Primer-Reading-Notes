//委托构造函数c++11
#include <iostream>
#include <string>
#include <vector>

class Sales_data
{
public:
    Sales_data(std::string s, unsigned int i, double p) : book_number(s), units_sold(i), total_income(i * p)
    {
        std::cout << "I am delegating constructor." << std::endl;
    };
    Sales_data() : Sales_data("", 0, 0){};
    Sales_data(std::string s) : Sales_data(s, 0, 0){};
    Sales_data(std::istream &is) : Sales_data()
    {
        //先执行委托的再执行这里的
        is >> book_number >> units_sold >> total_income;
    }

private:
    std::string book_number;
    unsigned int units_sold = 0;
    double total_income = 0.0;
};

int main(int argc, char const *argv[])
{
    Sales_data s1();
    Sales_data s2("eee");
    Sales_data s3("sec", 33, 2.4);
    Sales_data s4(std::cin);
    return 0;
}
