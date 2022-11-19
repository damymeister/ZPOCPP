#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>
#define MAX_M(a, b) a > b ? a : b
#define MIN_M(a, b) a < b ? a : b
using namespace std;
void show(int liczba, bool tru);
template <typename T>
void statistics(vector <T> v1) {
    int s = v1.size();
    double srednia = 0.0;
    double suma = 0.0;
    for (int i = 0; i < s; i++)
    {
        suma+= v1[i];
    }
    srednia = suma / s;
    vector < T > Vec2 = v1;
    double mediana;
    sort(Vec2.begin(), Vec2.end());
    if (s % 2 == 0)
    {
        mediana = 1.0 * (Vec2[(s / 2)] + Vec2[(s / 2) - 1]) / 2.0;
    }
    else
    {
        mediana = Vec2[s / 2];
    }
    cout<<"Srednia: "<<srednia<<endl;
    cout<<"Mediana: "<<mediana<<endl;
    cout<<"Elementy mniejsze od sredniej: ";
    for_each(v1.begin(), v1.end(), boost::bind(show, _1, boost::bind(less<T>(), _1, srednia)));
    cout<<endl<<"Elementy miedzy srednia a mediana: ";
    for_each(v1.begin(), v1.end(), boost::bind(show, _1, boost::bind(logical_and<T>(), boost::bind(greater<T>(), _1, MIN_M(srednia, mediana)), boost::bind(less<T>(), _1, MAX_M(srednia, mediana)))));
    cout<<endl<<"Elementy dodatnie: ";
    for_each(v1.begin(), v1.end(), boost::bind(show, _1, boost::bind(greater<T>(), _1, 0)));
}
int main()
{
    vector < int > v1 = {-8,-6,4,-3,1,-5,5,-10,8,14,12,22,2,54};
    cout<<"Wyswietlam tablice: ";
    for (int i = 0; i < v1.size(); i++)
    {
        show(v1[i], true);
    }
    cout<<endl;
    statistics(v1);
    cout<<endl;
    return 0;
}
void show(int liczba, bool tru)
{
    if(tru)
    {
        cout<<liczba<<" ";
    }
}
