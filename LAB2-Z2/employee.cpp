using namespace std;
#include "employee.h"
Employee::Employee()
{
    cout<<"Konstruktor bezparametrowy klasy Employee"<<endl;
}
Employee::Employee(string surname1, int age1, int experience1, int salary1)
{
    surname=surname1;
    age=age1;
    experience=experience1;
    salary=salary1;
}
Employee::~Employee()
{
    cout<<"Wirtualny Destruktor klasy employee"<<endl;
}
string Employee::getSurname()
{
    return surname;
}
int Employee::getAge()
{
    return age;
}
int Employee::getExperience()
{
    return experience;
}
int Employee::getSalary()
{
    return salary;
}
void Employee::show()
{
    cout<<"Nazwisko Pracownika: "<<surname<<endl;
    cout<<"Wiek Pracownika: "<<age<<endl;
    cout<<"Staz Pracownika: "<<experience<<endl;
    cout<<"Wyplata Pracownika: "<<salary<<endl;
}
int Employee::ageEmployment()
{
    int currentYear=2022;
    return currentYear - age;
}
