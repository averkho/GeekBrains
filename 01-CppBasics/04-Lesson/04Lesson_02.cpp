#include <iostream>



// Написать программу, выводящую на экран строку “true”, если две целочисленные константы, 
//объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти. 
//Иначе "false".


void check_numbers(int a, int b){

    if ((a==10 and b==10) or ((a+b)==10)){

        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }



}

int main(){

    int a,b;

    std::cout << "Enter integer a "<< std::endl;
    std::cin >> a;
    std::cout << "Enter integer b" << std::endl;
    std::cin >> b;

    check_numbers(a,b);


    return 0;
}