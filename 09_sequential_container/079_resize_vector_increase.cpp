//除了array，都可以resize
//resize(n,e)调整为n，多的用e初始化
//resize(n)，值初始化
//n比原来小就是丢弃了

//shrink_to_fit只适用于vector，string，deque
//capacity和reserve只适用于vector，string，
#include <vector>
#include <iostream>

void print_vector(const std::vector<int> &v)
{
    for (const auto &i : v)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.max_size(): " << v1.max_size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;

    for (int i = 1; i <= 6; ++i)
    {
        v1.push_back(i * i);
        print_vector(v1);

        std::cout << "v1.size(): " << v1.size() << std::endl;
        std::cout << "v1.capacity(): " << v1.capacity() << std::endl;
    }

    v1.resize(17);
    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;

    v1.resize(80);
    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;

    v1.reserve(100);
    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;

    v1.shrink_to_fit();
    std::cout << "v1.size(): " << v1.size() << std::endl;
    std::cout << "v1.capacity(): " << v1.capacity() << std::endl;

    return 0;
}
