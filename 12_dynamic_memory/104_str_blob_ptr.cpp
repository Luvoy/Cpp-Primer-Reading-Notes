#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;

public:
    using blob_size_t = std::vector<std::string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    blob_size_t size() const
    {
        return data->size();
    }

    bool empty() const
    {
        return data->empty();
    }

    void push_back(const std::string &t)
    {
        data->push_back(t);
    }

    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        return data->pop_back();
    }

    const std::string &front() const
    {
        check(0, "front on empty const StrBlob");
        return data->front();
    }

    const std::string &back() const
    {
        check(0, "back on empty const StrBlob");
        return data->back();
    }

    std::string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    // StrBlobPtr begin()
    // {
    //     return StrBlobPtr(*this);
    // }

    // StrBlobPtr end()
    // {
    //     return StrBlobPtr(*this, data->size());
    // }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(blob_size_t i, const std::string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, StrBlob::blob_size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string &deref() const //解引用*
    {
        auto p = check(curr, "deref out of range");
        return (*p)[curr];
    }

    StrBlobPtr &increase() //类似于++
    {
        check(curr, "increase at end");
        ++curr;
        return *this;
    }

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::blob_size_t curr;

    std::shared_ptr<std::vector<std::string>> check(StrBlob::blob_size_t i, const std::string &msg) const
    {
        auto p = wptr.lock();
        if (!p)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= p->size())
            throw std::out_of_range(msg);
        return p;
    }
};

#include <iostream>
int main(int argc, char const *argv[])
{
    StrBlob sb1;
    std::string word;
    while (std::cin >> word)
    {
        sb1.push_back(word);
    }

    try
    {
        StrBlobPtr sbp(sb1);
        while (1)
        {
            std::cout << sbp.deref() << std::endl;
            sbp.increase();
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
