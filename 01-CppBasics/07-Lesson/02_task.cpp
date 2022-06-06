#include <iostream>

//Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в 
//диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, 
//вывести на экран «true» или «false». 

#define check(a,b)(( a>=0 && a<=b) ? true : false)

int main(){

    int a,b;

    std::cout << "Enter a ";
    std::cin >> a;
    std::cout << "Enter b ";
    std::cin >> b;

    
    
    if (check(a,b)){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }
    

    return 0;
}