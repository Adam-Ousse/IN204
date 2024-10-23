#include <iostream>
#include<vector>

using namespace std;

template <typename T>
class ndarray {
public:
    pair<int, int> shape;
    vector<vector<T>> data;
    ndarray(pair<int,int> shape):shape(shape){};

};

int main(){
    ndarray<int> a({2,3});
    cout<<a.shape.first<<endl;
    cout<<a.shape.second<<endl;
    return 0;
}