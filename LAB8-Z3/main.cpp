#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QPair>
using namespace std;
void show(QMap<string, int> k)
{
    QMapIterator<string, int> i(k);
    while (i.hasNext())
    {
        i.next();
        cout<<i.key()<<" - "<<i.value()<<endl;
    }
}
void showCountryNames(QMap<string, int> k)
{
    QMapIterator<string, int> i(k);
    while (i.hasNext())
    {
        i.next();
        cout<<i.key()<<endl;
    }
}
void showCountriesRange(QMap<string, int> k, int min, int max)
{
    QMapIterator<string, int> i(k);
    while (i.hasNext())
    {
        i.next();
        if (i.value() >= min && i.value() <= max)
        {
            cout<<i.key()<<" - "<<i.value()<<endl;
        }
    }
}
class CompareCountryASC {//Klasa sortuje rosnaco
public:
    bool operator() (QPair<string, int> c1, QPair<string, int> c2)
    {
        return c1.second < c2.second;
    }
};
class CompareCountryDESC {//Klasa sortuje malejaco
public:
    bool operator() (QPair<string, int> c1, QPair<string, int> c2)
    {
        return c1.second > c2.second;
    }
};
void showCountriesByInhabitants (QMap<string, int> k, bool asc = true)
{
    QMapIterator<string, int> i(k);
    QVector<QPair<string, int>> vec;
    while (i.hasNext())
    {
        i.next();
        vec.append(QPair<string, int>(i.key(), i.value()));
    }
    if (asc)
    {
        sort(vec.begin(), vec.end(), CompareCountryASC());//If asc=true, sortuje rosnaco
    }
    else
    {
        sort(vec.begin(), vec.end(), CompareCountryDESC());//If asc = false, sortuje malejaco
    }
    typename QVector<QPair<string, int>>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p)
    {
        QPair<string, int> s = *p;
        cout<<s.first<<" - "<<s.second<<endl;
    }
}
int main(int argc, char *argv[])
{
    QMap<string, int> kraje;
       kraje.insert("Polska", 36500000);
       kraje.insert("Niemcy", 83130000);
       kraje.insert("Francja", 67592384);
       kraje.insert("USA", 33734195);
       kraje.insert("Wielka Brytania", 67335481);
       cout<<"---------Wyswietlam kraje------"<<endl;
       show(kraje);
       cout<<"---------Wyswietlam nazwy krajow------"<<endl;
       showCountryNames(kraje);
       cout<<"---------Wyswietlam kraje z przedzialu 60-70mln ludnosci------"<<endl;
       showCountriesRange(kraje, 60000000, 70000000);
       kraje.remove("USA");
       cout<<endl;
       cout<<"---------Wyswietlam kraje po usunieciu USA i po sortowaniu rosnaco wzgledem liczby mieszkancow------"<<endl;
       showCountriesByInhabitants(kraje);
}
