//类型转换
#include <iostream>
#include <cstdint>
#include <bitset>
int main(int argc, char const *argv[])
{
    int v = 3 + 3.5 + 3.6; //右边先隐转换到double计算，然后结果再转换int，给a初始化

    std::cout << "v = " << v << std::endl;

    int int_arr_1[10];
    auto p_arr_1 = int_arr_1;           //隐式转换成指针
    auto &ref_arr_1 = int_arr_1;        //不转换
    auto addr_arr_1 = &int_arr_1;       //不转换
    auto size_arr_1 = sizeof int_arr_1; //不转换
    decltype(int_arr_1) arr_2;          //不转换

    //显式的类型转换，有5种：
    //1。static_cast<type>(expression)
    //通常意义上的类型转换，只要不包含底层const，都可以
    int delta_y = 3;
    int delta_x = 2;
    double slope = static_cast<double>(delta_y) / delta_x;

    //用于找回void*指针
    void *vp_slope = &slope;
    double *dp_slope = static_cast<double *>(vp_slope);
    std::cout << *dp_slope << std::endl;

    // const void *const_vp_slope = &slope;
    // double *dp_slope_2 = static_cast<double *>(const_vp_slope);
    // static_cast不能转换掉const属性

    //
    //2。const_cast<type>(expression)
    //用于去除底层const
    int a = 1;
    const int const_a = 2;
    const int *p1 = &a;
    const int *p2 = &const_a;
    // *p1 +=1;//不能修改
    int *p_write_1 = const_cast<int *>(p1);
    *p_write_1 += 1;
    std::cout << "a = " << a << ", *p1 = " << *p1 << ", *p_write_1 = " << *p_write_1 << std::endl;
    // *p2 +=1;//不能修改
    int *p_write_2 = const_cast<int *>(p2);
    *p_write_2 += 1;
    std::cout << "const_a = " << const_a << ", *p2 = " << *p2 << ", *p_write_2 = " << *p_write_2 << std::endl;
    //结果是2，3，3，说明其实原来的const_a还是没变，只是p2和p_write_2指向了一个新的东西，新的东西加1

    const char *s = "Hello";
    char *p_char_writable = const_cast<char *>(s);
    // *(p_char_writable + 2) = 'a'; //Segmentation fault
    //如果去掉const，去修改常量，会产生未定义的效果
    std::cout << "s = " << s << ", p_char_writable = " << p_char_writable << std::endl;
    // int *p_temp = const_cast<int *>(s);//类型不同不能用const_cast

    //也可以给非底层const添加上底层const
    int *non_low_const_p = &a;
    auto low_const_p = const_cast<const int *>(non_low_const_p);
    // *low_const_p += 1;//不可修改！
    std::cout << "*non_low_const_p = " << *non_low_const_p << ", *low_const_p = " << *low_const_p << std::endl;
    *non_low_const_p += 1;
    std::cout << "after change, *non_low_const_p = " << *non_low_const_p << ", *low_const_p = " << *low_const_p << std::endl;

    //
    //3。reinterpret_cast<type>(expression)
    //改变指针或引用的类型、将指针或引用转换为一个足够长度的整形、将整型转换为指针或引用类型
    //type必须是指针、引用、算术类型、函数指针或者成员指针。
    //它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针
    //仅仅只是比特位的拷贝，因此在使用过程中需要特别谨慎
    unsigned int b = 345634986;
    unsigned int *bp = &b;
    unsigned int c = *(reinterpret_cast<unsigned int *>(reinterpret_cast<long>(bp)));
    std::cout << "c = " << c << std::endl;
    std::cout << "b: " << b << std::endl
              << std::bitset<8 * sizeof(int)>(b) << std::endl;
    const uint8_t *bcp = reinterpret_cast<const uint8_t *>(bp);
    for (int i = 0; i < sizeof(int); i++)
    {
        std::cout << static_cast<long>(*(bcp + i)) << "\t\tbin: " << std::bitset<8 * sizeof(uint8_t)>(*(bcp + i)) << std::endl;
    }
    std::cout << std::endl;

    //
    //4。dynamic_cast<type>(expression)
    //TODO

    //
    //5。c风格的
    //建议废弃
    return 0;
}
