//无序容器, 通过hash管理关键字
#include <unordered_map> //unordered_map, unordered_multimap
#include <unordered_set> //unordered_set,unordered_multiset
#include <iostream>
#include <random>
int main(int argc, char const *argv[])
{
    std::unordered_map<std::string, size_t> ump;
    std::string word;
    while (std::cin >> word)
    {
        ++ump[word];
    }

    for (const auto &i : ump)
    {
        std::cout << i.first << ": " << i.second << std::endl;
    }

    ump = {
        {"qwer", 1},
        {"asdf", 2},
        {"zxcv", 3},
        {"abcd", 4}};
    //桶接口：
    std::cout << "ump.bucket_count(): " << ump.bucket_count() << std::endl;         //当前桶数量
    std::cout << "ump.max_bucket_count(): " << ump.max_bucket_count() << std::endl; //最大桶数量
    for (decltype(ump.bucket_count()) i = 0; i < ump.bucket_count(); ++i)
    { //第n个桶有多少个元素？
        std::cout << "ump.bucket_size(" << i << "): " << ump.bucket_size(i) << std::endl;
    }
    for (const auto &i : ump)
    { //关键字k在哪个桶中？
        std::cout << "ump.bucket(" << i.first << "): " << ump.bucket(i.first) << std::endl;
    }

    ////////////////////////////

    std::unordered_map<unsigned, unsigned> ump2;
    std::uniform_int_distribution<unsigned> u(0, 999);
    std::default_random_engine e;
    for (unsigned i = 0; i < 300; ++i)
    {
        ump2[u(e)] = u(e);
    }

    //桶迭代
    for (const auto &i : ump2)
    {
        auto bucket_index = ump2.bucket(i.first);
        std::cout << "bucket(" << bucket_index << "): ";
        for (auto it = ump2.cbegin(bucket_index); it != ump2.cend(bucket_index); ++it)
        {
            std::cout << "(" << it->first << ":" << it->second << ") -> ";
        }
        std::cout << std::endl;
    }

    //hash策略
    std::cout << "ump2.load_factor(): " << ump2.load_factor() << std::endl;         //当前实际的每个桶的平均元素数量
    std::cout << "ump2.max_load_factor(): " << ump2.max_load_factor() << std::endl; //ump试图维护的平均桶大小

    ump2.rehash(ump2.bucket_count() * 1.33); //重组hash，使得bucket_count>=这个参数
    std::cout << "after rehash, ump2.bucket_count(): " << ump2.bucket_count() << std::endl;
    std::cout << "ump2.load_factor(): " << ump2.load_factor() << std::endl;         //当前实际的每个桶的平均元素数量
    std::cout << "ump2.max_load_factor(): " << ump2.max_load_factor() << std::endl; //ump试图维护的平均桶大小

    ump2.rehash((ump2.bucket_count() * 0.6)); //重组hash，使得bucket_count>=这个参数
    std::cout << "after rehash, ump2.bucket_count(): " << ump2.bucket_count() << std::endl;
    std::cout << "ump2.load_factor(): " << ump2.load_factor() << std::endl;         //当前实际的每个桶的平均元素数量
    std::cout << "ump2.max_load_factor(): " << ump2.max_load_factor() << std::endl; //ump试图维护的平均桶大小

    ump2.reserve(2 * ump2.bucket_count()); //重组，使得ump2能保存n个且不必reshash
    std::cout << "after reserve, ump2.bucket_count(): " << ump2.bucket_count() << std::endl;
    std::cout << "ump2.load_factor(): " << ump2.load_factor() << std::endl;         //当前实际的每个桶的平均元素数量
    std::cout << "ump2.max_load_factor(): " << ump2.max_load_factor() << std::endl; //ump试图维护的平均桶大小

    ump2.reserve((ump2.bucket_count() * 0.5)); //重组，使得ump2能保存n个且不必reshash
    std::cout << "after reserve, ump2.bucket_count(): " << ump2.bucket_count() << std::endl;
    std::cout << "ump2.load_factor(): " << ump2.load_factor() << std::endl;         //当前实际的每个桶的平均元素数量
    std::cout << "ump2.max_load_factor(): " << ump2.max_load_factor() << std::endl; //ump试图维护的平均桶大小

    //无序容器通过hash生成hash值，并且通过==来比较
    //定义时可以重载
    std::size_t my_hash(const std::string &s1);
    bool my_str_eq(const std::string &s1, const std::string &s2);
    std::unordered_map<std::string, int, decltype(my_hash) *, decltype(my_str_eq) *> ump3;
    return 0;
}
std::size_t my_hash(const std::string &s1)
{
    return std::hash<std::string>()(s1);
}
bool my_str_eq(const std::string &s1, const std::string &s2)
{
    return s1.size() == s2.size();
}