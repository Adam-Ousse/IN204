### Creation d'objet

au lieu de `malloc` on utilise `new` , pour l'initialisation dans le tas

```cpp
MyCounter* acounter = new MyCounter();
//Initialisation...
delete acounter;
```

On peut initialiser les vaeurs par défaut d'un objet en créant une ou plusieur méthodes appelées les constructeurs qui portent le même nom que la class (en c++)

```c++
myclass(param1, param2){
    param1 = param1;
    param2 = param2;
}
//or
myclass(param1,param2):
```

Un constructeur ayant seulement un seul parametre est un constructeur de conversion

```cpp
myClass(int a): num(a){}
myClass a= 3; => 3
// pour differencier entre un converteur et un constructeur on ajoute "explicite"
explicite(int a):num(a+2){}
myclass a = myClass(2);// => 4
```

Constructeur de copy :

```cpp
class ClassName {
public:
    ClassName(const ClassName& obj); // Copy constructor declaration
};
```
