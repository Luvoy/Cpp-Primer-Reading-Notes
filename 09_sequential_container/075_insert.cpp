//顺序容器的插入操作
#include <list>
#include <forward_list>
#include <deque>
#include <vector>
#include <string>
#include <array>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> vi1{1, 2, 3, 4};
    std::vector<std::vector<int>> vvi1;
    vvi1.push_back(vi1);
    vvi1.push_back(vi1);
    vi1[0] = 11;
    for (const auto &v : vvi1)
    {
        for (const auto &i : v)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    //注意容器元素是拷贝，插入的是拷贝，而不是对象本身

    std::list<std::string> list_int_1;
    std::string word;
    auto iter = list_int_1.begin();
    while (std::cin >> word)
        iter = list_int_1.insert(iter, word); //插入元素，返回第一个新元素的迭代器

    for (const auto &i : list_int_1)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    return 0;
}
