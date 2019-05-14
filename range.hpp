namespace itertools {

	template <class T>

	class _range {
	private:
		T _begin;
		T _end;

		//inner class iterator
		class iterator {
		public:
			T iter;
			iterator(T item) :iter(item) {}

			//override operators of iterator object
			bool operator !=(_range::iterator const second)const {
				return (this->iter != second.iter);
			}

			_range::iterator operator++() {
				++this->iter;
				return *this;
			}

			T operator *()const {
				return this->iter;
			}

		};//end inner class iterator

	public:
		_range(T begin, T end) :_begin(begin), _end(end) {}
		_range::iterator begin()const { return _range::iterator(_begin); }
		_range::iterator end()const { return _range::iterator(_end); }
	};//end class range

	template <typename T>
	_range<T> range(T begin, T end) {
		return _range<T>(begin, end);
	}


};//end itertools namespace
