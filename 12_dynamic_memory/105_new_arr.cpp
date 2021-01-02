//new和数组
#include <memory>
#include <iostream>
#include <new>
int main(int argc, char const *argv[])
{
    int *p1 = new int[10];
    using arr_ten = int[10]; //typedef int arr_ten[10];
    int *p2 = new arr_ten;

    //其实得到的是指针，不能使用范围for，begin，end等等

    int *p3 = new int[10]();        //值初始化
    int *p4 = new int[10]{1, 2, 3}; //后面的值初始化
    //int *p5 = new int[2]{1, 2, 3};  //bad_array_new_length
    int *p6 = new int[0]; //正确，但什么都没有，不能解引用

    delete[] p1; //逆序销毁
    delete[] p2;
    delete[] p3;
    delete[] p4;
    delete[] p6;

    //使用unique_ptr
    size_t sz = 8;
    std::unique_ptr<int[]> up(new int[sz]{1, 2, 3, 4, 5});
    for (size_t i = 0; i < sz; ++i)
        std::cout << up[i] << std::endl;
    up.reset();

    //使用shared_ptr，必须自定义删除器
    std::shared_ptr<int> sp(new int[10]{1}, [](int *p) { delete[] p; });
    for (size_t i = 0; i < sz; ++i)
        std::cout << *(sp.get() + i) << std::endl; //必须使用get
    sp.reset();                                    //默认使用delete，我们制定了delete[]

    return 0;
}
