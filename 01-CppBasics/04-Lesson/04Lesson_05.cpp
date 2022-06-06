#include <iostream>

// Пользователь вводит с клавиатуры число (год): от 1 до 3000. Написать программу, которая определяет является ли 
//этот год високосным. Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. 
//Вывести результаты работы программы в консоль.

bool check(uint16_t year){


    if (year%400==0){
        return true;
    } else if (year%4==0 and year%100!=0){

        return true;

    } else return false;

};

void isLeap(uint16_t year){

    std::cout << "Is the year " << year << " leap? ";
    if (check(year)){
        std::cout << "Yes!" << std::endl;
    } else {
        std::cout << "No!" << std::endl;
    }
}

int main(){

    uint16_t year;

    std::cout << "Enter the year to be checked " << std::endl;

    while (true){
        std::cin >> year;
        if (year<1 or year >3000){
            std::cout << "The year must be in the range 1 - 3 000. Please reenter the year " << std::endl;
        } else break;
    }

    isLeap(year);    

    return 0;
}