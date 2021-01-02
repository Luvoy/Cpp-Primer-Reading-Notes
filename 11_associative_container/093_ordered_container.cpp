//关联容器
//根据是只有键还是键值对，有序无序，是否有重复键，分成8种：
//map multimap unordered_map unordered_multimap
//set multiset unordered_set unordered_multiset
#include <map>           //map, multimap
#include <unordered_map> //unordered_map, unordered_multimap
#include <set>           //set, multiset
#include <unordered_set> //unordered_set,unordered_multiset
#include <iostream>
#include <utility>
#include <iterator>
#include <cstring>

int main(int argc, char const *argv[])
{
    // std::set<std::string, decltype(strcmp) *> dict{
    std::set<std::string> dict{
        //可以自定义比较
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "g",
        "h",
        "i",
        "j",
    };
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
        if (dict.find(word) == dict.end()) //不在字典里才加入
            ++word_count[word];
    for (const auto &kv : word_count)
    {
        std::cout << "word: " << kv.first << " occurs " << kv.second << (kv.second > 1 ? " times" : " time") << std::endl;
    }

    //map里的对象是pair类型, pair定义在utility中
    auto p = std::make_pair(1, 2);

    //key_type此容器的关键字类型
    //mapped_type其实是键值对中，“值”的类型，只有map有，set没有
    //value_type就是map或者set中的类型，对于map，value_type就是pair<const key_type, mapped_type>；对于set，就是key_type
    //注意，容易把value_type当成kv中的v的类型
    std::set<std::string>::key_type s1;
    std::set<std::string>::value_type s2;
    std::map<int, char>::key_type s3;    //int
    std::map<int, char>::value_type s4;  //std::pair<const int, char>
    std::map<int, char>::mapped_type s5; //char

    //关联容器有迭代器
    auto map_it = word_count.begin();
    std::cout << map_it->first << ": " << map_it->second << std::endl;
    ++(map_it->second);
    std::cout << map_it->first << ": " << map_it->second << std::endl;

    //set的迭代器永远const的
    std::set<int> set_int = {0, 1, 2, 3, 4, 5, 6, 7};
    auto set_it = set_int.begin();
    // *set_it = 42;//解引用之后是const，不可以修改
    while (set_it != set_int.end())
    {
        std::cout << *set_it << ", ";
        set_it++;
    }
    std::cout << std::endl;

    //////////////////////////////
    //测试multiset、multimap的顺序
    std::multimap<int, int> mmap = {{1, 3}, {1, 2}, {3, 4}, {3, 0}, {2, 5}, {2, 6}};
    for (auto it = mmap.cbegin(); it != mmap.cend(); it++)
    {
        std::cout << it->first << ": " << it->second << ", ";
    } //1: 3, 1: 2, 2: 5, 2: 6, 3: 4, 3: 0,
    //关键字按<排序，mapped_type按插入顺序
    std::cout << std::endl;

    std::multiset<int> mset = {8, 8, 9, 7, 2, 1, 6, 4, 8, 4, 4, 7, 1, 6, 8};
    for (auto it = mset.cbegin(); it != mset.cend(); it++)
    {
        std::cout << *it << ", ";
    } //1, 1, 2, 4, 4, 4, 6, 6, 7, 7, 8, 8, 8, 8, 9,
    std::cout << std::endl;

    /////////////////////////////
    //插入方法
    auto insert_ret = word_count.insert({"hello", 1}); //返回std::pair<iterator, bool>，iterator是指向给定关键字的元素，bool是说明原来关键字有没有,如果原来就有，insert什么也不做，bool返回为false

    if (!insert_ret.second) //如果原来就有，就递增计数器
        ++(insert_ret.first->second);

    word_count.insert(std::make_pair("world", 1));
    word_count.insert(std::pair<std::string, size_t>("qwer", 3));
    word_count.insert(std::map<std::string, size_t>::value_type("asdf", 2));

    //对于multimap，插入永远有效，则返回迭代器
    mmap.insert({1, 2});

    //对于set
    int arr[] = {22, 344, 5, 113, 53231};
    set_int.insert(std::begin(arr), std::end(arr)); //返回void
    set_int.insert({8888, 9999, 2222});             //返回void
    set_int.insert(8345);                           //返回pair
    mset.insert(1234);                              //返回一个指向新元素的迭代器

    //删除
    //c.erase(k);//删除所有关键字为k的元素，返回删除的数量
    //c.erase(p);
    //c.erase(b,e);//删除迭代器范围，返回删除的后面的

    //map下标
    word_count["jjjjj"]; //如果没有会插入, 返回引用, 不赋值就是值初始化
    // word_count.at("www") = 3;//没有会报错
    for (auto it = word_count.cbegin(); it != word_count.cend(); it++)
    {
        std::cout << it->first << ": " << it->second << ", ";
    }
    //multimap没有下标，因为这样就有歧义了
    // mmap["a"] = 3;
    std::cout << std::endl;
    return 0;
}
