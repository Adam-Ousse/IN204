#include "monomorphic.hpp"
#include <vector>
using namespace std;



int main(){
    
    vector<double> A;
    monomorphic::populate_with_randoms(A,5,4,10);
    monomorphic::simple_sort(A);
    monomorphic::print_vector(A);
    //normal_distribution<double> d(0,1);
    //mt19937 genn{monomorphic::rd()};
    // for(int i=0;i<100;i++){
    //     cout<<(d(genn))<<",";
    // }


    return 0;
}