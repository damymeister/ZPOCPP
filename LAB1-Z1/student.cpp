#include <iostream>
#include "student.h"
using namespace std;
Student::Student(string index1, string name1, string surname1, int age1) : Person(name1, surname1, age1)
    {
        index=index1;
        cout<<"Pochodze z klasy Student"<<endl;
    }
       Student::Student()
  {
    cout<<"Konstruktor bez. klasy bazowej – Person"<<endl;
  }
   void Student::setIndex(string newIndex)
    {
        index=newIndex;
    }
    string Student:: getIndex()
    {
        return index;
    }
    void Student::showInfoStudent()
    {
        showInfoPerson();
        cout<<"Indeks: "<<index<<endl;
    }

