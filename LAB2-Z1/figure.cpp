#include <iostream>
#include "figure.h"
using namespace std;
Figure::Figure()
{
    cout<<"Konstruktor klasy bazowej Figure"<<endl;
}
Figure:: ~Figure()
{
 cout<<"Wirtualny destruktor klasy bazowej Figure"<<endl;
}
float Figure:: getArea()
{
    return area;
}
void Figure::setArea(float area1)
{
    area=area1;
}
float Figure:: getObw()
{
    return obw;
}
void Figure::setObw(float obw1)
{
    obw=obw1;
}
void Figure::show()
{
 cout<<"Pole: "<<area<<endl;
}
