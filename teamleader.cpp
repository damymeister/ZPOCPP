#include "teamleader.h"
using namespace std;
Teamleader::Teamleader()
{
    cout<<"Konstruktor bezparametrowy klasy Teamleader"<<endl;
}
Teamleader::Teamleader(string surname1, int age1, int experience1, int salary1):Employee(surname1, age1, experience1,salary1)
{
    cout<<"Konstruktor parametrowy klasy teamleader"<<endl;
}
float Teamleader::calculateBonus(int value)
{
    return value*(1+getSalary()+getExperience());
}
void Teamleader::show()
{
    cout<<"Nazwisko Pracownika: "<<getSurname()<<endl;
    cout<<"Wiek Pracownika: "<<getAge()<<endl;
    cout<<"Wyplata Pracownika: "<<getSalary()<<endl;
    cout<<"Jestem Team Leader z "<<getExperience()<<" letnim doœwiadczeniem" <<endl;
}
