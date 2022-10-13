#include <iostream>
#include "developer.h"
using namespace std;
Developer::Developer()
{
    cout<<"Konstruktor bezparametrowy klasy Developer"<<endl;
}
Developer::Developer(string surname1, int age1, int experience1, int salary1):Employee(surname1, age1, experience1,salary1)
{
    cout<<"Konstruktor parametrowy klasy developer"<<endl;
}
float Developer::calculateBonus(int value)
{
    return value + (0.2*value)*(getSalary()+ getExperience());
}
