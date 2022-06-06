#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в 
//указанном пользователем файле (для простоты работаем только с латиницей). 
//Используем функцию find которая есть в строках std::string.

std::string extention=".txt";

bool check(std::string file, std::string word){

    std::string line;
    char delimiter=' ';
    std::ifstream fin(file+extention);

    if (fin.is_open())
    {
        while ( std::getline (fin,line) )
        {
            
            std::string sub_line;
            std::stringstream ss(line);

            while (getline(ss,sub_line,delimiter)){
                
                if (word==sub_line){
                    return true;
                }
            }
        }
        fin.close();
  }

    return false;
}

int main(){

    std::string file;
    std::string word;

    std::cout << "Enter the txt file name where you planning to search (without extention .txt)";
    std::cin >> file;
    std::cout << "Enter the word to be searched ";
    std::cin >> word;

    if (check(file, word)){
        std::cout << "The " << word << " is found in " << file << extention <<" " << std::endl;
    }
    else {
        std::cout << "The " << word << " is NOT found in " << file << extention <<" " << std::endl;
    }
    
    return 0;
}