#include <vector>       // std::vector
#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>
using namespace std;

template<class T>
void print(const T& A){
    ostream_iterator<typename T::value_type> O(cout, ", ");
    copy(A.begin(), A.end(), O);
}
// creation d'iterateur :
class interval_iterator {
public:
	using iterator_category = std::forward_iterator_tag;
	using value_type = int;
	using difference_type = std::ptrdiff_t;
	using pointer = int*;
	using reference = int&;

private:
	friend class interval; //allows interval to access private members 
	const interval* mInterval; // Référence à l'interval.
	int mCurrent; // la valeur courante dont on fait référence.

	interval_iterator(const interval& anInterval, int aCurrentValue) : 
		mInterval(&anInterval), mCurrent(aCurrentValue) {}

public:
	interval_iterator(const interval_iterator& anotherIterator):
		mInterval(anotherIterator.mInterval),
		mCurrent(anotherIterator.mCurrent) {}

	interval_iterator& operator = (const interval_iterator& anotherIterator)
	{
		mInterval = anotherIterator.mInterval;
		mCurrent = anotherIterator.mCurrent;
		return *this;
	}
	const int operator*() const{
		return mCurrent;
	};
	const pointer operator->() const{
		return &mCurrent;
	};
	interval_iterator& operator++() {
		++mCurrent;
		return *this;
	}
	interval_iterator operator++(int) {
		interval_iterator temp = *this;
		++(*this);
		return temp;
	}
	bool operator ==(const interval_iterator& other) const{
		assert(other.mInterval == mInterval);
		return mCurrent == other.mCurrent;
	};
class interval {
public:
	typedef int value_type;
	typedef const int& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	interval(int theMinValue, int theMaxValue) : 
		minValue(theMinValue), maxValue(theMaxValue) 
	{}
	typedef int value_type;
	typedef size_t size_type;
        typedef ptrdiff_t difference_type;
 
	interval(int theMinValue, int theMaxValue) : 
		minValue(theMinValue), maxValue(theMaxValue) 
	{}
	interval(const interval& anotherInterval):
		minValue(anotherInterval.minValue), 			 		  
                maxValue(anotherInterval.maxValue)
	{}
	interval& operator = (const interval& anotherInterval)
	{
		minValue = anotherInterval.minValue;
		maxValue = anotherInterval.maxValue;
		return *this;
	}
	size_type size() const
	{
		return (size_type)(maxValue - minValue);
	}
	int operator[](size_type anIndex) const
	{
		if (anIndex > size())
			throw std::out_of_range("Index out of range");
		return minValue + (int)anIndex;
	}
	bool operator == (const interval& anotherInterval) const
	{
		return anotherInterval.maxValue == maxValue &&
	bool operator != (const interval& anotherInterval) const {
	}
	bool operator != (const interval& anotherInterval) const
	interval_iterator begin() const{
		return interval_iterator(*this, minValue);
	}
	interval_iterator end() const{
		return interval_iterator(*this, maxValue+1);
	}
	const_iterator begin() const noexcept {
		return interval_iterator(*this, minValue);
	}
	const_iterator end() const noexcept {
		return interval_iterator(*this, maxValue + 1);
	}
	const_iterator begin() const noexcept;
	const_iterator end() const noexcept;
};



int main(){
    interval a(2,10);
    interval b(a);
    cout<<a[5]<<endl;
    cout<<b[5]<<endl;
    for(auto i= a.begin();i!=a.end();i++){
        cout<<*i<<endl;
    }

    return 0;
}