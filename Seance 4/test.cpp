#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template<class T>
void print(T A){
    ostream_iterator<int> O(cout,", ");
    copy(A.begin(),A.end(),O);
}

template<class inputIterator,class T>
inputIterator greatest_element(T& V){
    if(V.begin()== V.end()){
        return V.begin();
    }
    inputIterator potential = V.begin;
    inputIterator i = V.begin;
    for(;i<V.end();i=next(i)){
        if(*i > *potential){
            potential = i;
        }
    }
    return potential;
}
int main(){
   
    vector<int> vec = {1, 2, 3, 4, 5};
    // ostream_iterator<int> out_it(cout, ", ");
    // copy(vec.begin(), vec.end(), out_it);
    print(vec);
    cout<< *greatest_element(vec)<<endl;
    return 0;
}