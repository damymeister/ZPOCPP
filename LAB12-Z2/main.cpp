#include <iostream>
#include <algorithm>
#include <vector>
#include "car.h"
using namespace std;
int main () {
    vector <Car> c;
    c.push_back(Car("BMW F30", 2012, 2.0));
    c.push_back(Car("Audi A3", 2010, 1.9));
    c.push_back(Car("BMW F10", 2017, 2.4));
    c.push_back(Car("Nissan R34", 1994, 3.8));
    c.push_back(Car("Mercedes C", 2020, 2.0));
    sort(c.begin(), c.end(), [] (Car c1, Car c2) { return c1.getRok() < c2.getRok(); });
    int licz = 1;
    cout<<"Wyswietlam rosnaco wzgledem roku produkcji"<<endl;
    for_each(c.begin(), c.end(), [&licz] (Car el) { cout<<licz<<": "; el.show(); licz++; });
    sort(c.begin(), c.end(), [] (Car c1, Car c2) { return c1.getPojemnosc() > c2.getPojemnosc(); });
    licz = 1;
    cout<<"Wyswietlam po sortowaniu malejaco wzgledem pojemności"<<endl;
    for_each(c.begin(), c.end(), [&licz] (Car el) { cout<<licz<<": "; el.show(); licz++; });
    return 0;
}
