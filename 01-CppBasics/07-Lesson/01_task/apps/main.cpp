#include <iostream>
#include "mylib.h"

int main(){

    int n;
    std::cout << "Enter the size of array to be initialized ";
    while(true){
        std::cin >> n;
        if (n>=0){
            break;
        } else {
            std::cout << "The size of array must be positive. Please reenter the size";
        }
    }
    std::cout << std::endl;

    float array[n];

    if (Array::initilize(array,n)){
        std::cout << "The array was initialized successfully! " << std::endl;
    }
    else {
        std::cerr << "The array was NOT initilized successfully";
    };

    if (Array::print(array,n)){
        std::cout << "The array was printed successfully! " << std::endl;
    }
    else {
        std::cerr << "The array was NOT printed successfully!" << std::endl;
    }

    if (Array::count(array,n)){
        std::cout << "The counting was carried out successfully! " << std::endl;
    }
    else {
        std::cerr << "The counting was NOT carried out successfully! " << std::endl;
    }

    return 0;
}