#include <iostream>
const int a = 1;        //两个文件都是const int a 声明+定义
extern const int b = 2; //h文件extern声明+定义, cpp文件extern声明
const int c = 1;        //h文件const int 声明+定义, cpp文件extern声明

void func()
{
    std::cout << "In func():" << std::endl;
    std::cout << "a = " << a << ", &a = " << &a << std::endl;
    std::cout << "b = " << b << ", &b = " << &b << std::endl;
    std::cout << "c = " << c << ", &c = " << &c << std::endl;
}

//书上说多个文件的同名const变量, 等同于不同文件中分别定义了独立的变量, 这个好像不对啊...
//经过测试, c都是一样的啊
//为了让多个文件共享一个const变量, 需要const不管声明还是定义, 都加上extern. 但注意定义还是只有一次,声明可以很多次
