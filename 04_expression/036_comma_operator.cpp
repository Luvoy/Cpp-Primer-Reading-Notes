//逗号运算符
//从左向右的顺序依次求值
//真正的结果是右侧的，如果右侧是个左值，那么最终结果也是左值
#include <iostream>
#include <vector>
int main(int argc, char const *argv[])
{
    //想得到一个{987654321}的vector
    int cnt = 9;
    std::vector<int> vi(9);
    for (std::vector<int>::size_type i = 0; i < vi.size(); ++i, --cnt)
    {
        vi[i] = cnt;
    }

    for (auto i : vi)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    int a = 3;
    int b = 10;
    // a++, b-- = 3; //错误rvalue，不可修改、赋值
    a++, --b = 3; //lvalue, 可以赋值
    std::cout << "a = " << a << ", b = " << b << std::endl;

    decltype(a++, --b) d1 = a; //引用
    decltype(a++, b--) d2;
    decltype(++a, --b) d3 = a; //引用
    decltype(++a, b--) d4;
    //由上可知，左边没关系的

    //奇怪的现象：
    decltype((a++, b--)) d5; //仍然不是引用？

    return 0;
}
