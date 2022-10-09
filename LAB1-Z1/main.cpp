#include <iostream>
#include "person.h"
#include "teacher.h"
#include "student.h"
using namespace std;
int main()
 {
    cout<<endl<<"Obiekty klasy Person"<<endl;
    Person o1("Grazyna","Nowak",45);
    o1.showInfoPerson();
    cout<<"Czy pelnoletnia?: "<<o1.is_18()<<endl;
    o1.setAge(16);
    cout<<endl<<"Obiekty klasy Teacher"<<endl;
    Teacher n1("Barbara","Kowalska",56,30,"Phd");
    n1.showInfoTeacher();
    cout<<"Czy ma Phd?: "<<n1.is_Phd()<<endl;
    n1.setAge(34);
    Student h1("1","Ja","TY",21);
    h1.setIndex("4");//Dzialanie settera
    cout<<"Wyswietlam sam indeks: "<<h1.getIndex()<<endl;//dzialanie gettera

    h1.showInfoStudent();
    ///////Tablice

    Person p1[3];// Statyczna tablica statycznych obiektow
    Person* p2; // Dynamiczna tablica statycznych obiektow
    Person * p3[3];//Statyczna tablica dynamicznych obiekow
    Person ** p4; //Dynamiczna tablica dynamicznych obiektow
    for(int i=0; i<3; i++)
    {
        p1[i].init("Anna","Nowak",20+i);//metoda Init ustawia pola
        p1[i].showInfoPerson();
    }
    p2 = new Person[3];
    for(int i=0; i<3 ; i++)
    {
        p2[i].init("Ola","Adamek",20+i);//Metoda init ustawia pola
        p2[i].showInfoPerson();
    }
    for(int i=0; i<3; i++)
     {
     p3[i]=new Person("Kasia","Kowalska",20+i);//Konstruktor parametrowy, przydzielenie pamieci
     p3[i]->showInfoPerson();
     }
    p4=new Person*[3];
    for(int i=0; i<3; i++)
         {
         p4[i]=new Person("Pawel","Wojcik",20+i);
         p4[i]->showInfoPerson();
         }
    for(int i=0;i<3;i++)
        {
        delete p3[i];
        }
    for(int i=0;i<3;i++)
        {
        delete p4[i];
        }
delete [] p4;

    ///Tablice student
    Student s1[3];// Statyczna tablica statycznych obiektow
    Student* s2; // Dynamiczna tablica statycznych obiektow
    Student * s3[4];//Statyczna tablica dynamicznych obiekow
    Student ** s4; //Dynamiczna tablica dynamicznych obiektow
   ///////////////////////////
    s1[0].setIndex("1");
    s1[0].init("Marcin","Basak",20);
    s1[0].showInfoStudent();
    s1[0].getIndex();
    ////////////////////////////
    s2 = new Student[1];
    s2[0].setIndex("2");
    s2[0].init("Julia","Malysz",24);//Metoda init ustawia pola
    s2[0].showInfoStudent();
    ////////////////////////////
    for(int i=0; i<1; i++)
     {
     s3[i]=new Student("3","Kasia","Kowalska",25);//Konstruktor parametrowy, przydzielenie pamieci
     s3[i]->showInfoStudent();
     }
    s4=new Student*[1];
    ////////////////////////////
    for(int i=0; i<1; i++)
         {
         s4[i]=new Student("4","Pawel","Wojcik",30);
         s4[i]->showInfoStudent();//zamiast kropki  - strzalka - chodzi o typ tablicy
         }
    for(int i=0;i<1;i++)
            {
            delete s3[i];
            }
    for(int i=0;i<1;i++)
            {
            delete s4[i];
            }
delete [] s4;

    return 0;
 }
