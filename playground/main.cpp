#include <bits/stdc++.h>
using namespace std;

template<class T>
class Array {
    public: 
        vector<vector<T>> A;
        vector<unsigned long long int> shape{2}; 
        Array(unsigned long long int n, unsigned long long int m){
            shape[0] = n;
            shape[1] = m;
            A = vector<vector<T>>(n, vector<T>(m));
        }
        vector<T>& operator[](unsigned long long int i) {
            return A[i];
        }
        T& operator()(unsigned long long int i, unsigned long long int j){
            return A[i][j];
        }
        Array operator*(const Array<T>& B){
            assert(this->shape[1]==B.shape[0]);
            Array<T> C(this->shape[0],B.shape[1]);
            for(int i=0;i<this->shape[0];i++){
                
                for(int k=0;k<B.shape[1];k++){
                   T result = 0; 
                   for(int j=0;j<this->shape[1];j++){
                        result+= (*this)[i][j]*B[j][k];
                   }
                   C[i][k]=result;
                }

            }
            return C;
        }
        
        
};

void print(Array<double> A){
    for(const auto &a : A.A){
        for(const auto& b:a){
            cout<<b<<",";
        }
        cout<<endl;
    }
    
        
}

int main(){
        Array<double> A(3, 3);
        Array<double> B(3,3);
        B[2][2]=1.0;
        B[1][1]=1.0;
        B[0][0]=1.0;
        print(A);
        A[2][2]=69;
    cout<<A(2,2)<<endl;
        Array<double> C = A*B;
        return 0;
}
