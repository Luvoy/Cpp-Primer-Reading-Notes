//string还有其他的构造方法
//string的substr
//append
//replace
//TODO 这些都很简单

#include <string>
#include <iostream>
int global_1 = 1;
int main(int argc, char const *argv[])
{
    //find_first_of
    std::string nums("0123456789");

    std::string s1 = "8wefwe7sfs3hkhkf0fewf8sdgsgewg5wge7wefw5seg1";

    std::string::size_type pos = 0;
    while ((pos = s1.find_first_of(nums, pos)) != std::string::npos) //从pos处开始找
    {
        std::cout << "Found number at index: " << pos << ", element is: " << s1[pos] << std::endl;
        ++pos;
    } //类似的还有find_first_not_of, find_last_of, find_last_not_of

    //compare
    std::string s2 = "12aard34soe";
    const char *s3 = "2aard84owi";

    std::cout << s2.compare(1, 6, s3, 6) << std::endl; // 2aard3 和 2aard8 比较

    /////////////////////////////////
    //数值转换
    std::string s4 = "pi = 3.14";
    auto pi = std::stod(s4.substr(s4.find_first_of("+-.0123456789")));
    std::cout << pi << std::endl;

    static int a = 1;
    constexpr int *p1 = &a;
    constexpr int *p2 = &global_1; //TODO 这里p1 p2不能用to_string
    std::cout << std::string("a = ").append(std::to_string(a)) << std::endl;
    std::cout << std::string("global_1 = ") + std::to_string(global_1) << std::endl;

    std::string s5 = "0xAf.1e";
    std::string s6 = "0e0";
    std::string s7 = ".001e-3";

    double d1 = std::stod(s5);
    double d2 = std::stod(s6);
    double d3 = std::stod(s7);
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << ", d3 = " << d3 << std::endl;
    return 0;
}
