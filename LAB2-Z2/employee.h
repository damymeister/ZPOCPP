#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
using namespace std;
class Employee
{
private:
    string surname;
    int age;
    int experience;
    int salary;
    public:
        Employee(string surname1, int age1, int experience1, int salary1);
        Employee();
        virtual ~Employee();//Wirtualny destruktor - zapewnia wywolanie wszystkich destuktorow z klas potomnych
        virtual void show();//Metoda wirtualna - zaleznie od obiektu dynamicznego, moze byc nadpisana i wywolana z pochodnych klas
        virtual float calculateBonus(int value)=0;//Metoda czysto wirtualna tzn. implementacja TYLKO w klasie bazowej
        virtual int ageEmployment();
        string getSurname();
        int getAge();
        int getExperience();
        int getSalary();
};
#endif // EMPLOYEE_H_INCLUDED
