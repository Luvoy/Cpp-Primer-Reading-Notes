//聚合类：
//全public，无constructor，无类内初始值，无基类，无virtual函数
#include <string>
#include <vector>
class X
{
public:
    int i1;
    double d1;
    std::string s1;
};

struct Y
{
    unsigned u1;
    char c1;
    float f1;
    std::vector<X> v1;
};
#include <iostream>
int main(int argc, char const *argv[])
{
    X x1 = {1, 1.0, "ee"}; //按顺序初始化
    Y y1 = {1, 'c'};       //少给的按值初始化
    std::cout << y1.f1 << std::endl;
    return 0;
}
