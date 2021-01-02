//before_begin()
//cbefore_begin
//insert_after，返回指向最后一个插入的元素的迭代器。不能使用尾后迭代器作为参数
//erase_after删除某元素之后的。返回删除元素之后的迭代器，或尾后迭代器
#include <forward_list>
#include <iostream>
void print_forward_list(const std::forward_list<int> &f)
{
    for (const auto &i : f)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    std::forward_list<int> f1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = f1.before_begin();
    auto curr = f1.begin();
    while (curr != f1.end())
    {
        if (*curr & 1)
        {
            curr = f1.erase_after(prev);
        }
        else
        {
            prev = curr;
            curr++;
        }
    }

    print_forward_list(f1);
    return 0;
}
