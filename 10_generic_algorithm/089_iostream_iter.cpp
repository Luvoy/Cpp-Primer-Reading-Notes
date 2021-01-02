//iostream对象也有迭代器
//istream_iterator,初始化应该绑定一个流对象，否则默认情况下就是eof
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
int main(int argc, char const *argv[])
{
    // std::istream_iterator<int> is_it_int(std::cin);
    // std::istream_iterator<int> is_it_eof;
    // std::vector<int> vi1(is_it_int, is_it_eof);
    // std::vector<int> vi2;

    // while (is_it_int != is_it_eof)
    // {
    //     vi2.push_back(*is_it_int++);
    // }

    // for (const auto &i : vi1)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;
    // for (const auto &i : vi1)
    // {
    //     std::cout << i << ", ";
    // }
    // std::cout << std::endl;

    std::istream_iterator<int> in(std::cin), eof;
    std::cout << std::accumulate(in, eof, 0) << std::endl;

    return 0;
}
