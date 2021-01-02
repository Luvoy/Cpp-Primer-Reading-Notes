//函数重载
//如果同一作用域的几个函数名字相同但是形参列表不同，为重载
#include <iostream>
#include <string>
void f1(int *const p)
{
}
//顶层const不算形参的difference
// void f1(int *p) //error: redefinition
// {
// }

//
//
//底层const可以重载，底层const既可以传底层const也可以传非底层const
//再记一遍，不能用底层const初始化非底层const
void f2(const int *p)
{
    std::cout << "AAA" << std::endl;
}
void f2(int *p)
{ //调用同名的几个重载函数，传入非底层const，优先选择参数为非底层const的函数
    std::cout << "BBB" << std::endl;
}

//
//const_cast和重载
const std::string &shorter_str(const std::string &str1, const std::string &str2)
{
    return str1.size() < str2.size() ? str1 : str2;
}
const std::string &shorter_str_overload(const std::string &str1, const std::string &str2) //如果两个参数去掉&，会引发ambiguous call
{
    return str1.size() < str2.size() ? str1 : str2;
}
std::string &shorter_str_overload(std::string &str1, std::string &str2)
{
    //注意是auto&r， 不是auto r
    auto &r = shorter_str_overload(const_cast<const std::string &>(str1),
                                   const_cast<const std::string &>(str2));
    return const_cast<std::string &>(r);
}
int main(int argc, char const *argv[]) //main不可以重载
{
    int a = 1;
    int *p1 = &a;
    const int *p2 = p1;
    f2(p1);
    f2(p2);

    //如果参数不是常量，shorter_str返回的仍然是常量，我们想要得到非常量的返回值啊
    std::string s1 = "He";
    std::string s2 = "She";
    std::string s3 = shorter_str(s1, s2); //这里发生了拷贝赋值，所以看起来没什么问题，其实这样测不出来
    s3[0] = 'A';
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << std::endl;
    // shorter_str(s1, s2)[0] = 'A'; //禁止修改

    shorter_str_overload(s1, s2)[0] = 'A'; //可以修改
    const std::string s4 = "const He";
    const std::string s5 = "const She";
    // shorter_str_overload(s4, s5)[0] = 'A';//不可修改

    return 0;
}
