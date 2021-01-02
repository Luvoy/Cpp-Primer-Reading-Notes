//string的用法
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::string s1;
    std::string s2("hello world"); //s2是这个字面值的副本
    std::string s3 = s2;           //s3是s2的副本
    std::string s4(s2);            //s4是s2的副本
    std::string s5 = "abcdefg";    //s5是这个字面值的副本
    std::string s6(10, '*');

    //用等号的是 拷贝初始化
    //否则都是   直接初始化

    std::cout << "si.empty() = " << s1.empty() << std::endl;
    std::cout << "s1.size()  = " << s1.size() << std::endl;
    std::cout << "s2.empty() = " << s2.empty() << std::endl;
    std::cout << "s2 = " << s2 << ", s2.size()  = " << s2.size() << std::endl;
    std::cout << "s2[s2.size()-1] = " << s2[s2.size() - 1] << std::endl;
    //string 不包括最后的'\0'

    std::cout << "input a string" << std::endl;
    std::cin >> s1; //只输入第一段非空白
    std::cout << "s1 = " << s1 << std::endl;
    return 0;
}
