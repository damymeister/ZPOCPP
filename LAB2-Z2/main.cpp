#include <iostream>
#include "employee.h"
#include "developer.h"
#include "teamleader.h"
using namespace std;
void whoWorkMoreThan5Years(Employee **tab,int n);
void howManyEarnLessThanMeanBonus(Employee **tab,int n);
int main()
{
    Employee** tab; //Dynamiczna tablica dynamicznych obiektow
    tab = new Employee*[4];
    tab[0] = new Developer("Malysz",42,5,8000);
    tab[1] = new Developer("Stoch",34,3,7300);
    tab[2] = new Developer("Joshua",22,15,15000);
    tab[3] = new Teamleader("Lankamer",30,8,11000);
    tab[0]->show();
    cout<<"----------------------------------"<<endl;
    tab[1]->show();
    cout<<"----------------------------------"<<endl;
    tab[2]->show();
    cout<<"----------------------------------"<<endl;
    tab[3]->show();
    cout<<"-----FUNKCJA.1--------"<<endl;
    whoWorkMoreThan5Years(tab,4);
    cout<<"-----FUNKCJA.2--------"<<endl;
    howManyEarnLessThanMeanBonus(tab,4);
    for(int i=0;i<4;i++)
        {
            delete tab[i];//Wywolanie destruktora
        }
    delete [] tab;
    return 0;
}
void whoWorkMoreThan5Years(Employee **tab,int n)
{
    for(int i=0;i<n;i++)
    {
        if(tab[i]->getExperience()>=5)
        {
            tab[i]->show();
        }
         cout<<"-------------------------------------"<<endl;
    }
}
void howManyEarnLessThanMeanBonus(Employee **tab,int n)
{
   float avgsrpremii;
   int suma=0;
   for(int i=0;i<n;i++)
   {
       suma+=tab[i]->calculateBonus(1);
   }
   avgsrpremii = suma/n;
   int ilu=0;
   for(int j =0; j<n;j++)
   {
       if(tab[j]->calculateBonus(1)<avgsrpremii)
       {
         ilu+=1;
       }
   }
   cout<<"Pracownikow ktorzy dostali mniejsza premie niz srednia jest: "<<ilu<<endl;
}
