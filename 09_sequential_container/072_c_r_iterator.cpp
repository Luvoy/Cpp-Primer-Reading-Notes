//顺序容器 及其 迭代器
#include <list>         //双向链表
#include <forward_list> //单向列表，没有size操作，设计目的是提供一个最简便的类似于手写的单向链表
#include <vector>       //可变长连续内存数组，可随机访问
#include <deque>        //双端队列，可随机访问
#include <array>        //固定长度数组，不支持增加、删除，内置数组升级版
#include <string>       //字符串，类似于vector
#include <iostream>
int main(int argc, char const *argv[])
{
    //迭代器是标准库的基础
    std::list<int> int_list_1(10);
    auto i1 = int_list_1.begin(), i2 = int_list_1.end();
    int a = 1;
    while (i1 != i2) //不能用<，没有定义这种运算
    {
        *i1 = a++;
        std::cout << *i1++ << std::endl;
    }

    //
    //r是反向迭代器，c是只读迭代器
    auto ri1 = int_list_1.crbegin(), ri2 = int_list_1.crend();
    while (ri1 != ri2)
    {
        std::cout << *ri1++ << std::endl;
    }

    //反向推断类型
    std::list<int>::value_type b = 2;      //int b = 2;
    std::list<int>::reference c = b;       //int &c = b;
    std::list<int>::const_reference d = 3; // const int &d = 3;

    std::forward_list<int> int_forward_list_1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //forward_list没有rbegin和rend
    for (auto b = int_forward_list_1.cbegin(); b != int_forward_list_1.cend(); b++)
    {
        std::cout << *b << std::endl;
    }
    return 0;
}
