#include <iostream>
#include "bufor.h"
using namespace std;
Bufor::Bufor()
{
    int zmienna=10;
    tab = new int[zmienna];
    index=0;
}
Bufor::Bufor(int n1)
{
    n=n1;
    tab = new int[n1];
    index=0;
}
Bufor::~Bufor()
{
    delete []tab;
}
void Bufor::add(int value)
{
    tab[index]=value;
    index++;
}
int Bufor::getIndex()
{
    return index;
}
int Bufor::getSize()
{
    return n;
}
int Bufor::getTab(int i)
{
    return tab[i];
}
int Bufor::getFirst()
{
    return tab[index-1];
}
void Bufor::setFirst(int value)
{
 index=value;
}
void Bufor::setTab(int pos, int value)
{
 tab[pos]=value;
}
void Bufor::print()
{
    for(int i=0;i<index;i++)
    {
        cout<<tab[i]<<endl;
    }
}

