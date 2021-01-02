//顺序容器的赋值和交换
#include <list>
#include <forward_list>
#include <deque>
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <random>
#include <ctime>
int main(int argc, char const *argv[])
{
    std::vector<int> vi1{1, 2, 3, 4, 5};
    std::vector<int> vi2{6, 7, 8, 9, 10, 11, 12};

    vi1 = vi2; //将1中元素替换为2的拷贝
    for (auto b = vi1.cbegin(); b != vi1.cend(); ++b)
    {
        std::cout << *b << ", ";
    }
    std::cout << std::endl;

    vi2[0] = 66;
    for (auto b = vi1.cbegin(); b != vi1.cend(); ++b)
    {
        std::cout << *b << ", ";
    }
    std::cout << std::endl;

    for (auto b = vi2.cbegin(); b != vi2.cend(); ++b)
    {
        std::cout << *b << ", ";
    }
    std::cout << std::endl;

    vi1 = {11, 22, 33, 44, 55}; //重新赋值
    for (auto b = vi1.cbegin(); b != vi1.cend(); ++b)
    {
        std::cout << *b << ", ";
    }
    std::cout << std::endl;

    std::array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2 = {1};
    a1 = a2;
    a2 = {3}; //和书上写的不一样，书上说array不支持这种赋值//TODO
    for (const auto &i : a1)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (const auto &i : a2)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    vi1.assign(8, 1); //将vi1替换成8个1
    for (const auto &i : vi1)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    // a2.assign(8, 1); //array没有assign 操作

    std::default_random_engine e;
    std::vector<unsigned> vi3(1000000000, e());
    std::vector<unsigned> vi4(1000000000, e());
    std::vector<unsigned> vi5(1000000000);

    clock_t start = clock();
    vi5 = vi3;
    vi3 = vi4;
    vi4 = vi5;
    clock_t stop = clock();
    std::cout << "vi3 <-> vi4, using copy: " << 1.0 * (stop - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    //1.209s

    start = clock();
    swap(vi3, vi4);
    stop = clock();
    std::cout << "vi3 <-> vi4, using swap: " << 1.0 * (stop - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    //0.000005s

    //swap交换元素非常快，是常数级别操作

    return 0;
}
