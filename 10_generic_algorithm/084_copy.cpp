//copy算法
#include <iterator>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
#include <stack>
#include <queue>
#include <iostream>
int main(int argc, char const *argv[])
{
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int a2[sizeof(a1) / sizeof(decltype(a1[0]))];

    auto ret = std::copy(std::begin(a1), std::end(a1), std::begin(a2)); //ret指向a2的尾后位置

    for (auto i = std::begin(a2); i != std::end(a2); ++i)
    {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;

    //很多算法包含copy版本
    std::vector<int> vi1(std::begin(a1), std::end(a1));
    std::vector<int> vi2;

    std::replace_copy(vi1.cbegin(), vi1.cend(), std::back_inserter(vi2), 0, 888);

    for (const auto &i : vi1)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    for (const auto &i : vi2)
    {
        std::cout << i << ", ";
    }

    return 0;
}
