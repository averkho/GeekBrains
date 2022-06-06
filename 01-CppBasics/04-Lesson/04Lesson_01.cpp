#include <iostream>
#include <string>

//Написать программу, проверяющую что сумма двух (введенных с клавиатуры) чисел лежит в пределах от 10 до 20 
//(включительно), если да – вывести строку "true", в противном случае – "false";

void check_numbers(int a, int b){

    std::cout << "Is (a+b) inside the interval [10;20]? ";

    std::string flag="false";

    if (a+b>=10 && a+b <=20 ){
        flag="true";
    }

    std::cout << flag << std::endl;
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