#include <iostream>
#include "contacts.h"
using namespace std;
int main () {
    Contacts K;
    K.addNewContact("Matthew","Adamczyk",21,"511214667","Dluga");
    K.addNewContact("Julia","Dawidson",15,"663969202","Lubelska");
    K.addNewContact("Dawid","Guetta",50,"332511496","Ibiza");
    K.addNewContact("Jan","Muzykant",90,"512673212","Pilsudskiego");
    K.addNewContact("Mikolaj","Kopernik",53,"544212235","Zalesie");
    K.addNewContact("Kim","Kardashian",42,"664969203","Manhattan");
    cout<<"---------------------------Wyswietlam KSIAZKE TELEFONICZNA: -------------------------"<<endl;
    K.show();
    K.usun("511214667");
    cout<<"---------------------Wyswietlam KSIAZKE TELEFONICZNA po usunieciu pierwszej osoby po numerze Tel.: ------------------"<<endl;
    K.show();
    cout<<"---------------------------Wyswietlam po nazwie Ulicy: -------------------------"<<endl;
    K.findByStreet("Lubelska");
    cout<<"---------------------------Wyswietlam w przedziale wiekowym 40-55: -------------------------"<<endl;
    K.findByRange(40,55);
    cout<<"---------------------------Wyswietlam po numerze telefonu: -------------------------"<<endl;
    K.findByPhone("663969202");
    cout<<"---------------------------Zmieniam nazwe ulicy Pilsudskiego na Dmowskiego: -------------------------"<<endl;
    K.changeStreetName("Pilsudskiego","Dmowskiego");
    K.show();
    cout<<"Liczba osob powyzej 18 roku zycia: "<<K.howManyAdults()<<endl;
    cout<<"Liczba osob o unikatowych nazwiskach w ksiaze telefonicznej: "<<K.howManyUniqueSurnames()<<endl;
    return 0;
}
