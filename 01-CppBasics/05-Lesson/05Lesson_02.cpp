#include <iostream>

//Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
//Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. 
//Выводить на экран массив до изменений и после.

void printing(int *A, int size){

std::cout << "Start printing array of size " << size << std::endl;

for (int i=0;i<size;++i){
    
    std::cout << A[i] << " ";
}

std::cout << std::endl;
std::cout <<"Finish of printing array";
std::cout << std::endl;

}

void replacing(int* A, int size=10){

    for (int i=0; i<size; ++i){
        
        if (A[i]==0) A[i]=1;
        else A[i]=0;
        
    }

}

int main(){

    int A[]={1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    int size=10;
    std::cout << "Initial array " << std::endl;
    printing(A,size);
    replacing(A,size);
    std::cout << "Changed array " << std::endl;
    printing(A,size);


    return 0;
}