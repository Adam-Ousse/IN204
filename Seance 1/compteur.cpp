#include "compteur.hpp"
#include <iostream>

void useObjectA() {
MyCounter Counter1;
MyCounter Counter2;
Counter1.setMax(2u);
Counter2.setMax(4u);
Counter1.reset();
Counter2.reset();
for(unsigned i = 0; i <= 5; i++) {
std::cout
<< "Valeur des compteurs ("
<< Counter1.counter
<< ", " << Counter2.counter
<< ")" << std::endl;
Counter1.increment();
Counter2.increment();
}
}

void myfunctionA()
{
  MyCounter counter;
  std::cout << counter.getCounter() << std::endl;
  std::cout << counter.getMax() << std::endl;
}
 
void myfunctionB() 
{
  MyCounter* counter = new MyCounter(5);
  std::cout << counter->getCounter() << std::endl;
  std::cout << counter->getMax() << std::endl;
  delete counter;
}

int main(){
    // useObjectA();
    myfunctionA();
    myfunctionB();
    return 0;
}