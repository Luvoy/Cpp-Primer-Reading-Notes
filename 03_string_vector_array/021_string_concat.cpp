//字符串相加时的注意事项
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::string s1 = "Hello";
    std::string s2 = s1 + ","; //正确
    // std::string s3 = "AAA" + "BBB";        //错误，不能把字面值直接相加
    std::string s4 = s1 + "," + " World!"; //正确，从左到右

    //注意字符串字面值并不是标准的string对象
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s4 << std::endl;
    return 0;
}
