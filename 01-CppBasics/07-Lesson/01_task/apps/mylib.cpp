
#include <cstdlib>
#include <iostream>

namespace Array{

    bool initilize(float *array,int n){

    if (array==nullptr || n<=0){
        return false;
    }

    for (int i=0; i<n; ++i){
        
        array[i]=rand()%100*0.1;
    }

    return true;
}

bool print(float *array, int n){

    if (array==nullptr || n<=0){
        return false;
    }

    for (int i=0; i<n; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return true;
}

bool count(float *array, int n){

    if (array==nullptr || n<=0){
        return false;
    }

    int positiveCount=0;
    int negativeCount=0;

    for (int i=0; i<n; ++i){
        if (array[i]>=0) {
            ++positiveCount;
        }
        else {
            ++negativeCount;
        }
    }

    std::cout << "The quantity of positive elements is " << positiveCount << std::endl;
    std::cout << "The quantity of negative elements is " << negativeCount << std::endl;

    return true;
}

}

