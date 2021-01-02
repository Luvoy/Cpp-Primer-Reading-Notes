//值如何被返回的？
//返回的值用于初始化那个调用点的临时量

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
std::string my_str_concat(const std::string &s1, const std::string &s2)
{
    return s1 + s2; //可以返回一个未命名的临时string对象
}

const std::string &shorter_str(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size() ? s1 : s2; //返回const引用，不管调用还是返回都不会发生拷贝
}

//不要返回局部对象的引用或者指针
const std::string &func(int a)
{
    std::string ret = "Hello";
    if (a)
        return ret; //当函数结束，这变量的生命周期就结束了
    else
        return "World"; //两条返回都将指向不可用的内存空间
}

//返回左值
char &get_char_at_index(std::string &s, std::string::size_type i)
{ //注意参数也要传引用
    return s[i];
}

//列表初始化返回值
std::vector<std::string> func2(int a)
{
    std::string s1 = "AAA";
    if (!a)
        return {}; //按照类定义进行初始化
    else if (a == 1)
        return {"hello", "world"};
    else
        return {"333", s1};
}

int func3(int a)
{
    return {a}; //内置类型也可以返回列表，只能写一个
}

int main(int argc, char const *argv[])
{
    // std::cout << func(1) << func(2) << std::endl;//segmentaion fault
    std::string s1("Hello");
    std::cout << "before change, s1 = " << s1 << std::endl;
    get_char_at_index(s1, 0) = 'P';
    std::cout << "after change, s1 = " << s1 << std::endl;

    //
    void show_vector(const std::vector<std::string> &vs); //declaration
    std::vector<std::string> vs_1 = func2(1);
    show_vector(vs_1);
    std::vector<std::string> vs_2 = func2(2);
    show_vector(vs_2);
    //
    //主函数的返回值，为了与机器无关：
    return EXIT_SUCCESS; //#include<cstdlib>
    // return EXIT_FAILURE;
}
void show_vector(const std::vector<std::string> &vs)
{
    for (const auto &i : vs)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
