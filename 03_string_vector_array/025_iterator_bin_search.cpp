//使用迭代器进行二分查找
//迭代器的运算
#include <iostream>
#include <vector>
#include <typeinfo>

/* 打印一个int的vector */
void vector_int_print(const std::vector<int> vi)
{
    std::cout << "[";
    for (auto i = vi.cbegin(); i != vi.cend(); ++i)
    {
        if (i != vi.cbegin())
            std::cout << ", ";
        std::cout << *i;
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vi1;
    for (int i = 1; i <= 10; ++i)
        vi1.push_back(i * i);

    vector_int_print(vi1);

    auto i1 = vi1.begin() + 3;
    auto i2 = vi1.begin() + 7;
    auto d = i1 - i2;
    std::cout << "type iterator - iterator is " << typeid(d).name() << std::endl;
    std::vector<int>::difference_type dd = i2 - i1;
    //书上说iterator的差值是相应的difference_type
    //auto运算的是std::ptrdiff_t

    std::vector<std::string> l4f2 = {"Francis", "Zoe", "Bill", "Louis", "Coach", "Rochelle", "Ellis", "Nick"};

    auto i3 = l4f2.begin() + 2;
    auto i4 = l4f2.end() - 1;
    auto ddd = i4 - i3;
    auto max_d = l4f2.end() - l4f2.begin();
    std::cout << max_d << std::endl;

    //二分查找
    int key = 16;
    auto left = vi1.begin(), right = vi1.end();
    //end是最后一个元素的末尾位置，所以是左闭右开区间
    auto mid = left + (right - left) / 2;
    while (left < right)
    {
        if (*mid == key)
        {
            break;
        }
        else if (*mid > key)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    std::cout << *mid << std::endl;
    return 0;
}
