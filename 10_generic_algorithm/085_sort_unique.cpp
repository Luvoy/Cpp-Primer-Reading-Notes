//排序去重+删除
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
template <typename T>
void print_vector(const std::vector<T> &v)
{
    for (const auto &i : v)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

void eliminate_duplacation(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());                     //排序
    auto end_unique = std::unique(vs.begin(), vs.end()); //去重（并没有删除）
    vs.erase(end_unique, vs.end());                      //删除
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> vs1 = {"qqqqq", "www", "eeeeeee", "qwer", "www", "a", "eeee", "awer", "qqqqq", "rrrr"};

    print_vector(vs1);
    eliminate_duplacation(vs1);
    print_vector(vs1); //a, awer, eeee, eeeeeee, qqqqq, qwer, rrrr, www,

    return 0;
}
