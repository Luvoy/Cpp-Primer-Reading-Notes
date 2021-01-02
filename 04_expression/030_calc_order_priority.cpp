//运算顺序和优先级
#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
int global_i = 1;
int f1()
{
    global_i *= 3;
    return global_i;
}

int f2()
{
    global_i *= 2;
    return global_i;
}

int main(int argc, char const *argv[])
{
    int f12 = f1() * f2(); //先算f1还是f2是未知的
    global_i = 1;
    int f21 = f2() * f1();
    std::cout << "f12: " << f12 << ", f21: " << f21 << std::endl;

    //
    int i = 0;
    std::cout << "i: " << i << ", ++i: " << ++i << std::endl; //未定义的操作，先求i还是++i不确定
    //<<运算符没有规定何时如何对参与运算的对象求值
    int cc = (++i) + (++i); //may be undefined
    std::cout << "cc = " << cc << std::endl;

    // 只有逻辑与&& 逻辑或|| 条件运算?: 逗号, 这四种规定了

    std::string s1 = "Hello";
    auto it = s1.begin();
    while (it != s1.end())
    {
        *it = toupper(*it++);
        //两侧都用到了it，并且右侧还修改了it
        //求值顺序不是确定的，将产生未定义行为
    }
    std::cout << s1 << std::endl;

    return 0;

    //运算对象的求值顺序和优先级与结合律无关
    //f()+g()*h()+j()先乘法后加法，加法从左到右
    //但是函数调用顺序没有规定
    //如果它们修改了同一对象，将产生未定义行为

    //赋值运算符，右结合

    //自增自减，尽量前置++i
    //++前置返回一个递增后的lvalue
    //++后置返回一个未递增的rvalue
}
