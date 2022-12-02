#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QPair>
#include "car.h"
using namespace std;
void show (QVector<Car> vec)
{
    typename QVector<Car>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p)
    {
        Car s = *p;
        s.show();
    }
}
int autaStarszeOd (QVector<Car> vec, int year)
{
    int ile = 0;
    typename QVector<Car>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p) {
        Car s = *p;
        if (s.getYear() < year)
        {
            ile++;
        }
    }
    return ile;
}
void usunPoVinie (QVector<Car> &vec, string vin) {
    typename QVector<Car>::iterator p;
    int i = 0;
    for (p = vec.begin(); p != vec.end(); ++p)
    {
        Car s = *p;
        if (s.getVin() == vin)
        {
            vec.remove(i);
        }
        i++;
    }
}
class CompareYear {
public:
    bool operator() (Car c1, Car c2)
    {
        return c1.getYear() > c2.getYear();
    }
};
class CompareBrand {
public:
    bool operator() (Car c1, Car c2)
    {
        string b1 = c1.getMarka();
        string b2 = c2.getMarka();
        int l1 = b1.length();//Dlugosc wyrazu nazwy samochodu nr1
        int l2 = b2.length();//Dlugosc wyrazu nazwy samochodu nr2
        if (l1 > l2)
        {
            for (int i = l2; i < l1; i++)
            {
                b2 += '0';//Uzupelniamy zerami zeby wyrazy byly rowne
            }
        }
        if (l1 < l2)
        {
            for (int i = l1; i < l2; i++)
            {
                b1 += '0';//Uzupelniamy zerami zeby wyrazy byly rowne
            }
        }
        l1 = b1.length();
        for (int i = 0; i < l1; i++)
        {
            if (b1.at(i) < b2.at(i))
            {
                return true;
            }
            if (b1.at(i) > b2.at(i))
            {
                return false;
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<Car> katalog;
    srand(time(NULL));
    katalog.append(Car("BMW", "F30", "B4Z1HS726SD123456", 2013));
    katalog.append(Car("Merecedes", "GLE", "CZESHS532AZ123456", 2017));
    katalog.append(Car("Fiat", "Panda", "1AGSHS726SD1BAZ4D", 2004));
    katalog.append(Car("Aston Martin", "Vantage", "53GSHS724SD12PORZ", 2020));
    katalog.append(Car("Ford", "Mustang", "CZ135S726SD123456", 2012));
    katalog.append(Car("Audi", "TT", "GESSHBAZ6SD123742", 2007));
    cout<<"-------------Wyswietlam Katalog------------------"<<endl;
    show(katalog);
    cout<<"-------------Wyswietlam ilosc aut starszych od 2008r: ";
    cout<<autaStarszeOd(katalog, 2008)<<endl;
    usunPoVinie(katalog, "CZ135S726SD123456");
    sort(katalog.begin(), katalog.end(), CompareYear());
    cout<<"-------------Wyswietlam po usunieciu AUDI TT i po sortowaniu wzgledem roku produkcji------------------"<<endl;
    show(katalog);
    cout<<endl;
    sort(katalog.begin(), katalog.end(), CompareBrand());
    cout<<"-------------Wyswietlam po sortowaniu wzgledem marki------------------"<<endl;
    show(katalog);
}
