//像list和forward_list特定容器指定了特定的算法
//成员函数
//merge
//remove, remove_if(一元谓词), 也就是erase某个元素的所有出现
//reverse
//sort
//unique去重，可接受二元谓词
//splice 大段插入
#include <list>
#include <forward_list>
#include <iterator>
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
    std::list<int> L1{1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
    std::list<int> L2(L1.cbegin(), L1.cend());

    L1.splice(L1.begin(), L2);
    print_list(L1);
    print_list(L2);

    L1.reverse();
    print_list(L1);

    L1.remove_if([](int a) -> bool { return a == 2; });
    print_list(L1);

    L1.sort();
    print_list(L1);

    L1.unique();
    print_list(L1);

    L1.merge({1, 2, 3, 4, 5}); //L1,L2必须是有序的
    print_list(L1);

    return 0;
}
