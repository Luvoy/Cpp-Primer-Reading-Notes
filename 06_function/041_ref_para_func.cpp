//引用传参
//一般的形参parameter
//和实参argument是独立的
//修改形参，实参不受影响

#include <iostream>
bool str1_is_shorter_than_str2(const std::string &str1, const std::string &str2)
{
    return str1.size() < str2.size();
}
//尽量使用引用
//引用可以直接修改，不修改就传指向const的引用
//传统的拷贝赋值，对一些类对象会有很大的开销

int main(int argc, char const *argv[])
{
    std::cout << "\"Hello\" is shorter than \"World\"? " << (str1_is_shorter_than_str2("Hello", "World") ? "True" : "False") << "." << std::endl;
    return 0;
}
