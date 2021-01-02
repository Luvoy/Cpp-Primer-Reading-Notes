//如何在一个vector<string>中，找到大于某个长度a的string有多少个呢？并打印
//按长度排序，然后用find_if，find_if接收一元谓词，元素本身已经占用了，没法传入长度a
//lambda格式：
// [ capture_list ] ( parameter_list ) -> return_type { function_body }
//捕获列表用于捕获这个lambda所在函数的局部变量，这样函数体就可以用了
//没有捕获的局部变量不能用，但是，没有捕获的static变量、全局变量可以在函数体内用

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <iostream>
#include <stack>
#include <queue>
#include <iterator>
#include <iostream>
//declaration
void print_strs_longer_than_len(std::vector<std::string> &vs, std::string::size_type threshold_size, std::ostream &os, char suffix);
int f1();
int f2();
int f3();
int f4();
int f5();
int main(int argc, char const *argv[])
{
    //捕获列表为空，参数列表也为空
    auto lambda_1 = [] { return 42; };    //参数列表和返回类型可以省略，但是永远包括捕获列表和函数体
    decltype(&lambda_1) f;                //TODO
    std::cout << lambda_1 << std::endl;   //1
    std::cout << lambda_1() << std::endl; //42

    //捕获列表为空
    auto lambda_2 = [](const std::string &s1, const std::string &s2) -> bool {
        return s1.size() < s2.size();
    };
    std::cout << lambda_2("ee", "eee") << std::endl; //1

    //使用捕获列表
    int a = 5;
    auto lambda_3 = [a](const int b) -> long {
        long ret = 1;
        for(int i = 0;i<a;++i)
            ret*=b;
        return ret; };
    std::cout << lambda_3(2) << std::endl;

    //完成想要的功能：找到一个vector中大于某长度的str
    std::vector<std::string> vs1 = {"qq", "www", "eeee", "rrrrr", "tttttt"};
    std::string::size_type my_size = 3;
    print_strs_longer_than_len(vs1, my_size, std::cout, ',');

    //测试捕获值和捕获引用的区别：
    std::cout << "f1(): " << f1() << std::endl; //42
    std::cout << "f2(): " << f2() << std::endl; //3
    //测试显式捕获和隐式捕获
    std::cout << "f3(): " << f3() << std::endl; //11
    std::cout << "f4(): " << f4() << std::endl; //10
    //测试可变lambda
    std::cout << "f5(): " << f5() << std::endl; //3
    return 0;
}

//使用捕获列表
void print_strs_longer_than_len(std::vector<std::string> &vs, std::string::size_type threshold_size, std::ostream &os, char suffix)
{ //打印一个string的vecotr中，大于某个长度t的string
    std::stable_sort(vs.begin(), vs.end(), [](const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); });
    auto ret_iter = find_if(vs.begin(), vs.end(), [threshold_size](const std::string &s) { return s.size() > threshold_size; });

    auto count = vs.end() - ret_iter;
    std::cout << "Find " << count << " string(s) longer than " << threshold_size << ":" << std::endl;
    std::for_each(ret_iter, vs.end(), [&os, suffix](const std::string &s) { os << s << suffix; });
    std::cout << std::endl;
}

int f1()
{
    int a = 42;
    auto my_lambda = [a]() { return a; };
    a = 3;
    auto ret = my_lambda();
    return ret; //这里是42，因为创建lambda时，保存的是a的拷贝
}
int f2()
{
    int a = 42;
    auto my_lambda = [&a]() { return a; }; //引用
    a = 3;
    auto ret = my_lambda(); //3
    return ret;
    //注意，局部变量的引用，在函数结束后就消失了，也就是a已经不存在了
}
int f3()
{
    //显隐捕获
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    auto my_lambda = [=, &c]() { return a + b + c + d; }; //除了c是引用捕获，其他的都是值捕获
    c++;
    d++;
    return my_lambda();
}

int f4()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    auto my_lambda = [&, c, d]() { return a + b + c + d; }; //除了c,d是值捕获，其他的都是引用捕获
    c++;
    d++;
    return my_lambda();
}

int f5()
{
    int a = 1;
    const int b = 1;
    // auto my_lambda_1 = [a]() { return ++a; };//error,这里a不可以修改，
    //想修改必须加上mutable

    auto my_lambda_1 = [a]() mutable { return (++a) + b; };
    // auto my_lambda_1 = [a]() mutable { return (++a) + (++b); };//虽然加了mutable，但是b本身是const的，不能修改
    std::cout << "in f5, a = " << a << std::endl; //a=1,可见lambda虽然mutable，但是修改的是lambda中局部的
    a = 4;                                        //这个修改不影响lambda里面的

    return my_lambda_1();
}
//function body含有多条语句的lambda，应用->指明返回类型