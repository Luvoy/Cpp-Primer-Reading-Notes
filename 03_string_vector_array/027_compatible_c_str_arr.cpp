//和c风格字符串兼容
//用数组初始化vector
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cctype>
#include <cstring>
int main(int argc, char const *argv[])
{
    //允许用c风格字符串初始化string对象
    std::string s1 = "Hello";
    std::string s2("world");
    std::cout << s1 << std::endl;

    //允许用以'\0'结尾的字符数组来初始化string或赋值
    char char_arr_1[] = {'C', 'a', 'n', 'a', 'd', 'a', '\0'};
    s1 = char_arr_1;
    std::cout << s1 << std::endl;

    char char_arr_2[] = {'A', 'm', 'e', 'r', 'i', 'c', 'a'}; //不是\0结尾，变成了在前面插入
    s1 = char_arr_2;
    std::cout << s1 << std::endl;

    //在string的加法运算中，允许其中一个是'\0'
    s2 = s1 + "China" + "Japan";
    std::cout << s2 << std::endl;

    std::string s3 = char_arr_1 + s1;
    std::cout << s3 << std::endl;

    // s3 = char_arr_1 + char_arr_2;//错误

    //string的成员函数c_str()返回c风格的字符串const char*
    const char *str = s1.c_str();
    std::cout << str << std::endl;
    s1 += "eee"; //后续操作改变s1，那么用c_str()得到的结果可能失效
    s1[3] = '*';
    std::cout << str << std::endl;
    //最好重新拷贝一份
    char str_copy[s1.size()];
    strcpy(str_copy, str);

    //
    //
    //用数组初始化vector
    int int_arr_1[] = {44, 56, 46, 28, 36, 29};
    std::vector<int> vi1(std::begin(int_arr_1), std::end(int_arr_1));

    std::vector<int> vi2(int_arr_1 + 2, int_arr_1 + 4);
    //切片，左闭右开

    for (auto i : vi1)
        std::cout << i << ", ";
    std::cout << std::endl;

    for (auto i : vi2)
        std::cout << i << ", ";
    std::cout << std::endl;
    return 0;
}
