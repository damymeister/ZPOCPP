#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
using namespace std;
int sumOfDigits(int v1);//Rosnaco wedlug sumy cyfr w liczbie
int numberOfDigits(int v1);//Malejaco wedlug liczby cyfr
bool porownajSumeCyfr(int i, int j);
bool porownajliczbeCyfr(int i, int j);
void wyswietl(int liczba);
int main()
{
    srand(time(NULL));
    vector <int> v1;
    v1.resize(15);
    for(int i =0 ; i < v1.size();i++)
    {
        v1[i] = rand() % 200 + 1;  //Zakres 1 do 100
    }
    cout<<"Tablica przed sortowaniem rosnaco wedlug sumy cyfr w liczbie: "<<endl;
    for_each(v1.begin(), v1.end(), wyswietl);
    cout<<" "<<endl;
    cout<<"Tablica po sortowaniu rosnaco wedlug sumy cyfr w liczbie: "<<endl;
    sort(v1.begin(), v1.end(),porownajSumeCyfr);
    for_each(v1.begin(), v1.end(), wyswietl);
     cout<<" "<<endl;
    cout<<"Tablica po sortowaniu malejaco wedlug liczby cyfr w liczbie: "<<endl;
    sort(v1.begin(), v1.end(), porownajliczbeCyfr);
    for_each(v1.begin(), v1.end(), wyswietl);
     cout<<" "<<endl;
    return 0;
}
int sumOfDigits(int v1)
{
    int sumacyfr = 0 ;
    while(v1>0)
    {
        sumacyfr += v1 % 10;
        v1 /= 10;
    }
    return sumacyfr;
}
int numberOfDigits(int v1)
{
    int liczbacyfr = 1;

        while(v1>10)
        {
            liczbacyfr++;
            v1 /= 10;
        }
    return liczbacyfr;
}
bool porownajSumeCyfr(int i, int j)
{
    return sumOfDigits(i)<sumOfDigits(j);
}
bool porownajliczbeCyfr(int i, int j)
{
    return numberOfDigits(i) > numberOfDigits(j);
}
void wyswietl(int liczba)
{
    cout<<liczba<<" ";
}
