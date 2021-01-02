//范围for(declaration: serizable_expression)
#include <iostream>
#include <string>
#include <cctype>
int main(int argc, char const *argv[])
{
    //遍历
    std::string s1("I love you.");
    for (auto c : s1)
    {
        std::cout << c << std::endl;
    }

    //统计标点个数
    std::string s2("QWER,./;'[]<>?:\"{}!@#$%%^&*()-=_+");
    decltype(s2.size()) punct_count = 0;
    for (auto c : s2)
    {
        if (ispunct(c))
            ++punct_count;
    }
    std::cout << "In string \"" << s2 << "\": " << punct_count << "punctuations, " << s2.size() << " characters." << std::endl;

    //修改为大写
    std::string s3("Hello World");
    for (auto c : s3)
        c = toupper(c);
    std::cout << s3 << std::endl;

    for (auto &c : s3)
        c = toupper(c);
    std::cout << s3 << std::endl;

    //修改第一个词
    s3 = "the form should be filled";
    for (decltype(s3.size()) index = 0; index != s3.size() && !isspace(s3[index]); ++index)
    {
        s3[index] = toupper(s3[index]);
    }
    std::cout << s3 << std::endl;

    //下标越界测试
    std::cout
        << "s3[-1]: " << s3[-1] << std::endl; //[]中间的索引，会自动转换成std::string::size_type
    std::cout << "s3[s3.size()]: " << s3[s3.size()] << std::endl;
    std::string s4;
    std::string s5 = "";
    std::cout << "s4.empty(): " << s4.empty() << std::endl;
    std::cout << "s5.empty(): " << s5.empty() << std::endl;
    std::cout << "s4[0]: " << s4[0] << std::endl;

    //const string测试
    const std::string s6 = "qwertyuiop";
    for (auto &c : s6)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
