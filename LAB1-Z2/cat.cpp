#include "cat.h"
#include <iostream>
#include <cstdlib>
Cat::Cat(int limbNr1, string name1, bool protectedAnimal1):Animal(limbNr1, name1,protectedAnimal1)
{
    cout<<"Konstruktor Parametrowy Animal w CAT"<<endl;
}
Cat::Cat()
{
    cout<<"Konstruktor bezparametrowy klasy Cat"<<endl;
}
void Cat::initMice()
{
    for(int i=0;i<5;i++)
    {
        mice[i]=rand() % 100 + 1;
    }
}
void Cat::initCat(int levelOfMouseHunting1 )
{
  levelOfMouseHunting=levelOfMouseHunting1;
  //Cat(limbNr1, name1,  protectedAnimal1);//konstruktor wywolany drugi raz
}
void Cat:: setLevelOfMouseHunting(int value)
{
  if(value<11 && value>0) levelOfMouseHunting=value;
  else cout<<"Wprowadz prawidlowe dane!";
}
int Cat::getLevelOfMouseHunting()
{
    return levelOfMouseHunting;
}
int Cat::getMice(int index)
{
    return mice[index];
}
void Cat::giveVoice()
{
    cout<<"Miau miau"<<endl;
}
void Cat::info()
{
    Animal::info();
    cout<<"Poziom umiejetnosci lowienia myszy: "<<levelOfMouseHunting<<endl;
}
