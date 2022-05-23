#include <iostream>

//Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и инициализировать в 
//другом cpp файле. Используйте extern.

// External variables are initilized in 03Lesson_04_vrbls.cpp file
// compilied file in 03Lesson_04.exe

extern int a;
extern int b;
extern int c;
extern int d;

float calculation(int a, int b, int c, int d){

    return a*(b+float(c)/d);
}


int main(){

    std::cout << calculation(a,b,c,d) << std::endl;

    return 0;
}