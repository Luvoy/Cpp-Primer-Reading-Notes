#include <iostream>
using namespace std;
void func1(const int *x);
void func2(int *x);
void func3(int **x);
void func4(int *const *x);
void func5(const int **x);
void func6(int **const x);
int g_1 = 3;
int g_2 = 4;
int main()
{
    const char *p_1 = "Hello";
    cout << p_1 << endl;
    cout << *p_1 << endl;
    cout << *(p_1 + 1) << endl;
    if (*(p_1 + 5) == '\0')
    {
        cout << "the last index of const char is \'\\0\'" << endl;
    }
    //cout << *(p_1 + 121313) << endl; //out of index

    p_1 = "aaaaa";
    cout << "after change p_1: " << p_1 << endl;

    // *p_1 = "bbbbb";
    // cout << "after change *p_1: " << p_1 << endl;

    char const *p_2 = "world";
    cout << p_2 << endl;

    p_2 = "eeee";
    cout << "after change p_2: " << p_2 << endl;

    // *p_2 = "dddd";
    // cout << "after change *p_2: " << p_2 << endl;

    //char *const p_3 = "!!!";
    // cout << p_3 << endl;

    int v_a = 1;
    const int v_b = 2;
    int v_c = 5;

    int *pi_1 = &v_a;
    const int *pi_2 = &v_a;
    int *const pi_3 = &v_a;
    int const *pi_4 = &v_a;
    //const int const * pi_5 = &v_a;//error: duplicate const
    const int *const pi_6 = &v_a;
    //int const const * pi_7 = &v_a;//error: dupliacte const
    int const *const pi_8 = &v_a;

    *pi_1 = 4;
    cout << *pi_1 << endl; // 4
    cout << v_a << endl;   // 4

    //*pi_2 = 7; //read only
    //cout << *pi_2 << endl;
    //cout << v_a << endl;

    *pi_3 = 6;
    cout << *pi_3 << endl; // 6
    cout << v_a << endl;   // 6

    // *pi_4 = 8; //read only
    // cout << *pi_4 << endl;
    // cout << v_a << endl;

    // *pi_6 = 6;
    // cout << "*pi_6: "<<*pi_6 << endl;
    // cout << v_a << endl;

    // *pi_8 = 11;  //read only
    // cout << "*pi_8: "<<*pi_8 << endl;
    // cout << v_a << endl;

    //////////////////////////
    //pi_1 = &v_b; //invalid conversion from 'const int*' to 'int*'
    pi_1 = &v_c;
    cout << *pi_1 << endl; // 5
    cout << v_a << endl;   // 6

    pi_2 = &v_b;
    pi_2 = &v_c;
    cout << *pi_2 << endl; // 5
    cout << v_a << endl;   // 6

    //pi_3 = &v_b; //invalid conversion from 'const int*' to 'int*' + assignment of read-only variable 'pi_3'
    //pi_3 = &v_c; //error: assignment of read-only variable 'pi_3'
    //cout << *pi_3 << endl;
    //cout << v_a << endl;

    // pi_4 = &v_b;
    // pi_4 = &v_c;
    // cout << *pi_4 << endl; // 5
    // cout << v_a << endl;   // 6

    // pi_6 = &v_b; //read-only
    // pi_6 = &v_c; //read-only
    cout << *pi_6 << endl;
    cout << v_a << endl;

    // pi_8 = &v_b; //read-only
    // pi_8 = &v_c; //read-only
    // cout << *pi_8 << endl;
    // cout << v_a << endl;

    /*
    Summary:
    const int *p 不能修改指向的变量的值，可以修改指向
    int const *p 不能修改指向的变量的值，可以修改指向
    int *const p 不能修改指向，可以修改指向的变量的值
    可以用const int* p 或者 int const *p指向int，也可以指向const int
    （至此，可以理解为const int* p 和 int const *p是一样的）
    不能用int* p 指向const int
    不能用int * const p指向const int，其实是两方面原因
    
    所谓指向const的指针, 是指针自以为是,自己觉得指向了一个常量,
    通过它不能修改那个量,但是可以改变它的指向,指向谁,谁就不能通过它修改
    但是如果那个量原本不是const, 还是可以用其他办法修改

    const int * const p 既不能修改指向,也不能修改指向的变量的值
    int const * const p 既不能修改指向,也不能修改指向的变量的值
    const int const * p非法定义(我猜,因为对int进行了多重const定义)
    int const const * p非法定义
    
    可以进一步猜测:
    从右往左看, const离谁(*还是int)近{或者[谁(*还是int)离const近]}就修饰谁, (实际上c++创始人也建议从右往左看来记忆)
    int const 和const int 一样的
    */

    int *p_t = &g_1;
    cout << "p_t: " << p_t << ", *p_t: " << *p_t << endl;

    func1(p_t);
    cout << "p_t: " << p_t << ", *p_t: " << *p_t << endl;

    func2(p_t);
    cout << "p_t: " << p_t << ", *p_t: " << *p_t << endl;

    func3(&p_t);
    cout << "p_t: " << p_t << ", *p_t: " << *p_t << endl;
    string s;
    cout << "enter a char to exit" << endl;
    cin >> s;
}

void func1(const int *p)
{
    //*p = 108; //error: read only

    p = &g_2;
    // 为什么p没有修改呢
    // 进一步理解const int *和函数形参
    // 传递的是指针, 指针的值其实是它所指向的变量的地址比如0x405004
    // 严格来讲,是复制了一个0x405004进来
    // 本来(没有const)说的"函数传递指针就可以修改指向的变量的值",是说
    // 实际上是在函数里根据0x405004做了一些操作,当然可以修改
    // 但加了const 不能修改了
    // 而修改指向不是一回事,因为传递的是指针的形参,虽然是指向变量的地址
    // 想要修改指向,要用**
}

void func2(int *p)
{

    p = &g_2;
    // 并不会修改指向
}

void func3(int **p)
{

    *p = &g_2;
}

void func4(int *const *p)
{

    //*p = &g_2; //error: read only
    return;
}

void func5(const int **p)
{
    *p = &g_2;
}

void func6(int **const p)
{
    *p = &g_2;
}