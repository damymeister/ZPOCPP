#include "animal.h"
#include <iostream>
using namespace std;
Animal::Animal(int limbNr1, string name1, bool protectedAnimal1)
{
    limbNr=limbNr1;
    name=name1;
    protectedAnimal=protectedAnimal1;
    protectedAnimal1=true;
}
Animal::Animal()
{
    cout<<"Konstruktor bezparametrowy klasy Animal"<<endl;
}
void Animal:: setLimbNr(int NewLimbNr)
{
    limbNr=NewLimbNr;

}
void Animal:: setName(string NewName)
{
    name=NewName;
}
void Animal::setProtectedAnimal(bool NewProtectedAnimal)
{
    protectedAnimal=NewProtectedAnimal;
}
int Animal:: getLimbNr()
{
    return limbNr;
}
string Animal:: getName()
{
    return name;
}
bool Animal :: getProtectedAnimal()
{
    return protectedAnimal;
}
void Animal :: giveVoice()
{
    cout<<"Chrum, miau, hau, piiii"<<endl;
}
void Animal::info()
{
    cout<<"Liczba Konczyn: "<<limbNr<<endl;
    cout<<"Nazwa zwierzecia: "<<name<<endl;
    cout<<"Czy zwierze jest chronione: "<<protectedAnimal<<endl;
}
