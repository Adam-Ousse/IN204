#include <vector>       // std::vector
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
void print(const T& A){
    ostream_iterator<typename T::value_type> O(cout, ", ");
    copy(A.begin(), A.end(), O);
}
// #define itero
#ifdef itero
template <class T>
size_t upper(vector<T> aVector, const T& theValue)
{
	for (int i = 0; i < aVector.size(); i++)
	{
		if (aVector[i] > theValue)
			return i;
	}
	return -1;
}
#endif
// 20 | vector<T>::iterator upper(vector<T> V, const T& theValue){
//       | ^~~~~~~~~
//       | typename
//Besoin d'ajouter typename before vector::iterator , for parsing
    template <class T>
    typename vector<T>::iterator upper(vector<T>& V, const T& theValue){
        //we require the vecotr>T>& cause if we input a copy of the vecotr, the index distance(itr,v.begin()) is going to be wrong
    for(typename vector<T>::iterator itr = V.begin();itr!=V.end();++itr){
        if(*itr >theValue){
            return itr;
        }
    }return V.end();
}
template <class inputIter, class T>
inputIter upper(inputIter begin, inputIter end, const T& theValue){
    for(inputIter itr=begin;itr!=end;++itr){
        if(*itr>theValue){
            return itr;
        }
    }
    return end;
}

int main(){
    vector<double> a{3.14,1.2,23,231};  
    double tab[]= {1.0,231,2313};
    #ifdef itero
    size_t pos = upper(a,5.0); //un indice save commonly used for indexing car il s'adapte automatiquement avec la machine
    //in c #include<inttypes.h> intptr_t 
    cout<<"indice : "<<upper(a,5.0) <<" valeur :"<<a[upper(a,5.0)]<<endl;
    #endif
    vector<double>::iterator itr = upper(a,5.0);
    cout<<"indice : "<<itr-a.begin()<<" value :"<<*itr<<endl;
    //ou 
    cout<<"indice : "<<distance(a.begin(),itr)<< " value :"<<*itr<<endl;
    //ou 
    vector<double>::iterator ittr = upper(a.begin(),a.end(),5.0);
    cout<<"indice : "<<distance(a.begin(),itr)<< " value :"<<*ittr<<endl;

    cout<< distance(&tab[0],upper(&tab[0], &tab[3],20.0))<<endl;
    sort(a.begin(),a.end());
    print(a);
    return 0;
}
