//c++中，名称查找发生在类型转换之前
//这意味着，先确定作用域内的函数，再检查参数合不合格
#include <iostream>
void read(); //函数声明
void print(const std::string &s)
{
    std::cout << s << std::endl;
}

void print(double a)
{
    std::cout << a << std::endl;
}

void print(int a)
{
    std::cout << a << std::endl;
}
//
int main(int argc, char const *argv[])
{
    bool read = false; //新作用域，屏蔽了外层的read函数

    void print(int); //函数声明，这样写不太好。为了演示效果。
    //屏蔽了外侧所有重载的print函数

    // print("Hello");
    print(2);    //调用了本作用域的print(int)
    print(3.14); //正确，但是调用的是这个作用域内的print(int),并且进行了隐式转换
    return 0;
}
