//sizeof运算符
//sizeof(type)
//sizeof expression
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    // cout << "sizeof char" << (sizeof char) << endl;//错误
    cout << "sizeof(char): " << sizeof(char) << endl;
    char a = 48;
    cout << "sizeof a: " << sizeof a << endl;
    cout << "sizeof(a): " << sizeof(a) << endl;

    //引用类型和原来的size一致
    char &ref = a;
    cout << "sizeof(char& ref): " << sizeof(char &) << endl;
    cout << "sizeof ref: " << sizeof ref << endl;

    //指针大小
    int *p = nullptr;
    cout << "sizeof p: " << sizeof p << endl;

    //指针即使是无效指针，也可以*p用于sizeof，因为它不需要真正使用指针获取对象
    cout << "sizeof *p: " << sizeof *p << endl;
    //sizeof右结合，运算优先级和*一样，所以，sizeof(*p)<=>sizeof *p
    cout << "sizeof(*p): " << sizeof(*p) << endl;

    int arr[10]; //对数组名，会得到数组的字节大小，并不会转换成指针
    cout << "sizeof arr: " << sizeof arr << endl;

    int arr_2[10][9][8];
    cout << "sizeof arr_2: " << sizeof arr_2 << endl;

    //对于string，vector类型，sizeof只返回该类型固定部分的大小，不计算具体元素空间
    string s1 = "hello";
    cout << "sizeof s1: " << sizeof s1 << endl;
    cout << "sizeof(std::string): " << sizeof(string) << endl;

    vector<vector<string>> v1 = {{"AAA", "BBB"}, {"Tom", "Bob", "Amy"}, {"hello", "world", "cpp"}};
    cout << "sizeof v1: " << sizeof(v1) << endl;
    cout << "sizeof(std::vector<int>): " << sizeof(vector<int>) << endl;                                 //必须指明vector的类型
    cout << "sizeof(std::vector<std::string>): " << sizeof(vector<string>) << endl;                      //必须指明vector的类型
    cout << "sizeof(std::vector<std::vector<std::string>>): " << sizeof(vector<vector<string>>) << endl; //必须指明vector的类型
    //然而无论什么样的vector，大小都一样
    return 0;
}
