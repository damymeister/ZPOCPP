#include "dog.h"
#include <iostream>
using namespace std;
Dog::Dog(int limbNr1, string name1, bool protectedAnimal1, string breed1,int levelOfGuideSkills1, int levelOfTrackerSkills1):Animal(limbNr1, name1,protectedAnimal1)
{
    breed=breed1;
    levelOfGuideSkills=levelOfGuideSkills1;
    levelOfTrackerSkills=levelOfTrackerSkills1;
}
Dog::Dog(int limbNr1, string name1, bool protectedAnimal1) : Animal(limbNr1, name1, protectedAnimal1)
{
    cout<<"Jestem konstuktorem z animal ale w Dog"<<endl;
}
Dog::Dog()
{
    cout<<"Konstruktor bezparametrowy klasy Dog"<<endl;
}
void Dog:: setSkillLevel(int type, int value)
{
   if(type>0&&type<2)
      {
            if(type==1)
           {
                levelOfGuideSkills=value;;
           }
            else
            {
                levelOfTrackerSkills=value;
            }
      }
    else
      {
        cout<<"Wprowadz poprawne dane!"<<endl;
       }
}
int Dog:: getSkillLevel(int type)
{
   if(type==1)
   {
       return levelOfGuideSkills;
   }
    else
    {
        return levelOfTrackerSkills;
    }
}
void Dog::giveVoice()
{
    cout<<"Hau,hau"<<endl;
}
void Dog::info()
{
    Animal::info();//dostep do metody przyslonietej z klasy bazowej
    cout<<"Rasa psa: "<<breed<<endl;
    cout<<"Poziom umiejetnosci przewodnika: "<<levelOfGuideSkills<<endl;
    cout<<"Poziom umiejetnosci tropiciela: "<<levelOfTrackerSkills<<endl;
}
