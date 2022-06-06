#include <iostream>

//Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя. 
//Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран. 
//Не забыть освободить память. =) Разбить программу на функции.

bool fillArray(int* ptrArray, const size_t size){

    if (ptrArray==nullptr || size==0) return false;

    ptrArray[0]=1;

    for (int i=1; i<size; ++i){
        ptrArray[i]=ptrArray[i-1]*2;
    }

    return true;

}

bool printArray(const int* ptrArray, const size_t size){

    if (ptrArray==nullptr || size==0){
        return false;
    }

    for (int i=0; i<size; ++i){

        std::cout << ptrArray[i] << " ";
    }

    std::cout << std::endl;

    return true;


}

int main(){

    int size;
    std::cout << "Enter the size of array ";
    
    while (true){

        std::cin >> size;

        if (size<=0){

            std::cout << "The size of array must be positive.Please renter the size of array.";
        }
        else break;
    }

    int* ptrArray=new (std::nothrow) int[size];

    if (fillArray(ptrArray,size)){
        std::cout << "The array is successfully filled " << std::endl;
    }
    else {
        std::cerr << "The array is not filled " << std::endl;
    }

    if (printArray(ptrArray,size)){
        std::cout << "The array is successfully printed " << std::endl;
    }
    else{
        std::cerr << "The array is not printed " << std::endl;
    }

    delete[] ptrArray;


    return 0;
}