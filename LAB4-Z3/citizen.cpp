#include <iostream>
#include "citizen.h"
using namespace std;
Citizen::Citizen()
{
    cout<<"Konstruktor bezargumentowy klasy citizen"<<endl;
}
Citizen::Citizen(string name1, string surname1, int age1, char sex1, string postal_code1)
{
    this->name = name1;
    this->surname = surname1;
    this->age = age1;
    this->sex = sex1;
    this->postal_code = postal_code1;
}
void Citizen::show()
{
    cout<<" Imie: "<<this->name<<" Nazwisko: "<<this->surname<<" Wiek: "<<this->age<<" Plec: "<<this->sex<<" Kod pocztowy: "<<this->postal_code<<endl;

}
string Citizen::getName()
{
    return this->name;
}
string Citizen::getSurname()
{
    return this->surname;
}
int Citizen::getAge()
{
    return this->age;
}
char Citizen::getSex()
{
    return this->sex;
}
string Citizen::getPostal_Code()
{
    return this->postal_code;
}
