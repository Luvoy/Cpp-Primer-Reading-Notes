//使用泛型算法
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
#include <iterator>
#include <iostream>
int main(int argc, char const *argv[])
{
    ///////////////////
    //find
    std::vector<int> vi1{1, 2, 3, 4, 5, 6, 7, 7};
    auto ret_iter = std::find(vi1.begin() + 1, vi1.end(), 3);

    if (ret_iter != vi1.end())
    {
        std::cout << *ret_iter << std::endl;
    }

    auto ret_count = std::count(vi1.begin(), vi1.end(), 7);

    //因为算法不执行容器操作，运行于迭代器之上，因此不会改变底层容器的大小，但是可能改变容器中保存的元素，或者移动元素位置，但是不会增删

    ///////////////////////////
    //accumulate
    auto sum = std::accumulate(vi1.begin(), vi1.end(), 0.0); //0是求和初始值,sum是double，取决于0.0

    std::vector<std::string> vs2 = {"a", "b", "c"};
    // std::string str_sum = std::accumulate(vs2.begin(), vs2.end(), ""); //错误，const char *没有定义+操作，应该使用std::string("")

    /////////////////////
    //equal 两个序列的操作
    std::vector<int> vi3{1, 2, 3, 4, 5, 6};
    std::vector<int> vi4{3, 4, 5, 8};
    std::cout << "vi3 == vi4 ? " << std::equal(vi3.cbegin() + 2, vi3.cbegin() + 5, vi4.cbegin()) << std::endl;

    const char *s5 = "1234567";
    const char *s6 = "hihi3456";
    std::cout << "s5 == s6 ? " << std::equal(s5 + 2, s5 + 6, s6 + 4) << std::endl;

    //////////////////////
    //fill fill_n
    std::vector<int> vi7(10);
    std::fill(vi7.begin(), vi7.end(), 7);
    std::fill_n(vi7.begin(), 5, 8);
    //注意，fill必须预先有那么多空间
    return 0;
}
