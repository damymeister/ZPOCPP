#include <iostream>
#include "dictionary.h"
using namespace std;
int main()
{
    Dictionary slownik;
    slownik.showDictionary();
    cout<<"-----------DODAJE SLOWO DO SLOWNIKA---------------"<<endl;
    slownik.addWordAndTranslate("Samochod","Car");
    slownik.showDictionary();
    cout<<"-----------USUWAM SLOWO ZE SLOWNIKA---------------"<<endl;
    slownik.deleteWordAndTranslate("Samochod");
    slownik.showDictionary();
    slownik.addWordAndTranslate("Ryba","Fish");
      slownik.addWordAndTranslate("Slon","Elephant");
    slownik.addWordAndTranslate("Kierowca","Driver");
    slownik.addWordAndTranslate("Pokoj","Zimmer");
    cout<<"-----------WYWSWIETLAM TLUMACZENIE WYBRANEGO SLOWA---------------"<<endl;
    slownik.showTranslationSpecifiedWord("Kierowca");
     cout<<"-----------PRZED SORTOWANIEM---------------"<<endl;
    slownik.showDictionary();
    cout<<"-----------WYWSWIETLAM ELEMENTY POSORTOWANE OD Z DO A WZGLEDEM TLUMACZENIA---------------"<<endl;
    slownik.showDictionaryAlphabetically();
    return 0;
}
