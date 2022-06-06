#include <iostream>


//Написать программу, проверяющую, является ли некоторое число - простым. 
//Простое число — это целое положительное число, которое делится без остатка только на единицу и 
//себя само.

bool check(int a){

    bool prime=true;

    if (a<=1) {
        return false;
    }
    
    else{

        for (int i=2; i<=a/2+1; ++i){
             
            if (a%i==0){
                return false;
            };
        };
        
    };

    return true;
}

void isPrime(int a){

    bool prime=check(a);
    if (prime){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

}

int main(){

    int a;

    std::cout << "Enter the number to be checked "<< std::endl;
    std::cin >> a;
    std::cout << "Is it a prime number? " << std::endl;
    isPrime(a);

    return 0;
}