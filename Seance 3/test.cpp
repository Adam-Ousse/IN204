#include <iostream>
#include<vector>
#include <array>
using namespace std;

template <class T>
void print(T A){
    for(auto i:A){
        cout<<i<<",";
    }
    cout<<endl;
}




int main(){

    vector<int> a = {1,5,2,3};
    array b={2,3,1};
    print(a);
    print(b);
    return 0;
}