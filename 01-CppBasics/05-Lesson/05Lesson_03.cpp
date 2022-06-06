#include <iostream>

//Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит 
//его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

void printing(int *A, int size){

std::cout << "Start printing array of size " << size << std::endl;

for (int i=0;i<size;++i){
    
    std::cout << A[i] << " ";
}

std::cout << std::endl;
std::cout <<"Finish of printing array";
std::cout << std::endl;

}

void fillingArray(int* A, int size){

    A[0]=1;

    for (int i=1; i<size; ++i){
        A[i]=A[i-1]+3;
    }

}

int main(){

    int size=8;
    int A[size];

    fillingArray(A,size);
    printing(A,size);

    return 0;
}