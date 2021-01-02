//编写函数，接收一个istream&参数,返回 也是这个.从给定流中读取数据，直至文件结束
//将读取的数据打印在标准输出上，返回流之前看，对流复位
#include <iostream>
std::istream &read_print_till_eof(std::istream &is)
{
    // std::cout << "std::ios_base::eofbit is " << std::ios_base::eofbit << std::endl;
    std::string s;
    while (!((is >> s).eof()))
    {
        // std::cout << "state is " << is.rdstate() << std::endl;
        std::cout << s << std::endl;
    }
    is.clear();
    return is;
}

int main(int argc, char const *argv[])
{
    read_print_till_eof(std::cin);
    std::cout << "std::cin.bad() is " << std::cin.bad() << std::endl;
    std::cout << "std::cin.fail() is " << std::cin.fail() << std::endl;
    std::cout << "std::cin.eof() is " << std::cin.eof() << std::endl;
    std::cout << "std::cin.good() is " << std::cin.good() << std::endl;
    read_print_till_eof(std::cin);
    return 0;
}
