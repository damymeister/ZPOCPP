#include <iostream>
#include "meanbufor.h"
using namespace std;
MeanBufor::MeanBufor(int n1):Bufor(n1)
{
    cout<<"Mean Bufor Konstruktor"<<endl;
}
double MeanBufor::calculate()
{
    int suma=0;
    for(int i =0; i<getIndex(); i++)
    {
        suma += getTab(i);
    }
    double srednia;
    srednia = suma / getIndex();
    return srednia;
}
