//访问容器中的元素方法
//[] 和 at()只能用于map和unordered_map
//c.find(k)返回一个迭代器，指向第一个关键字为k的元素，没有就返回尾后
//c.count(k)返回某个关键字的个数，常用于multi的，对于非multi的，只会是1或者0
//c.lower_bound(k)只能用于ordered，返回迭代器，指向第一个关键字不小于k的元素，可能是k，也可能是k不存在时比k大一点，这样在这个位置插入就不会影响顺序，也可能是尾后。
//c.upper_bound(k)只能用于ordered，返回迭代器，指向第一个关键字大于k的元素
//c.equal_range(k) 返回pair<iter, iter>,表示关键字的范围，左闭右开，或者全是尾后
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::map<std::string, size_t> mp = {
        {"qwer", 1},
        {"asdf", 2},
        {"zxcv", 3},
        {"abcd", 4}};

    //find
    if (mp.find("abcd") == mp.end())
    {
        std::cout << "abcd not found" << std::endl;
    }
    else
    {
        std::cout << mp.find("abcd")->first << ": " << mp.find("abcd")->second << std::endl;
    }

    //对于multimap和multiset，最好用count，再用find
    std::multimap<std::string, size_t> mmp = {
        {"qwer", 1},
        {"asdf", 2},
        {"asdf", 22},
        {"zxcv", 3},
        {"zxcv", 33},
        {"zxcv", 333},
        {"abcd", 4}};
    std::string query = "zxcv";
    if (auto query_count = mmp.count(query))
    {
        for (auto it = mmp.find(query); query_count; --query_count)
        {
            std::cout << it->first << ": " << it->second << std::endl;
            ++it;
        }
    }

    //也可以用lower_bound和upper_bound:
    for (auto bg = mmp.lower_bound(query), ed = mmp.upper_bound(query); bg != ed; ++bg)
    { //bg==ed说明没找到
        std::cout << bg->first << ": " << bg->second << std::endl;
    }

    //也可以使用equal_range
    for (auto pair_iter = mmp.equal_range(query); pair_iter.first != pair_iter.second; ++(pair_iter.first))
    {
        std::cout << pair_iter.first->first << ": " << pair_iter.first->second << std::endl;
    }

    return 0;
}
