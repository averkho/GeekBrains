#include <iostream>
#include <cstdlib>

// Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. 
//Вызвать эту функцию из main.

void initializeArray(double *A, int size){

    

    for (int i=0; i<=size; ++i){

        A[i]=rand()%100*0.1;

    }

   }

void printing(double *A, int size){

std::cout << "Start printing array of size " << size << std::endl;

for (int i=0;i<=size;++i){

    std::cout << A[i] << " ";
}

std::cout << std::endl;
std::cout <<"Finish of priting array";
std::cout << std::endl;

}

int main(){

    int size=5;
    double A[size];

    initializeArray(A,size);

    printing(A,size);

    return 0;
}