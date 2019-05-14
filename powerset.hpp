#include <set> 
#include <vector>
#include <cmath>
#include <iostream>
#include "zip.hpp"

namespace itertools{
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &S){
    return os;
}
template <class T>
class _powerset{
private:
    T _start;
    template <class E>
    // inner class of powerset
    class iterator{
    public:
        E elementStart;
        E elementEnd;
        unsigned int index;
        unsigned int size;

        iterator(E elementStartplace, E elementEndplace):elementStart(elementStartplace),elementEnd(elementEndplace),size(0),index(0)                                                   {
            E elementIterator = elementStart;
            while (elementIterator != elementEnd){
                ++size;
                ++elementIterator;
            }
            size = std::pow(2, size);
        }

        // operators
        bool operator!=(_powerset::iterator<E> const &second) const{
            return ((size - index) != (second.size - second.index - 1));
        }

        auto operator*() const
{
            E elementIterator = elementStart;
            std::vector<typename std::remove_const<typename std::remove_reference<decltype(*elementStart)>::type>::type> S;
           
            unsigned int i = index;
            while (i != 0 && elementIterator != elementEnd){ 
                unsigned int r = i % 2;
                i = i >> 1; 

                if (r == 1)
                    S.emplace_back(*elementIterator);

                ++elementIterator;
            }
            return S;
        }
        _powerset::iterator<E> &operator++(){
            ++index;
            return *this;
        }
    };//end inner class iterator
public:
    _powerset(T start) : _start(start) {}                                                                                                             
    auto begin() const { return _powerset::iterator<decltype(_start.begin())>(_start.begin(), _start.end()); } 
    auto end() const { return _powerset::iterator<decltype(_start.begin())>(_start.end(), _start.end()); }      
};                                                                                                                                                 

template <typename T>
_powerset<T> powerset(T start){
    return _powerset<T>(start);
}

}; // end namespace itertools
