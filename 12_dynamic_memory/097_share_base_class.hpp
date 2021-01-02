//某个类，多个类对象需要共享相同的底层数据
//也就是类分配的资源对于实例对象来说，有独立的生存周期
//也就是说，销毁某个实例对象时，不能单方面地销毁底层数据
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
class StrBlob
{
public:
    using blob_size_t = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    blob_size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t)
    {
        data->push_back(t);
    }
    void pop_back();
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(blob_size_t i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
{
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    return data->pop_back();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty const StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty const StrBlob");
    return data->back();
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(blob_size_t i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
