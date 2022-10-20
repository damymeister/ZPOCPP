#include <iostream>
#include "array.h"
using namespace std;
int main()
{
    cout<<"INT: "<<endl;
    Array <int> *o1 = new Array <int>();
    o1->addTab(5);
    o1->addTab(3);
    o1->addTab(1);
    o1->addTab(7);
    o1->show_tab();
    o1->sortAscendigly();
    o1->show_tab();
    cout<<"Wyswietlam element MaxTab INT: "<<o1->returnMaxfromTab()<<endl;
    cout<<"Wyswietlam element o indeksie podanym INT: "<<o1->getTabIndex(2)<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"STRING: "<<endl;
    Array <string> *o2 = new Array <string>();
    o2->addTab("Mateusz");
    o2->addTab("GabrielKoz");
    o2->addTab("Julia");
    o2->addTab("MiloszSzSzSz");
    o2->show_tab();
    o2->sortAscendigly();
    o2->show_tab();
    cout<<"Wyswietlam element MaxTab STRING: "<<o2->returnMaxfromTab()<<endl;
    cout<<"Wyswietlam element o indeksie podanym STRING: "<<o2->getTabIndex(2)<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"DOUBLE: "<<endl;
    Array <double> o3 (4);
    o3.addTab(1.3);
    o3.addTab(0.8);
    o3.addTab(5.3);
    o3.addTab(3.9);
    o3.show_tab();
    o3.sortAscendigly();
    o3.show_tab();
    cout<<"Wyswietlam element MaxTab Double: "<<o3.returnMaxfromTab()<<endl;
    cout<<"Wyswietlam element o indeksie podanym Double: "<<o3.getTabIndex(2)<<endl;
    cout<<"----------------------------"<<endl;
    return 0;

}
