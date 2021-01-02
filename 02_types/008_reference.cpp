//引用类型，这里指的是左值引用
//引用必须初始化
//引用无法重新绑定另一个
#include <iostream>
#include <typeinfo>
extern int &ref1;
int main(int argc, char const *argv[])
{
    int a = 1024;
    int &ref2 = a; //ref2指向a，相当于a的另一个名字
    //对ref2的操作，就是对a的操作
    int &ref3 = ref2; //获取引用的值，就是获取引用绑定的对象/变量的值
    int b = ref2;     //以引用作为初始值，就是用引用绑定的对象或变量的值作为初始值
    //没有引用的引用
    int &ref4 = a, c = a;     //c是int，不是引用
    int &ref5 = a, &ref6 = a; //ref5, ref6都是引用
    // int &ref7 = 10; //错误
    std::cout << "a = " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "ref2 = " << ref2 << ", type: " << typeid(ref2).name() << std::endl;
    std::cout << "ref3 = " << ref3 << ", type: " << typeid(ref3).name() << std::endl;
    std::cout << "ref4 = " << ref4 << ", type: " << typeid(ref4).name() << std::endl;
    std::cout << "ref5 = " << ref5 << ", type: " << typeid(ref5).name() << std::endl;
    std::cout << "ref6 = " << ref6 << ", type: " << typeid(ref6).name() << std::endl;
    std::cout << "b = " << b << ", type: " << typeid(b).name() << std::endl;
    std::cout << "c = " << c << ", type: " << typeid(c).name() << std::endl;

    return 0;
}
