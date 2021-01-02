//可变参数的函数:
//1.虽然个数不确定， 但是全部实参类型相同: initializer_list
//2.可变参数模板
//3.c风格stdargs，仅适用于与c兼容。类对象传递常常出错。
//本文演示第一种
#include <iostream>
#include <string>
#include <initializer_list>
void print_error_msg(std::initializer_list<std::string> iL)
{
    for (const auto &i : iL)
    {
        std::cout << i;
    }
    std::cout << std::endl;
    return;
}

int main(int argc, char const *argv[])
{
    //initializer_list和vector类似，但是其中的元素永远是常量，无法修改
    std::cout << "what is the longest word in the world?" << std::endl;
    std::string key = "smile";
    std::string user_input;
    std::getline(std::cin, user_input);
    if (user_input == key)
    {
        print_error_msg({"Congratulations! Your answer ", user_input, " is correct!"});
        //直接在参数中初始化一个initializer_list, 需要加上{}
    }
    else
    {
        print_error_msg({"Wrong!", " Your answer: ", user_input, "; Expected: ", key, "."});
    }

    return 0;
}
