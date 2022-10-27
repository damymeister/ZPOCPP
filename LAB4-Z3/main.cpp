#include <iostream>
#include "city.h"
#include "citizen.h"
#include <vector>
using namespace std;
void showCities(vector <City> c);
void the_most(vector<City> c, int mode);
void statatistic(vector <City> c);
void sort_cities(vector <City> &c);
int main()
{
    vector <City> c; //Tworze wektor obiektow klasy city
    c.push_back(City("Opole Lubelskie"));//Konstruktor klasy city, dodaje miasto na koniec vektora c
    c.push_back(City("Lublin"));
    c.push_back(City("Pulawy"));
    c.push_back(City("Poniatowa"));
    c.push_back(City("Warszawa"));
    Citizen o1("Mateusz","Adamczyk",21,'M',"24-300");//Konstruktor klasy citizen
    c[0].addCitizen(o1);//Dodajemy obywatela na indeks 0 w wektorze
    Citizen o2("Joanna","Alfler",41,'W',"21-324");
    Citizen o11("Janusz","Amermajster",11,'M',"21-324");
    Citizen o12("Kain","Montana",27,'M',"66-353");
    c[1].addCitizen(o2);
    c[1].addCitizen(o11);
    c[1].addCitizen(o12);
    Citizen o3("Zbigniew","Mentzen",62,'M',"20-301");
    Citizen o7("Stanislaw","Strawa",16,'M',"30-301");
    c[2].addCitizen(o7);
    c[2].addCitizen(o3);
    Citizen o4("Jaroslaw","Kmiec",33,'M',"21-321");
    Citizen o15("Dorota","Rinn",10,'W',"20-312");
    Citizen o16("Janina","Lech",93,'W',"20-312");
    Citizen o17("Bolek","Niewielski",68,'M',"20-312");
    c[3].addCitizen(o4);
    c[3].addCitizen(o15);
    c[3].addCitizen(o17);
    c[3].addCitizen(o16);
    Citizen o5("Beata","Socha",53,'W',"33-600");
    Citizen o6("Baba","Wanga",32,'W',"31-300");
    Citizen o20("Mariusz","Koziarski",47,'M',"24-123");
    Citizen o21("Dorota","Koziarska",45,'W',"24-123");
    Citizen o22("Jadwiga","Ostrowska",70,'W',"24-123");
    Citizen o23("Konrad","Szczesny",40,'M',"24-123");
    c[4].addCitizen(o5);
    c[4].addCitizen(o6);
    c[4].addCitizen(o20);
    c[4].addCitizen(o21);
    c[4].addCitizen(o22);
    c[4].addCitizen(o23);
    showCities(c);
    statatistic(c);
    sort_cities(c);
    cout<<"Wyswietlam posortowane"<<endl;
    for(int i=0;i<c.size();i++)
    {
        c[i].show_city();
    }
    cout<<"Wyswietlam kody pocztowe"<<endl;
     for(int i=0;i<c.size();i++)
    {
        c[i].postal_codes(1);
    }
    the_most(c,1);
    the_most(c,2);
    return 0;
}
void showCities(vector <City> c)
{
    for(int i=0; i<c.size();i++)
    {
        c[i].show_city();
        c[i].show_citizens();
        cout<<"Ilosc kobiet: "<<c[i].women()<<endl;
        cout<<"Ilosc osob doroslych: "<<c[i].adults()<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
void statatistic(vector <City> c)
{
    cout<<"FUNKCJA STATISTICS"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
     for(int i=0; i<c.size();i++)
    {
        c[i].show_city();
        cout<<"Liczba mieszkancow miasta: "<<c[i].city_citizens()<<endl;
        cout<<"Kobiety: "<<c[i].women()<<endl;
        cout<<"Mezczyzni: "<<c[i].city_citizens()-c[i].women()<<endl;
        cout<<"Pelnoletni: "<<c[i].adults()<<endl;
        cout<<"Niepelnoletni: "<<c[i].city_citizens()-c[i].adults()<<endl;
        cout<<"----------------------------------------"<<endl;
    }
}
void sort_cities(vector <City> &c)
{
    for(int i=0; i < c.size();i++)
    {
        for(int j = i; j <c.size();j++)
        {
            if(c[i].city_citizens()>c[j].city_citizens())
               {
                   swap(c[i],c[j]);
               }
        }
    }
}
void the_most(vector<City> c, int mode)
{
    if(mode==1)
    {
        int index =0;
        int max = c[0].postal_codes(0);
        for (int i=1; i< c.size();i++)
        {
            if(c[i].postal_codes(0)>max)
            {
                max = c[i].postal_codes(0);
                index=i;
            }
        }
        cout<<"Miasto z najwieksza iloscia unikalnych kodow pocztowych: ";
        c[index].show_city();
        return;
    }
    if(mode==2)
    {
        int index2 = 0;
        int min = c[0].city_citizens();
        for (int i=1; i< c.size();i++)
        {
            if(c[i].city_citizens() < min)
            {
                min = c[i].postal_codes(0);
                index2=i;
            }
        }
        cout<<"Miasto o najmniejszej liczbie mieszkancow: ";
        c[index2].show_city();
        return;
    }
}
