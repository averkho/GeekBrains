#include <iostream>


void printing(int *A, int size){

std::cout << "Start printing array of size " << size << std::endl;

for (int i=0;i<size;++i){
    
    std::cout << A[i] << " ";
}

std::cout << std::endl;
std::cout <<"Finish of printing array";
std::cout << std::endl;

}

void initializeArray(int *A, int size){

    for (int i=0; i<size; ++i){

        A[i] = rand()%100;

    }

   }