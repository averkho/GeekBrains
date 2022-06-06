#include <iostream>
#include <string>
#include <fstream>

//Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы 
//pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с 
//помощью sizeof. Сохраните эту структуру в текстовый файл.

#pragma pack(push,1)
struct Employee{

    int age;
    std::string name;
    int salary;
    int department;
};
#pragma pack(pop)

void printEmployee(Employee *employee){
    std::cout << "Name is " << employee->name << std::endl;
    std::cout << "Age = " << employee->age << " years" << std::endl;
    std::cout << "Salary = "<< employee->salary << " RUR" << std::endl;
    std::cout << "Department = "<< employee->department << std::endl;
    std::cout << "The size of struct is " << sizeof(employee) << std::endl;
}

void saveEmployee(Employee *employee){

    std::ofstream fout("employee.txt");
    fout << "Name is " << employee->name << std::endl;
    fout << "Age = " << employee->age << " years" << std::endl;
    fout << "Salary = "<< employee->salary << " RUR" << std::endl;
    fout << "Department = "<< employee->department << std::endl;
    fout << "The size of struct is " << sizeof(employee) << std::endl;
    fout.close();
}

int main(){

    Employee* employee=new Employee;
    employee->age=10;
    employee->name="Victor";
    employee->salary=10000;
    employee->department=5;

    printEmployee(employee);
    saveEmployee(employee);

    delete employee;

    return 0;
}