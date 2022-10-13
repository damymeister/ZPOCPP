#include<iostream>
#include "figure.h"
#include "circle.h"
using namespace std;
Circle::Circle(float r1)
{
 r=r1;
 cout<<"Konstruktor w klasie Circle"<<endl;
}
Circle::~Circle()
{
 cout<<"Destruktor w klasie Circle"<<endl;
}
void Circle:: calculateArea() //implementacja metody wirtualnej
{
float p=3.14*r*r;
float obw=2*3.14*r;
setArea(p);
setObw(obw);
}
void Circle::show()
{
 cout<<"Show w klasie Circle, pole: "<<getArea()<<endl;
 cout<<"Show w klasie Circle, obwod: "<<getObw()<<endl;
}
