#include <iostream>
#include "bufor.h"
#include "meanbufor.h"
#include "maxbufor.h"
using namespace std;
int main () {
    MaxBufor a(10);
    MeanBufor b(10);
    b.add(3);
    b.add(5);
    a.add(8);
    a.add(6);
     cout<<"Drukuje tablice MeanBufor"<<endl;
    b.print();
    cout<<"Drukuje tablice MaxBufor"<<endl;
    a.print();
    cout<<"MaxBufor: "<<a.calculate()<<endl;
    cout<<"Meanbufor: "<<b.calculate()<<endl;
    return 0;
}
