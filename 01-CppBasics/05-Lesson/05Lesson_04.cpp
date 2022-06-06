#include <iostream>

//Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), 
//при этом метод должен циклически сместить все элементы массива на n позиций.

void initializeArray(int *A, int size){

    

    for (int i=0; i<size; ++i){

        A[i] = rand()%100;

    }

   }

void printing(int *A, int size){

std::cout << "Start printing array of size " << size << std::endl;

for (int i=0;i<size;++i){
    
    std::cout << A[i] << " ";
}

std::cout << std::endl;
std::cout <<"Finish of printing array";
std::cout << std::endl;

}

void shifting(int* A, int size, int n){

    int B[size];

    if (n!=0){
        if (n>0){
            for (int i=0; i<size; ++i){
                if (i<n){
                    B[i]=0;
                } else {
                    B[i]=A[i-n];
                }
            }
        } else {
            n=-n;
            for (int i=0; i<size; ++i){
                if (i<size-n){
                    B[i]=A[i+n];
                } else {
                    B[i]=0;
                }
            }
        }
    }

    for (int i=0; i<size; ++i){
        A[i]=B[i];
    }

}

int main(){

    int size=20;
    int A[size];
    initializeArray(A,size);
    printing(A,size);
    int n=-3;
    shifting(A,size,n);
    printing(A,size);

    return 0;
}