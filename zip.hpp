#pragma once
#include <utility> 
#include <iostream>
namespace itertools{
template <typename T,typename E>
std::ostream &operator<<(std::ostream &os, const std::pair<T,E>&pair){
    os<< pair.first <<','<< pair.second;
    return os;
}
template <class T, class E>
class _zip{
private:
    T iterableA;    
    E iterableB;   
    // inner class of zip
    template <typename U, typename V>
    class iterator{
    public:
        U iterA; 
        V iterB; 
        iterator(U iterabA, V iterabB) : iterA(iterabA), iterB(iterabB) {}
        // operators
        bool operator!=(_zip::iterator<U,V> const &other) {
            return (iterA != other.iterA) && (iterB != other.iterB);
        }
        std::pair<decltype(*iterA),decltype(*iterB)> operator*() const{
            return std::pair< decltype(*iterA),decltype(*iterB)> (*iterA,*iterB);
        }
        _zip::iterator<U,V> &operator++(){
            ++iterA;
            ++iterB;   
            return *this;
        }
    };
public:
    _zip(T start, E end) : iterableA(start), iterableB(end) {} 
    auto begin() const{ 
        return  _zip::iterator<decltype(iterableA.begin()),decltype(iterableB.begin())>(iterableA.begin(), iterableB.begin()); } 

    auto end() const {
        return _zip::iterator<decltype(iterableA.end()),decltype(iterableB.end())>(iterableA.end(), iterableB.end()); }   
}; 
template <typename T, typename E>
_zip<T, E> zip(T first, E second){
    return _zip<T, E>(first, second);
}
} // namespace itertools
