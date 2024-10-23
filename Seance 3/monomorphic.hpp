#ifndef monomorphicHPP
#define monomorphicHPP
 
#include <vector>
#include <random>
#include <iostream>
using namespace std;

namespace monomorphic
{
    random_device rd; // initialisés une seule fois 
    minstd_rand gen(rd());

    template<typename T>
    void populate_with_randoms(std::vector<T>& theVector,
        int theNumberOfValues, int theMinValue, int theMaxValue)
    {
        theVector.clear();
        // approche C
        // srand(time(0));
        // for(int i=0;i<theNumberOfValues;i++){
        //     theVector.push_back(rand()%(theMaxValue-theMinValue+1)+theMinValue);
        // }
        // approche C++
        
        uniform_int_distribution<> distribution(theMinValue, theMaxValue);
        
        for(int i = 0; i < theNumberOfValues; i++){
            int a = distribution(gen);
            theVector.push_back(a);
        }
    }

    template<typename T>
    void print_vector(const std::vector<T>& anArray)
    {   
        cout << "[";
        for(auto const &i : anArray){
            std::cout << i << ",";
        }
        std::cout << "]" << std::endl; // endl is "\n" + std:flush();
    }

    template<typename T>
    void simple_sort(std::vector<T>& theValues)
    {
        for (int i = 0; i < theValues.size(); i++)
        {
            for (int j = i + 1; j < theValues.size(); j++)
            {
                // Compare si les deux elements sont dans le bon ordre.
                if (theValues[i] > theValues[j])
                {
                    // Procede a la permutation des deux elements
                    int Temp = theValues[i];
                    theValues[i] = theValues[j];
                    theValues[j] = Temp;
                }
            }
        }
    }
};
 
#endif