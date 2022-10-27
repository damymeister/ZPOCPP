#include <iostream>
#include <random>
#include <algorithm>
#include <list>
#include "time.h"
using namespace std;
void print (int z){
    cout<<z<<" ";
}
int main()
{
    srand(time(NULL));
    int n;
    n = rand() % 10 + 1;
    int liczba;
    list <int> liczby;
    for(int i=0;i<n;i++)
    {
        liczba = rand() % 201 - 100;
        if(liczba>=0)
        {
            liczby.push_front(liczba);
        }
        else
        {
            liczby.push_back(liczba);
        }
    }
    for_each(liczby.begin(), liczby.end(), print);
    return 0;
}
