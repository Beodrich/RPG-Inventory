#pragma once
#include <functional>
using namespace std;
template <typename T>
class Collection
{
public:
    virtual ~Collection() = 0;

    virtual unsigned int getSize() const = 0;

    virtual void forEach(
        const std::function<void(const T&)>& accept)
        const
    = 0;

    virtual void forEach(
        const std::function<void(T&)>& accept)
    = 0;
};

template <typename T>
Collection<T>::~Collection()
{
}
