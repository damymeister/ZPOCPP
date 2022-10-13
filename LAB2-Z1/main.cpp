#include <iostream>
#include "figure.h"
#include "square.h"
#include "circle.h"
using namespace std;
//Linijki 10,15, sprawdzany jest typ dynamiczny i na jego podstawie wywolywana jest odpowiednia metoda
int main()
{
    Figure* f1=new Square(5);//tworzenie wskaznika o typie statycznym figure i dynamicznym square - wywola sie konstruktor figure i square
    Figure* f2=new Circle(3);//tworzenie wskaznika o typie statycznym figure i dynamicznym circle - wywola sie konstruktor figure i square

    f1->calculateArea();//polimorficzne wywolanie metody calculatearea, strzalka bo typ dynmaiczny
    f1->show();

    f2->calculateArea();
    f2->show();

    delete f1;//destuktory, zwolnienie pamieci
    delete f2;//destruktory, zwolnienie pamieci

    cout<<"---------------------------"<<endl;

  Figure* tab[3];
  tab[0]=new Square(4);
  tab[1]=new Square(2);
  tab[2]=new Circle(5);
for(int i=0;i<3;i++)
{
    tab[i]->calculateArea();
    delete tab[i];
}
return 0;
 }
