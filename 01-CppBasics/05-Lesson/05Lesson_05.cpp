#include <iostream>

// Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть истину если в 
//массиве есть место, в котором сумма левой и правой части массива равны. 
//Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, 
//checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.

bool checkBalance(int* A, int size){

    int sum1=0;
    

    for (int i=0; i<size; ++i){

        sum1+=A[i];

        int sum2=0;

        for (int j=i+1; j<size; ++j){
            
            sum2+=A[j];

        }

        if (sum1==sum2){
            return true;
        }

    }
    
    return false;
    
} 

int main(){

    int size=5;
    int A[]={10,1,2,3,2};
    std::cout << checkBalance(A,size) << std::endl;

    return 0;
}