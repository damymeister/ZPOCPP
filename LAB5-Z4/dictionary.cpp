#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "dictionary.h"
using namespace std;
Dictionary::Dictionary()
{
    cout<<"Konstruktor bezparametrowy klasy dictionary"<<endl;
}
string Dictionary :: toLower(string str)
{
    string lowerString = "";
    for(int i=0; i<str.size();i++)
    {
        if(str.at(i)>=65 && str.at(i)<=90)
        {
            lowerString += (char) str.at(i) + 32;
        }
        else
        {
            lowerString += str.at(i);
        }
    }
    return lowerString;
}
void Dictionary::addWordAndTranslate(string word, string translation)
{
   string lowerCaseWord = toLower(word);
   string lowerCaseTranslation = toLower(translation);
     if (this->words.find(lowerCaseWord) != this->words.end()) { //Jezeli indeks znalezionego slowa jest rozny od indeksu za ostatnim slowem w mapie
        cout<<"Slowo juz jest w slowniku!"<<endl;
     }
     else
     {
        this->words.insert(make_pair(lowerCaseWord,lowerCaseTranslation));
     }
}
void Dictionary::deleteWordAndTranslate(string word)
{
     string lowerCaseWord = toLower(word);
    if(this->words.find(lowerCaseWord) == this->words.end())
    {
        cout<<"Nie ma takiego slowa w Slowniku"<<endl;
    }
    else
    {
        this->words.erase(lowerCaseWord);
    }
}
void Dictionary::showDictionary(){
    if (this->words.empty()) {
        cout<<"Slownik jest pusty!"<<endl;
    }
    else
    {
        for (map<string, string>::iterator i = this->words.begin(); i != this->words.end(); ++i)
            {
                cout<<i->first<<" -> "<<i->second<<endl;
            }
    }
}
void Dictionary :: showTranslationSpecifiedWord(string word)
{
     string lowerCaseWord = toLower(word);
     if(this->words.find(lowerCaseWord) == this->words.end())
    {
        cout<<"Nie ma takiego slowa w Slowniku"<<endl;
    }
    else
    {
        cout<<"Slowo: "<<this->words.find(lowerCaseWord)->first;
        cout<<" - ";
        cout<<"Tlumaczenie: "<<this->words.find(lowerCaseWord)->second<<endl;
    }
}
bool Dictionary ::compare(pair <string, string> translation1 , pair <string, string> translation2)
{
     string t1 = translation1.second;//Driver
     string t2 = translation2.second;//Zimmer
     int t1l = t1.length(); //6
     int t2l = t2.length(); //6
    if (t1l > t2l)
    {
        for (int i = t2l; i < t1l; i++)
        {
            t2 += '0';
        }
    }
    if (t1l < t2l)
    {
        for (int i = t1l; i < t2l; i++) //4<8    4 5 6 7
        {
            t1 += '0'; //"Fish0000"
        }
    }
    t1l = t1.length(); // 4
    for (int i = 0; i < t1l; i++) { // 0 1 2 3
        if (t1.at(i) > t2.at(i))
        {
            return true;
        }
        if (t1.at(i) < t2.at(i))
        {
            return false; //D<Z //Jezeli false, zamienia miejscami
        }
}
    return true;
}
void Dictionary :: showDictionaryAlphabetically() // od z do a wzgledem drugiej wartosci (tlumaczenia)
{
     if (this->words.empty()) {
        cout<<"Slownik jest pusty"<<endl;
    }
    else
    {
       vector <pair<string, string>> sortTranslations;
    for (map<string, string>::iterator i = this->words.begin(); i != this->words.end(); ++i)
    {
        sortTranslations.push_back(make_pair(i->first, i->second));
    }
    sort(sortTranslations.begin(), sortTranslations.end(), compare);
    for (int i = 0; i < sortTranslations.size(); i++)
    {
        cout<<sortTranslations[i].first<<" -> "<<sortTranslations[i].second<<endl;
    }
}
}
