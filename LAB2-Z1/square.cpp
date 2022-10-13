#include<iostream>
#include "figure.h"
#include "square.h"
using namespace std;
Square:: Square(float a1):Figure()
{
     a=a1;
     cout<<"Konstruktor klasy Square"<<endl;
 }
Square:: ~Square()
{
    cout<<"Destruktor klasy Square"<<endl;
}
void Square::calculateArea() //kod metody wirtualnej
{
    float p=a*a;
    float obw=a+a+a+a;
    setArea(p);
    setObw(obw);
}
void Square::show()
{
 cout<<"Show w klasie Sqaure, pole: "<<getArea()<<endl;
  cout<<"Show w klasie Sqaure, obwod: "<<getObw()<<endl;
}

