//ostream_iterator
//不允许无参的默认初始化，必须绑定到一个流对象
//还可以有第二个参数，必须是c风格字符串，作为每次写入的结尾后缀
//若out是一个ostream_iterator, 则没有*out, ++out, out++这些操作
//只有out = val; 把val写入到out绑定的输出流上. val必须类型兼容
#include <iterator>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::ostream_iterator<int> os_it_int(std::cout, ", ");
    for (int i = 0; i < 10; ++i)
    {
        os_it_int = i;
        // *os_it_int++ = i;//也可以，好处是看起来好理解
    }

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::copy(std::begin(arr), std::end(arr), os_it_int);
    return 0;
}
