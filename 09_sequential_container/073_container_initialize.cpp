//容器定义和初始化
#include <list>         //双向链表
#include <forward_list> //单向列表，没有size操作，设计目的是提供一个最简便的类似于手写的单向链表
#include <vector>       //可变长连续内存数组，可随机访问
#include <deque>        //双端队列，可随机访问
#include <array>        //固定长度数组，不支持增加、删除，内置数组升级版
#include <string>       //字符串，类似于vector
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> vi1;
    std::vector<int> vi2{11, 22, 33, 44, 55, 66};
    std::vector<int> vi3(vi2);  //初始化为拷贝
    std::vector<int> vi4 = vi3; //同样也是初始化为拷贝

    std::array<int, 10> arr1;          //array必须先指定大小
    std::array<int, 10> arr2{1, 2, 3}; //  剩余的执行值初始化

    std::vector<int> vi5(arr2.begin(), arr2.end()); //使用迭代器拷贝指定范围的元素
    // std::vector<int, 10> arr3(arr2.begin(), arr2.end());//迭代器初始化对于array不适用

    std::vector<std::string> vi6(10, "eeee");
    std::vector<std::string> vi7(10); //explicit, 使用默认构造参数
    // std::array<std::string, 10> arr4(10); //array不适用

    for (const auto &i : arr1)
    { //arr1值是未定义的
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (const auto &i : arr2)
    { //arr2值: 1, 2, 3, 0, 0, 0, 0, 0, 0, 0,
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (const auto &i : vi6)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (decltype(vi3.size()) index = 0; index < vi3.size(); index++)
    {
        std::cout << vi3[index] << ", " << vi4[index] << std::endl;
    }

    vi3[0] = 888;
    std::cout << "vi3[0] = " << vi3[0] << ", vi4[0] = " << vi4[0] << std::endl;

    return 0;
}
