//顺序容器中front返回首元素的引用，back返回尾元素的引用
//forward_list没有back
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> vi1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (!vi1.empty())
    {
        auto first_1 = *(vi1.begin());
        auto first_2 = vi1.front();
        std::cout << "first_1 == first_2 ? " << (first_2 == first_1) << std::endl;
        first_2 = 11;
        std::cout << "after change first_2, vi1[0] = " << vi1[0] << std::endl;
        vi1.front() = 11; //把vi1.front()赋值给first_2后，就变成了拷贝了，front本身才是引用
        //auto & ref = vi1.front();
        std::cout << "after change first_2, vi1[0] = " << vi1[0] << std::endl;

        auto last_1 = *(--vi1.end()); //forward_list不能--
        auto last_2 = vi1.back();     //forward_list不支持back

        std::cout << "last_1 == last_2 ? " << (last_1 == last_2) << std::endl;
        last_2 = 999;
        std::cout << "after change last_2, vi1[vi1.size()-1] = " << vi1[vi1.size() - 1] << std::endl;
        vi1.back() = 999;
        std::cout << "after change last_2, vi1[vi1.size()-1] = " << vi1[vi1.size() - 1] << std::endl;

        // std::cout << "try to access vi1[vi1.size() + 1]: " << vi1[vi1.size() + 1] << std::endl;

        std::cout << "try to access vi1.at(vi1.size() + 1)" << vi1.at(vi1.size() + 1) << std::endl; //throw 'std::out_of_range'
    }
    return 0;
}