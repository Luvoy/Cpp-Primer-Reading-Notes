#include <iostream>
//declaration只是使得名字被程序所知道，一个文件如果想使用别处definition，必须包含对那个名字的declaration
//definition负责创建与名字关联的实体，开辟内存空间

extern int i;     //declaration but not definition，不要赋值
int j;            //declaration and definition
extern int k = 1; //definition //WARNING

int main(int argc, char const *argv[])
{
    // std::cout << "i=" << i << std::endl; //ERROR undefined i
    std::cout << " j=" << j << " k=" << k << std::endl;

    extern int a; //函数内部可以extern声明
    // a = 1;        //ERROR: undefined a
    // int a = 1; //ERROR: redeclaration of a

    // extern int b = 1; //函数内部不可以初始化一个extern变量

    // i = 5; //ERROR: undefined i
    return 0;
}
//总结：在函数内部，extern一个变量是没有意义的：
//      如果只声明，后面不能用，其他include的文件也不能用（因为是函数内部的）；不用的话还报warning
//      如果声明又初始化，直接编译报错

//extern一个变量的正确姿势：
//      在文件A定义变量x（这时已经包括声明了），其他文件include这个A文件，
//      然后其他文件中extern声明这个变量（变量可以多次声明，但是不能多次定义）