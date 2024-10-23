#include <iostream>
#include "complex_test.hpp"
#include <cmath>
using namespace std;

#define pi 3.141592653589793238462643383279502884197


int main(){
    Complex c(5.4561,4.46513);
    Complex a(5,-pi/2,true);

    a.print();
    c.print();
    (5*I).print();
    (2-(3*(c+2*I))).print();
    a+=5;
    a.print();
    a *= 5.0;
    a*=a;
    a.print();
    a+= 20;
    cout<<a<<"lol"<<endl;
    return 0;
}