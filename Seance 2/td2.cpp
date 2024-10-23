// #ifndef MYCOUNTER_HPP
#define MYCOUNTER_HPP
 
#include<iostream>
using namespace std;

class BaseCounter
{
protected:
    unsigned counter;
    unsigned max;
 
public:
    unsigned getCounter() const { return counter; }
    unsigned getMax() const { return max; }
    void reset() { counter = 0; }
    void set(unsigned value) { counter = value; }
    void setMax(unsigned value)
    {
        max = value;
        if(value > counter)
            counter = counter % max;
    }
    void print() const
    {
        cout<<"Compteur : "<<counter<<"/"<<max<<endl;
    }
 
protected:
    BaseCounter(): counter(0), max(0) {}
    BaseCounter(unsigned theCounter,
        unsigned theMax): counter(theCounter), max(theMax)
    {}
    BaseCounter(const BaseCounter & anotherCounter):
        counter(anotherCounter.counter),
        max(anotherCounter.max)
    {}
    ~BaseCounter ()
    {}
};
// class MyCounter
// {
// protected: 
//     unsigned counter;
//     unsigned max;
 
// public:
//     unsigned getCounter() const { return counter; }
//     unsigned getMax() const { return max; }
//     void increment()
//     {
//        if(counter == max)
//            counter = 0;
//         else
//            counter ++;
//     }
//     void reset() { counter = 0; }
//     void set(unsigned value) { counter = value; }
//     void setMax(unsigned value)
//     {
//         max = value;
//         if(value > counter)
//             counter = counter % max;
//     }
 
//     MyCounter(): counter(0), max(0) {}
//     MyCounter(unsigned theCounter,
//         unsigned theMax): counter(theCounter), max(theMax)
//     {}
//     explicit MyCounter(unsigned theMax):
//         max(theMax), counter(0)
//     {}
//     MyCounter(const MyCounter& anotherCounter):
//         counter(anotherCounter.counter),
//         max(anotherCounter.max)
//     {}
//     ~MyCounter()
//     {}
// };

class ForwardCounter: public virtual BaseCounter
{
    public:
        void increment()
        {
            if(counter < max)
                counter = counter + 1;
            else
                counter = 0;
        }
 
        ForwardCounter(): BaseCounter() {}
        ForwardCounter(const ForwardCounter& aCounter): BaseCounter(aCounter) {}
        explicit ForwardCounter(unsigned theMaxValue): ForwardCounter(0, theMaxValue) {}
        ForwardCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {}
};
 
 
class BackwardCounter: public virtual BaseCounter
{
    public:
        void decrement()
        {
            if(counter > 0)
                counter = counter -1;
            else
                counter = max;
        }
        BackwardCounter(): BaseCounter() {}
        BackwardCounter(const ForwardCounter& aCounter): BaseCounter(aCounter) {}
        explicit BackwardCounter(unsigned theMaxValue): BackwardCounter(0, theMaxValue) {}
        BackwardCounter(unsigned theCounter, unsigned theMaxValue): BaseCounter(theCounter, theMaxValue) {}
};
// class MyBiDiCounter:public MyCounter{
//     public:
//     MyBiDiCounter():MyCounter(){}; //par defaut
//     MyBiDiCounter(unsigned theMax):MyCounter(theMax){}; //max
//     MyBiDiCounter(const MyBiDiCounter& copie): MyCounter(copie){}; //copie
//     MyBiDiCounter(unsigned theCounter,
//         unsigned theMax): MyCounter(theCounter,theMax){}; // total

//     void decrement(){
//         if(counter>0) counter--;
//         else counter=max;
//     }
//     void print() const //read only function
//     {
//         cout<<"Compteur : "<<counter<<"/"<<max<<endl;
//     }

// };

class BiDiCounter: public ForwardCounter, public BackwardCounter
{
    public:
        BiDiCounter(): ForwardCounter(), BackwardCounter() {}
        BiDiCounter(const BiDiCounter& aCounter):
            ForwardCounter(aCounter),
            BackwardCounter((const BackwardCounter&)aCounter),
            BaseCounter(aCounter) {}
        BiDiCounter(unsigned theMaxValue): BiDiCounter(0, theMaxValue) {}
        BiDiCounter(unsigned theCounter, unsigned theMaxValue):
            ForwardCounter(),
            BackwardCounter(),
            BaseCounter(theCounter, theMaxValue) {}
};
//Class ?
// FOrward_class               Backward_class
//                     Bidir class
void testMyBiDiCounter()
{
    BiDiCounter counterA;
    counterA.setMax(4);
    counterA.reset();
    counterA.print();
    for(int i=0; i < 6; i++)
    {
        counterA.increment();
        counterA.print();
    }
    for(int i=0; i < 6; i++)
    {
        counterA.decrement();
        counterA.print();
    }
}

int main(){
    BiDiCounter c1(0,10);
    c1.print();
    c1.increment();
    c1.print();
    c1.decrement();
    c1.print();
    // BiDiCounter c2(c1);
    // c2.print();
    

    return 0;
}