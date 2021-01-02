//迭代器的基础知识和案例
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cctype>

/* 将字符串转换成大写 */
std::string &string_upper(std::string &s)
{ //这个函数不传引用可以吗？不可以
    for (auto c = s.begin(); c != s.end(); ++c)
    { //迭代器中，！=常用，而<索引值那种形式不常用
        *c = toupper(*c);
    }
    std::cout << "In func string_upper, s: " << s << std::endl;
    return s;
}

void vector_string_print(const std::vector<std::string> vs)
{
    for (auto i = vs.cbegin(); i != vs.cend(); ++i)
    {
        if (i != vs.begin())
            std::cout << ", ";
        std::cout << *i;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> vs1 = {"Tony", "Alex", "John", "Amy", "Jenny", "Thomas"};
    auto b = vs1.begin(); //指向第一个元素的迭代器
    auto e = vs1.end();   //指向尾元素的下一位置

    std::cout << "*begin() " << *b << std::endl;
    std::cout << "begin()->member " << b->size() << std::endl;
    std::cout << "*(++iter) " << *(++b) << std::endl;
    std::cout << "*(--iter) " << *(--b) << std::endl;
    auto bb = vs1.begin();
    std::cout << "b == bb " << (b == bb) << std::endl;
    std::cout << "b == e " << (b == e) << std::endl;
    //相等：指向同元素或者是同一个元素的尾后迭代器

    //测试一下写的函数
    std::string str1("Hello");
    auto &ref1 = str1;
    string_upper(ref1);
    std::cout << "str1: " << str1 << std::endl;

    //迭代器类型:
    //iterator可读可修改
    //const_iterator只读
    //并且和命名空间是相关的
    //例如std::vector<std::string>::iterator

    //非const容器，既可以有iterator也可以有const_iterator
    //const容器，只能有const_iterator
    const std::vector<int> cvi = {13, 19, 29, 37, 43};
    auto cvi_b = cvi.begin();

    //c++11定义了cbegin和cend，就是const_iterator
    auto cb = vs1.cbegin();
    auto cvi_cb = cvi.cbegin();

    //尝试修改：
    std::cout << "before change, *b: " << *b << ", *bb: " << *bb << ", *cb: " << *cb << std::endl; //对于非const容器，修改之前
    auto &ref2 = *b;
    string_upper(ref2);
    std::cout << "change through b, *b: " << *b << ", *bb: " << *bb << ", *cb: " << *cb << std::endl; //对于非const容器，普通的可以修改，修改了*b，*bb也跟着变了
    auto &ref3 = *cb;
    // string_upper(ref3); 指向const的引用
    std::cout << "change through cb, *b: " << *b << ", *bb: " << *bb << ", *cb: " << *cb << std::endl; //对于非const容器，const的可以修改

    std::cout << "before change, *cvi_b: " << *cvi_b << ", *cvi_cb: " << *cvi_cb << std::endl; //对于const容器，修改之前
    // *cvi_b = 0;//直接报错！
    // std::cout << "change through cvi_b, *cvi_b: " << *cvi_b << ", *cvi_cb: " << *cvi_cb << std::endl; //对于const容器，用普通的修改
    // *cvi_cb = 999;//直接报错！
    // std::cout << "change through cvi_cb, *cvi_b: " << *cvi_b << ", *cvi_cb: " << *cvi_cb << std::endl; //对于const容器，用const修改

    //看看类型
    std::cout << "typeid(b).name(): " << typeid(b).name() << std::endl;
    std::cout << "typeid(cb).name(): " << typeid(cb).name() << std::endl;
    std::cout << "typeid(cvi_b).name(): " << typeid(cvi_b).name() << std::endl;
    std::cout << "typeid(cvi_cb).name(): " << typeid(cvi_cb).name() << std::endl;

    //尝试在迭代器中删除
    // vs1.push_back(std::string("Bill"));
    std::cout << "before erase, vs1:" << std::endl;
    vector_string_print(vs1);
    for (auto i = vs1.begin(); i != vs1.end(); ++i)
    {
        vs1.erase(i);
        vector_string_print(vs1);
    }
    std::cout << "after erase, vs1:" << std::endl;
    vector_string_print(vs1);
    //单个元素删除后，传入的迭代器仍然指向被删除元素的位置(注意是位置不是元素）
    //而被删除元素之后的所有元素都向前移动一位
    //也就是该迭代器实际上是指向了原来被删除元素的下一个元素
    //数量为偶，会保留一半。数量为奇，会报错

    //正确的删除，应该这样

    std::vector<std::string> l4f2 = {"Francis", "Zoe", "Bill", "Louis", "Coach", "Rochelle", "Ellis", "Nick"};
    std::cout << "before erase, l4f2:" << std::endl;
    vector_string_print(l4f2);
    for (auto i = l4f2.begin(); i != l4f2.end();)
    {
        if (true)
        { //符合删除条件的
            l4f2.erase(i);
        }
        else
        {
            ++i;
        }
    }
    std::cout << "after erase, l4f2:" << std::endl;
    vector_string_print(l4f2);

    //使用迭代器，不要添加元素！
    return 0;
}
