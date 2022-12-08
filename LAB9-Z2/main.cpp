#include <iostream>
using namespace std;
void sprawdzSume (int suma) {
    if (suma > 21)
    {
        throw runtime_error("Suma wieksza od 21!");
    }
}
int main()
{
    int suma = 0;
    int udane = 0;
    int nieudane = 0;
    int liczba;
    bool over = false;
    cout<<"Nacisnij jakis klawisz zeby rozpoczac gre!"<<endl;
    while(!over)
    {
        do{
            cin.clear();
            cin.ignore();
            cout<<"Podaj liczbe calkowita"<<endl;
            cin>>liczba;

        }while(!cin);
    suma += liczba;
    udane ++;
    if(suma == 21)
    {
        cout<<"Oczko!"<<endl;
        cout<<"Ilosc prob udanych: "<<udane<<endl;
        cout<<"Ilosc prob nieudanych: "<<nieudane<<endl;
        over = true;
    }
    try{
        sprawdzSume(suma);
    }
    catch(exception &ex)
    {
        cout<<"Suma jest wieksza niz 21!"<<endl;
        cout<<"Wprowadz liczbe ponownie!"<<endl;
        suma = suma - liczba;
        if(udane>0)
        {
        udane --;
        }
        nieudane++;
    }
    }
    return 0;
}
