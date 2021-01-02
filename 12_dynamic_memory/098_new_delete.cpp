//new delete直接管理内存
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <new> //bad_alloc, nothrow
int main(int argc, char const *argv[])
{
    //初始化问题
    int *p1 = new int;                   //默认初始化，类对象使用默认构造，而内置类型将是未定义的
    int *p2 = new int(42);               //显式指定
    std::string *p3 = new std::string;   //默认初始化
    std::string *p4 = new std::string(); //值初始化
    int *p5 = new int();                 //值初始化，0

    //使用auto
    // std::vector<int> *p6 = new auto {1, 2, 3};//错误
    // std::vector<int> *p7 = new auto(1, 2, 3);//错误
    auto p8 = new auto(42);
    auto p9 = new auto({1, 2, 3});
    auto p10 = new auto {1, 2, 3};
    // auto p11 = new auto(1, 2, 3);//错误

    //const问题
    const int *p12 = new const int(1024); //必须初始化
    // const int *p13 = new const int; //可以()值初始化，但是什么都不写，是没有初始值的
    const std::string *p14 = new const std::string;

    //异常
    //内存耗尽时，会抛出bad_alloc异常
    int *p15 = new (std::nothrow) int; //指定不抛，返回空指针

    //delete, delete必须释放new的，除非空指针，每个new只能释放1次

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p8;
    delete p9;
    delete p10;
    delete p12;
    delete p14;
    delete p15;
    return 0;
}
