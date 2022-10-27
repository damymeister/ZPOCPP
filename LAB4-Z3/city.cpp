#include <iostream>
#include "city.h"
#include <vector>
#include <map>
using namespace std;
City::City(string city_name1)
{
    this->city_name = city_name1;
}
void City::addCitizen(Citizen newcitizen)
{
    citizens.push_back(newcitizen);
}
void City::deleteCitizen(string surname,  int age)
{
    for(int i=0; i< this->citizens.size();i++)
    {
        if(surname == this->citizens[i].getSurname() && age == this->citizens[i].getAge())
        {
            citizens.erase(this->citizens.begin()+i);
        }
    }
}
void City::show_citizens()
{
    for(int i=0; i < this->citizens.size(); i++)
    {
        this->citizens[i].show();
    }
}
void City::show_city()
{
    cout<<"Miasto: "<<this->city_name<<endl;
}
int City::women()
{
       int howmanywomen=0;
    for(int i=0;i<this->citizens.size();i++)
    {
        if(this->citizens[i].getSex()=='W')
        {
            howmanywomen ++;
        }
    }
    return howmanywomen;
}
int City::city_citizens()
{
       return this->citizens.size();
}
int City::adults()
{
    int howmanyadults=0;
    for(int i=0;i<this->citizens.size();i++)
    {
        if(this->citizens[i].getAge()>=18)
        {
            howmanyadults ++;
        }
    }
    return howmanyadults;
}
//Jak damy 0 nie drukuje, jak damy 1 to drukuje wartosci
int City::postal_codes(int czydrukuj)
{
    map <string, int> m;//Map przyjmuje wartosc i klucz tutaj String(kod pocztowy) oraz wartosc ( ile
    for(int i=0; i< citizens.size();i++)
    {
        string kod_pocztowy = this->citizens[i].getPostal_Code();
        ++m[kod_pocztowy];
    }
    int ile=0;
    for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if(czydrukuj==1) cout<<i->first<<" -> ";//First czyli string w zadeklarowanym map, i to iterator wskazujacy na poczatek mapy
        if(i->second > 1)//Gdy wartosci (danego kodu pocztowego) jest wiecej niz jeden
        {
           if(czydrukuj==1) cout<<i->second<<" mieszkancow "<<endl;//Drukuj wartosc
        }
        else
        {
            if(czydrukuj==1) cout<<"unikatowy"<<endl;//Gdy jest tylko jeden kod pocztowy (unikatowy)
            ile++;
        }
    }
    return ile;
}
