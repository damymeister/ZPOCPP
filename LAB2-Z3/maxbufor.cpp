#include <iostream>
#include "maxbufor.h"
using namespace std;
MaxBufor::MaxBufor(int n1):Bufor(n1)
{
    cout<<"Max Bufor Konstruktor"<<endl;
}
double MaxBufor::calculate()
{
    double max=getFirst();
    for(int i=0;i<getIndex();i++)
    {
        if(getTab(i)>max)
        {
            max=getTab(i);
        }
    }
    return max;
}
void MaxBufor::add(int value)
{
    if(getIndex()>=getSize())
    {
        cout<<"Nie ma miejsca wolnego w tablicy!"<<endl;
    }
    else
    {
       setTab(getIndex(),value);
       setFirst(getIndex()+1);
    }
}
