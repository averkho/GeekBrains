#include <iostream>
#include <fstream>
#include <string>


//Написать программу, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом 
//(особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.

std::string s=".txt";

void makeFiles(std::string file1, std::string file2){

    std::ofstream fout1(file1+s);
    std::ofstream fout2(file2+s);

    std::string s1{ "a" },s2{ "b" };

    for (int i=0; i<150; ++i){
        s1+="a";
        s2+="b";
    }

    fout1 << s1 << " " << std::endl;
    fout2 << s2 << " " << std::endl;

    fout1.close();
    fout2.close();
    
}

void mergeFiles(std::string file1, std::string file2, std::string file3){

    std::ifstream fin1(file1+s);
    std::ifstream fin2(file2+s);

    std::ofstream fout3(file3+s);
    
    std::string temp1;
    std::string temp2;
    std::string temp3;

    if (fin1.is_open() && fin2.is_open()){
        fin1 >> temp1;
        fin2 >> temp2;
    }
    

    temp3 = temp1 + temp2;

    fout3 << temp3;

    fout3.close();

}

int main(){

    std::string file1,file2,file3;

    std::cout << "Enter the name of the first file ";
    std::cin >> file1;
    std::cout << std::endl;
    std::cout << "Enter the name of the second file ";
    std::cin >> file2;
    std::cout << std::endl;
    std::cout << "Enter the name of the third merged file";
    std::cin >> file3;
    std::cout << std::endl;

    makeFiles(file1, file2);
    mergeFiles(file1,file2,file3);


    return 0;
}