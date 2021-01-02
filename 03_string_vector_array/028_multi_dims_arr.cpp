//多维数组, 严格来讲是数组的数组

#include <iostream>
#include <iterator>
void int_arr_3x4_print(int arr[][4])
{
    for (size_t i = 0; i < 3; ++i)
    // for (auto &i : arr) //函数中第一层用auto &i:arr这种范围for不行?
    {
        for (auto j : arr[i])
        {
            std::cout << j << ",";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    int arr_3x4_1[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr_3x4_2[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int arr_3x4_3[3][4] = {{0}, {4}, {8}}; //每行的第一个元素初始化，其他的默认值初始化
    int arr_3x4_4[3][4] = {0, 1, 2, 3};    //初始化第一行，其他默认值初始化

    int_arr_3x4_print(arr_3x4_1);
    std::cout << std::endl;
    int_arr_3x4_print(arr_3x4_2);
    std::cout << std::endl;
    int_arr_3x4_print(arr_3x4_3);
    std::cout << std::endl;
    int_arr_3x4_print(arr_3x4_4);
    std::cout << std::endl;

    int(&row_4)[4] = arr_3x4_1[1]; //引用，绑定到了一个数组，这个数组有4个int
    for (auto i : row_4)
    {
        i *= i;
    }

    int_arr_3x4_print(arr_3x4_1);
    std::cout << std::endl;

    for (auto &i : row_4) //这样才能修改
    {
        i *= i;
    }

    int_arr_3x4_print(arr_3x4_1);
    std::cout << std::endl;

    //使用范围for遍历多维数组，并尝试修改
    for (auto &row : arr_3x4_1) //如果这个row不加引用，会自动变成指针
    {
        for (auto &i : row) //最内层循环如果要修改，也最好引用；只读随意
        {
            ++i;
        }
    }
    int_arr_3x4_print(arr_3x4_1);
    std::cout << std::endl;

    //指针和多维数组
    int(*p)[4] = arr_3x4_1; //使用数组名，编译器将自动转换成指向数组首个元素的指针
    //注意这里的“元素“仍然是一个数组
    auto auto_p = arr_3x4_1;
    decltype(arr_3x4_1) decl_p; //这里decl_p是数组，不是指针

    // decl_p = {{8, 8, 8, 8}, {2, 3, 3, 4}, {32, 5, 76, 2}};//提示不是可修改的左值
    decl_p[0][0] = 888;
    int_arr_3x4_print(decl_p);
    return 0;
}
