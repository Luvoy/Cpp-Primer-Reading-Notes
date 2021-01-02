//容器适配器
#include <stack>
#include <queue>
// #include <priority_queue>//错误，这个也在queue中
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <iostream>
int main(int argc, char const *argv[])
{
    //默认情况下,statck和queue基于queue
    //priority_queue基于vector

    std::priority_queue<int> pq1;

    for (int i = 1; i <= 10; ++i)
    {
        pq1.push(i * i);
    }

    while (!pq1.empty())
    {
        std::cout << pq1.top() << ", ";
        pq1.pop();
    }
    std::cout << std::endl;

    std::priority_queue<int>::container_type v1;

    std::vector<std::string> vs1{"s", "e", "w"};
    std::stack<std::string, std::vector<std::string>> stack_1(vs1); //拷贝
    return 0;
}