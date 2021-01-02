//变量作用域
#include <iostream>
int a = 1; //global scope

int main(int argc, char const *argv[])
{
    std::cout << "a=" << a << std::endl;
    int a; //warning:没有初始化，但是不管是否初始化，这个a已经不是全局了
    std::cout << "a=" << a << std::endl;
    std::cout << "global a = " << ::a << ", block a = " << a << std::endl; //使用 空格::a 访问全局
    int i;
    for (i = 0; i < 10; ++i)
    {
    }
    std::cout << "i=" << i << std::endl;
    for (int j = 0; j < 10; ++j)
    { //j: block scope
    }
    // std::cout << "j=" << j << std::endl;//ERROR
    int k = 100, sum = 0;
    for (int k = 0; k < 10; ++k)
    { //这里k是新k
        sum += k;
    }
    std::cout << "k = " << k << ", sum = " << sum << std::endl;
    return 0;
}
//强烈建议局部变量和全局变量不要使用同名的
