#include <utility>
namespace itertools{
template <class T, class E>
class _product{
private:
    T iterable1;   
    E iterable2;    

    template <typename U, typename V>
    class iterator{
    public:
        U iteratorA; 
        V iteratorB; 
        V BstartIter; 
        iterator(U iterabA, V iterabB):iteratorA(iterabA),iteratorB(iterabB),BstartIter(iterabB){}
        // operators
        bool operator!=(_product::iterator<U,V> const &other) {            
            if ((iteratorA != other.iteratorA) && !(iteratorB != other.iteratorB)){ 
                iteratorB = BstartIter;
                ++iteratorA;
            }
            return (iteratorA != other.iteratorA);
        }
        std::pair<decltype(*iteratorA),decltype(*iteratorB)> operator*() const{
            return std::pair< decltype(*iteratorA),decltype(*iteratorB)> (*iteratorA,*iteratorB);
        }
        _product::iterator<U,V> &operator++(){
            ++iteratorB;
            return *this;
        }
    };
public:
    _product(T start, E end) : iterable1(start), iterable2(end) {}

    auto begin() const{ 
        return  _product::iterator<decltype(iterable1.begin()),decltype(iterable2.begin())>(iterable1.begin(), iterable2.begin()); } 

    auto end() const {
        return _product::iterator<decltype(iterable1.end()),decltype(iterable2.end())>(iterable1.end(), iterable2.end()); }  
};  
template <typename T, typename E>
_product<T, E> product(T first, E second)
{
    return _product<T, E>(first, second);
}
}; // end namespace itertools
