
struct MyCounter
{
    unsigned counter;
    unsigned max;
    MyCounter():counter(0),max(0){}
    explicit MyCounter(unsigned max):counter(0),max(max){}
    
    unsigned getCounter() const {
      return counter;
    }
    unsigned getMax() const {
      return max;
    }
 
    void increment() {
      counter ++;
      if(counter > max)
        counter = max;
    }
 
    void reset() {
      counter = 0;
    }
 
    void set(unsigned value) {
      counter = (value <= max) ? value : counter;
    }
 
    void setMax(unsigned value) {
       if(counter >= value)
         counter = 0;
         max = value;;
    }
};