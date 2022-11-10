#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED
#include <iostream>
#include <map>
using namespace std;
class Dictionary
{
    private:
        map <string, string> words; //Kontener przechowujacy slowo oraz jego tlumaczenie
        string toLower(string znaki);
        static bool compare(pair <string, string> translation1 , pair <string, string> translation2);
    public:
        Dictionary();//Konstruktor bezargumentowy klasy dictionary
        void addWordAndTranslate(string word, string translation);
        void deleteWordAndTranslate(string word);
        void showDictionary();
        void showTranslationSpecifiedWord(string word);//Pokaz tlumaczenie podanego slowa
        void showDictionaryAlphabetically();//Pokaz slownik alfabetycznie od z do a wzgledem tlumaczenia
};
#endif // DICTIONARY_H_INCLUDED
