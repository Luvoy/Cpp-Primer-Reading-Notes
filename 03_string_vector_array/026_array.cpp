//数组
#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
int global_arr[8];

std::vector<int> global_vi(8);

int main(int argc, char const *argv[])
{
    //书上说n必须是常量表达式，编译时已知?
    size_t n;
    std::cin >> n;
    int a[n];
    for (size_t i = 0; i < n; ++i)
    {
        a[n] = -i;
    }

    int b[6];
    for (size_t i = 0; i < 6; ++i)
    {
        std::cout << b[i] << ", ";
    }
    std::cout << std::endl;

    std::vector<int> vi(8, 3);
    for (auto i = vi.begin(); i != vi.end(); ++i)
    {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    for (auto i : vi)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (auto i : global_arr)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    for (auto i = global_vi.begin(); i != global_vi.end(); ++i)
    {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    //可见vecotr总是会初始化为默认值
    //数组和基本类型一样，函数外才会初始化，函数内不确定

    char a1[]{'c', 'a', 'c', 'c'}; //c++11的列表初始化
    char a2[] = {'1', '2', '\0'};  //普通列表初始化
    char a3[] = "I love you";      //字符数组很特殊，可以用字符串字面值初始化，结尾有'\0'
    int arr[10] = {888};
    int *int_ptr_arr[10]; //指针数组，总共10个指针
    // int &refs[10];//错误，没有引用数组
    int(*int_10_ptr)[10];                     //指向数组的指针，这个数组是10个int
    int(&int_10_ref)[10] = arr;               //引用，引用一个数组，这个数组是10个int, 必须初始化
    int *(&int_ptr_10_ref)[10] = int_ptr_arr; //引用，引用一个数组，这个数组有10个元素，每个元素是int*

    //总结，按照中右左的顺序读

    //指针和数组
    //用到数组名的地方，编译器会替换成一个指向数组首元素的指针
    auto p1(arr);     //pp是int*
    auto p2{arr};     //这里注意在mingw上这里是std::initializer_list<int *> ppp
    auto p3(&arr[0]); //和p1等价

    decltype(arr) arr2; //注意，这个是数组

    //指针也是数组的迭代器
    for (int *p_temp = arr; p_temp < arr + 10; ++p_temp)
    {
        std::cout << *p_temp << ", ";
    }
    std::cout << std::endl;

    //c++11新用法，begin和end, #include<iterator>
    int *p_begin = std::begin(arr); //首元素地址
    int *p_end = std::end(arr);     //最后元素的末尾位置
    for (auto *i = std::begin(arr); i != std::end(arr); ++i)
    {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;

    //数组的索引是非负的
    //但是指针用下标访问
    int *arr_p_2 = &arr[2];
    int ret = arr_p_2[-2]; //可以有负的，等价于*(p-2)

    //对于vector也可以
    auto p_vi_2 = &vi[2];
    std::cout << p_vi_2[-2] << std::endl;

    std::string s1 = "Hello";
    auto p_s1_2 = &s1[2];
    std::cout << p_s1_2[-2] << std::endl;
    return 0;
}
