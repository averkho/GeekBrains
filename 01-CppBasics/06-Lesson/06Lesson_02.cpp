#include <iostream>
#include <cstdlib>

//Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand. 
//Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.

const size_t n=4;

int** makeMatrix(){

    int** ptrArray = new int* [n];

    for (size_t i=0; i<n; ++i){

        ptrArray[i]=new int[n];

        for (size_t j=0; j<n; ++j){
            ptrArray[i][j]=rand()%100;
        }

    }

    return ptrArray;

}

void deleteMatrix(int** ptrArray){
    
    for (size_t i=0; i<n; ++i){
        delete[] ptrArray[i];
    }

    delete[] ptrArray;
    ptrArray=nullptr;
}

bool printArray(int** ptrArray){

    if (ptrArray==nullptr) return false;

    for (size_t i=0; i<n; ++i){
        for (size_t j=0; j<n; ++j){
            std::cout << ptrArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return true;

}


int main(){

    int** ptrArray = makeMatrix();
    if (printArray(ptrArray)){
        std::cout << "The array was sucessfully printed " << std::endl;
    }
    else{
        std::cerr << "The array is empty. Error!!!" << std::endl;
    }
    deleteMatrix(ptrArray);
    

    return 0;
}