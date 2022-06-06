#include <iostream>

// Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: 
//"Your numbers: 1 3 5 7 9 11 13 ...". Для решения используйте любой С++ цикл.


int main(){

    std::cout << "Your numbers: ";

    for (int i=1; i<=50; ++i){


        if (i%2!=0){

            std::cout << i << " ";
        }
    }

    std::cout << std::endl;


    return 0;
}