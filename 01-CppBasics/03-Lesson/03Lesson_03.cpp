#include <iostream>

//Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и 
//при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба [1][1][1].

int main(){

    int A[3][3][3] = {
                    {{1,2,3},{4,5,6},{7,8,9}},
                    {{10,11,12},{13,14,15},{16,17,18}},
                    {{19,20,21},{22,23,24},{25,26,27}}
                    };
    
    std::cout << "Middle element of an array A is " << A[1][1][1] << std::endl;

    int *a; // pointer to an array
    a = &A[0][0][0];

    std::cout << "Middle element of an array A is " << *(a+13) << std::endl;


    return 0;
}