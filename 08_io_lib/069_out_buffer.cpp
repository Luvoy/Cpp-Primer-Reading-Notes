//输出缓冲. io操作很耗时，操作系统会建立缓冲区，只有刷新才会将数据写到输出设备/文件
//刷新的情况：
//      1。main函数的return
//      2。缓冲区满
//      3。std::endl, \n显式刷新
//      4。每个输出操作后，用unitbuf设置流的状态
//      5。std::cerr是立即刷新的
//      6。一个输出流关联到另一个流，cin和cerr都关联cout，读cin或者写cerr都会刷新cout的缓冲区
//      7。std::flush刷新

#include <iostream>
#include <ctime>
void delay(double d)
{
    clock_t total_delay_time = d * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < total_delay_time)
        ;
}
int main(int argc, char const *argv[])
{
    std ::cout << "aaaaaaa";
    std::cout << "aaa";
    delay(3);
    std::cout << "bbb\n";

    std::cout << "ccccccccccc";
    delay(3);
    std::cout << "ccccccc" << std::endl;

    std::cout << "dddd" << std::flush;
    std::cout << "DDDD" << std::flush;
    std::cout << "dddd" << std::flush;
    delay(3);
    std::cout << "EEEE" << std::endl;

    std::cout << std::unitbuf; //以后都立刻缓冲
    std::cout << "eeeeeee";
    std::cout << "EEEEEE";
    std::cout << "eeee";
    delay(3);
    std::cout << std::nounitbuf; //恢复原来的样子
    std::cout << "eeeeeee";
    std::cout << "EEEEEE";
    std::cout << "eeee";
    delay(3);
    std::cout << std::endl;

    //默认cin和cout是关联的
    std::cout << "hahaha";
    std::cout << "111";
    int i1;
    std::cin >> i1;
    delay(3);

    std::cout << "结束" << std::endl;

    //tie函数
    //不带参数返回指向输出流的指针，如果本对象关联到一个输出流，返回的就是这个输出流的指针，未关联返回空指针
    //带参数，接受一个ostream指针，将自己关联到此ostream（新），返回旧的关联的指针

    std::ostream *old_tie = std::cin.tie(nullptr); //取消旧关联
    std::cout << "hahaha";
    std::cout << "111";
    std::cin >> i1;
    delay(3);
    std::cout << i1;
    std::cin.tie(&std::cerr);
    std::cin.tie(old_tie); //重新绑定原来的
    std::cout << std::endl;

    return 0;
}
