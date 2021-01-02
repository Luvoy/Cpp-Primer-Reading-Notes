//想实现sort排序中的自定义顺序规则,需要传递第三个参数
//一元谓词unary predicate，二元谓词binary predicate
//sort函数的第三个参数接收二元谓词来取代默认的<运算
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

bool is_shorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vs1 = {"qqqqq", "www", "eeeeeee", "qwer", "www", "a", "eeee", "awer", "qqqqq", "rrrr"};
    //如果自定义按照长度排序，长度一样了再按照原有顺序，这个"原有"可以用stable_sort

    print_vector(vs1);
    //传入函数名
    stable_sort(vs1.begin(), vs1.end(), is_shorter);
    print_vector(vs1); //a, www, www, qwer, eeee, awer, rrrr, qqqqq, qqqqq, eeeeeee,
    return 0;
}
