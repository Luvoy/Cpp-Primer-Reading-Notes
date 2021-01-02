//删除元素
//array不支持这种删除，有另外的
//forward_list不支持erase,不支持pop_back
//vector和string不支持pop_front
//pop_back和pop_front返回void
//erase返回最后一个被删元素的之后的位置迭代器，或者尾后迭代器
//clear清空所有

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
void print_list(const std::list<int> &L)
{
    for (const auto &i : L)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::list<int> l1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = l1.begin();
    while (it != l1.end())
    {
        if (*it & 1)
            it = l1.erase(it);
        else
            ++it;
    }

    print_list(l1);

    //erase不能用const iterator
    //也不能用rbegin

    auto it1 = l1.begin();
    auto it2 = l1.begin();
    auto it_new = l1.erase(it1, it2); //左闭右开，什么都没删除
    print_list(l1);
    std::cout << *it_new << std::endl;

    return 0;
}