//反向迭代器
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::string s1 = "FIRST,MIDDLE,LAST";
    auto r_comma = std::find(s1.crbegin(), s1.crend(), ',');
    std::cout << std::string(s1.crbegin(), r_comma) << std::endl; //TSAL

    //应该使用base成员函数来把一个r迭代器转换成正向的
    std::cout << std::string(r_comma.base(), s1.cend()) << std::endl; //LAST

    std::reverse_iterator<std::string::const_iterator> b(s1.cbegin()); //r迭代器可以用正向的初始化
    //正向的可以用r.base()得到

    return 0;
}
