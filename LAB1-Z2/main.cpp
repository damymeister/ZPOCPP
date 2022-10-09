#include <iostream>
#include <iostream>
#include "dog.h"
#include "cat.h"
#include "animal.h"
using namespace std;
int howManyProtectedAnimals(Animal *t1[],int tabSize1);
void howManyTrackerDogs(Dog *t2[],int tabSize2);
void howManyCats(Cat *t3[],int tabSize3);
int main()
{
    cout<<"Obiekt klasy Animal"<<endl;
    Animal o1(10,"Kurczak",true);
    o1.info();
    o1.setLimbNr(5);
    o1.setName("Kurczaczek");
    o1.setProtectedAnimal(false);
    cout<<"---------------------------------------------"<<endl;
    cout<<"Gettery"<<endl;
    cout<<o1.getName()<<endl;
    cout<<o1.getLimbNr()<<endl;
    cout<<o1.getProtectedAnimal()<<endl;
   cout<<"---------------------------------------------"<<endl;
    o1.info();
    cout<<"---------------------------------------------"<<endl;
    cout<<"Obiekt klasy Dog"<<endl;
    Dog o2(5,"Pies",false,"Cavapoo",5,8);
    o2.info();
    cout<<"Sprawdzam dzialanie Settera:"<<endl;
    o2.setSkillLevel(1,9);
    cout<<o2.getSkillLevel(1)<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Obiekt klasy Cat"<<endl;
    Cat o3(4,"Kot",false);
    o3.setLevelOfMouseHunting(8);
    o3.info();
    cout<<"---------------------------------------------"<<endl;
    cout<<"Init"<<endl; //Metoda init
    o3.initCat(5);
    o3.info();
    cout<<endl;
    ////TABLICE OBIEKTOW
    cout<<"------------TABLICE OBIEKTOW --------------------"<<endl;
    cout<<endl;
    Animal * t1[3];
    t1[0]=new Animal(4,"Zyrafa",true);
    t1[1]=new Animal(8,"Pajak",false);
    t1[2]=new Animal(2,"Strus",true);
    cout<<"Jak duzo jest chronionych zwierzat: "<<howManyProtectedAnimals(t1,3)<<endl;
   cout<<"---------------------------------------------"<<endl;
    Dog * t2[3];
    t2[0]=new Dog(4,"Pies",false,"Owczarek",5,8);
    t2[1]=new Dog(4,"Pies",false,"York",3,2);
    t2[2]=new Dog(4,"Pies",false,"Terrier",5,2);
    howManyTrackerDogs(t2,3);
    cout<<"---------------------------------------------"<<endl;
    Cat * t3[3];
    t3[0]=new Cat(4,"Kotek1",false);
    t3[0]->setLevelOfMouseHunting(4);
    t3[1]=new Cat(4,"Kotek2",false);
    t3[1]->setLevelOfMouseHunting(8);
    t3[2]=new Cat(4,"Kotek3",false);
    t3[2]->setLevelOfMouseHunting(1);
    howManyCats(t3,3);
    return 0;
}
int howManyProtectedAnimals(Animal *t1[],int tabSize1)
{
    int outcome=0;
    for(int i=0;i<tabSize1;i++)
    {
        if(t1[i]->getProtectedAnimal()==1)
        {
            outcome+=1;
        }
    }
    return outcome;
}
void howManyTrackerDogs(Dog *t2[],int tabSize2)
{
    for(int i=0; i<tabSize2;i++)
    {
        if((t2[i]->getSkillLevel(1))<(t2[i]->getSkillLevel(2)))
        {
            t2[i]->Dog::info();
        }
    }
}
void howManyCats(Cat *t3[],int tabSize3)
{
    for(int i=0;i<tabSize3;i++)
    {
        int suma=0;
      t3[i]->initMice();
        for(int j=0;j<5;j++)
        {
            suma= suma+ t3[i]->getMice(j);
        }
        t3[i]->Cat::info();
        cout<<"Liczba upolowanych myszy: "<<suma<<endl;
    }

}
