#include <iostream>

//######################################################################################################################
//Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. 
//Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. 
//При выполнении задания следует использовать тернарный оператор (?:).
//######################################################################################################################

int main(){

    int number;
    std::cout << "Enter the integer " << std::endl;
    std::cin >> number;

    int diff;

    diff = (number <= 21) ? 21 - number : 2 * (number - 21);

    std::cout << "The result is " << diff << std::endl;


    return 0;
}