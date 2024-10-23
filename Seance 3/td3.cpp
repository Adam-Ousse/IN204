#include <iostream>
#include<vector>
#include <array>
using namespace std;


template< typename T, unsigned int n>
class Array{
    public:
        T L[n];
};

int main(){
    Array<double,5> A;
    A.L[0]=20;
    for(auto a:A.L){
        cout<<a<<",";
    }
    cout<<endl;

    return 0;
}