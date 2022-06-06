#include <iostream>
#include <cstdlib>

#define ARRAY_SIZE 10
#define swapINT(a,b) \
do { \
    int tmp=*a; \
    *a=*b; \ 
    *b=tmp; \
} while(0);
    

bool initializeArray(int *array){

    if (array==nullptr){
        return false;
    }

    for (size_t i=0; i<ARRAY_SIZE; ++i){

        array[i]=rand()%100;
    }

    return true;

}

void printArray(int *array){

    for (size_t i=0; i<ARRAY_SIZE; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
}

void bubbleSort(int *array){

    for (size_t i=0; i<ARRAY_SIZE-1; ++i){
        for (size_t j=0; j<ARRAY_SIZE-i-1; ++j) {
            if (array[j]>array[j+1]){
                swapINT(&array[j],&array[j+1]);
            }
        }

    }

}

int main(){

    int array[ARRAY_SIZE];

    if (initializeArray(array)){
        std::cout << "The array was successfully initilized " << std::endl;
    }
    else{
        std::cerr << "Failure while initilizing array " << std::endl;
    }

    std::cout << "Initial array " << std::endl;
    printArray(array);
    bubbleSort(array);
    std::cout << "Sorted array " << std::endl;
    printArray(array);

    return 0;
}