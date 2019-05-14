
namespace itertools
{

template <class T, class E>
class _chain{
private:
    T iterableA;    
    E iterableB;   

    // inner class of chain
    template <typename U, typename V>
    class iterator
    {
    public:
        U iteratorA; 
        V iteratorB; 
        bool iterateA;
        iterator(U iterabA, V iterabB) : iteratorA(iterabA), iteratorB(iterabB), iterateA(true) {}
        // operators
        bool operator!=(_chain::iterator<U,V> const &other) 
        {
            if (iterateA && !(iteratorA != (other.iteratorA)))
                iterateA = false;

            if(iterateA)
                return (iteratorA != (other.iteratorA));
            else 
                return (iteratorB != (other.iteratorB));

            
        }

        decltype(*iteratorA) operator*() const{
            if(iterateA)
                return *iteratorA;
            else
                return *iteratorB;
        }

        _chain::iterator<U,V> &operator++(){
            if(iterateA)
                ++iteratorA;
            else 
                ++iteratorB;
            
            return *this;
        }
    };//end inner class iterator

public:
    _chain(T start, E end) : iterableA(start), iterableB(end) {}

    auto begin() const{ 
        return  _chain::iterator<decltype(iterableA.begin()),decltype(iterableB.begin())>(iterableA.begin(), iterableB.begin()); }  

    auto end() const {
        return _chain::iterator<decltype(iterableA.end()),decltype(iterableB.end())>(iterableA.end(), iterableB.end()); }  
};  

template <typename T, typename E>

_chain<T, E> chain(T first, E second){
    return _chain<T, E>(first, second);
}

}; //end namespace itertools
