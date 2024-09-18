#include <iostream>
using namespace std;
typedef struct Person{
    Person(string name, string surname):name(name),surname(surname){}
    Person(){
        name = "Uknown";
        surname = "Uknown";
    }
    Person(int a){
        name= to_string(a);
        surname = "Adam";
    }
    string name;
    string surname;
    void present() const {
        cout << "My name is " << name << " " << surname << endl;
    }
}Person;

int main(){
    Person P = Person();
    P = 1;
    P.present();
    return 0;
}