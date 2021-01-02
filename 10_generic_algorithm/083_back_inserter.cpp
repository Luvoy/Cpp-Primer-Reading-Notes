//插入迭代器，定义在iterator中
//给插入迭代器赋值，会拷贝，然后新增到容器中
//back_inserter, 接收容器的引用，返回绑定该容器的插入迭代器
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
void print_vector_int(const std::vector<int> &v)
{
    for (const auto &i : v)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
void print_list_int(const std::list<int> &L)
{
    for (const auto &i : L)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    std::vector<int> vi1;
    print_vector_int(vi1);
    auto it = std::back_inserter(vi1);
    *it = 42; //给插入迭代器赋值42，是拷贝一个42，然后42新增到容器中
    //等价于：
    //it = vi1.insert(vi1.end(), 42);
    //++it;

    *it = 42;
    print_vector_int(vi1);

    std::fill_n(it, 10, 888); //怎么理解：fill_n本来是在一个迭代器后面填充10个888，但是我们这个迭代器是会动的。。。
    print_vector_int(vi1);

    std::fill_n(std::back_inserter(vi1), 10, 888);
    print_vector_int(vi1);

    // front_inserter
    std::list<int> Li2;
    auto fr_it = std::front_inserter(Li2);
    std::copy(vi1.begin(), vi1.end(), fr_it);
    print_list_int(Li2);

    // inserter
    std::vector<int> vi3;
    std::copy(vi1.cbegin(), vi1.cend(), std::inserter(vi3, vi3.begin())); //两个参数，第二个是要插入之前
    print_vector_int(vi3);

    return 0;
}
