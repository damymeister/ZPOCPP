#ifndef CONTACTS_H_INCLUDED
#define CONTACTS_H_INCLUDED
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>
#include <set>
#include "contact.h"
using namespace boost::multi_index;
using namespace std;
typedef multi_index_container <Contact, indexed_by<//Kontener przechowuje obiekty klasy Contact
hashed_non_unique<member<Contact, string, &Contact::imie>>,//Imie z klasy Contact
hashed_non_unique<member<Contact, string, &Contact::nazwisko>>,//Nazwisko z klasy contact
hashed_non_unique<member<Contact, int, &Contact::wiek>>,//Wiek z klasy contact
hashed_unique<member<Contact, string, &Contact::tel>>,//Telefon z klasy kontakt
hashed_non_unique<member<Contact, string, &Contact::ulica>>//Ulica z klasy kontakt
>> ksiazka;
typedef ksiazka::nth_index<3>::type tel_type;//Stworzenie typu dla interfejsu telefon
typedef ksiazka::nth_index<4>::type ulica_type;//Stworzenie typu dla interfejsu ulica
typedef ksiazka::nth_index<2>::type wiek_type;//Stworzenie typu dla interfejsu wiek
typedef ksiazka::nth_index<1>::type nazwisko_type;//Stworzenie typu dla interfejsu nazwisko
void newStreetName (Contact& x, string staranazwa, string nowanazwa) {
    if (x.ulica == staranazwa)
    {
        x.ulica = nowanazwa;
    }
}
class Contacts{
public:
    ksiazka Ksiazka; //Tworzymy kontener Ksiazka
    void addNewContact(string imie, string nazwisko, int wiek, string tel, string ulica)
    {
         if (Ksiazka.get<3>().count(tel) == 0) {//Sprawdzamy czy telefon znajduje sie w kontenerze, jesli nie, dodajemy go
                Ksiazka.insert({imie, nazwisko, wiek, tel, ulica});
            }
    }
    void usun(string tel)//Usuwanie z ksiazki tel os o podanym numerze tel
    {
          tel_type &tel_index = Ksiazka.get<3>();//Zapisanie do zmiennej interfejsu telefon
          auto del = tel_index.find(tel);//Auto sprawia ze dobiera nam typ automatycznie
          tel_index.erase(del);
    }
    void findByStreet(string ulica) { //Funkcja znajduje po ulicy
            for (ulica_type::iterator it = Ksiazka.get<4>().begin(); it != Ksiazka.get<4>().end(); ++it)
                {
                    if (it->ulica == ulica)
                    {
                           cout<<it->imie<<" "<<it->nazwisko<<" Wiek: "<<it->wiek<<", Telefon: "<<it->tel<<", Ulica: "<<it->ulica<<endl;
                    }
                }
        }
     void findByRange(int dol, int gora) {//Znajduje po przedziale wiekowym
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                if (it->wiek >= dol && it->wiek <= gora) {
                    cout<<it->imie<<" "<<it->nazwisko<<" Wiek: "<<it->wiek<<", Telefon: "<<it->tel<<", Ulica: "<<it->ulica<<endl;
                }
            }
        }
     void findByPhone(string tel) {
            tel_type &tel_index = Ksiazka.get<3>();//Zapisanie do zmiennej interfejsu telefon
            auto it = tel_index.find(tel);//Auto sprawia ze dobiera nam typ automatycznie
            cout<<it->imie<<" "<<it->nazwisko<<" Wiek: "<<it->wiek<<", Telefon: "<<it->tel<<", Ulica: "<<it->ulica<<endl;
        }
     void changeStreetName(string staranazwa, string nowanazwa) {
            vector<ulica_type::iterator> v1;
            auto &ulica_index = Ksiazka.get<4>();
            for (ulica_type::iterator it = Ksiazka.get<4>().begin(); it != Ksiazka.get<4>().end(); ++it)
            {
                v1.push_back(it);
            }
            for (int i = 0; i < v1.size(); i++)
            {
                ulica_index.modify(v1[i], boost::bind(newStreetName, _1, staranazwa, nowanazwa));//funkcja bind daje mozliwosc zastepowania argumentow
            }
        }
      int howManyAdults () {
            int ile = 0;
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                if (it->wiek >= 18)
                {
                    ile++;
                }
            }
            return ile;
        }
       int howManyUniqueSurnames(){
            set <string> kontener;//Bedzie zawieral unikalne nazwiska
            int ile = 0;
            for (nazwisko_type::iterator it = Ksiazka.get<1>().begin(); it != Ksiazka.get<1>().end(); ++it) {
                if (kontener.find(it->nazwisko) == kontener.end()) {//Jezeli nie ma nazwiska kontenerze
                    kontener.insert(it->nazwisko);
                    ile++;
                }
                else ile--;
            }
            return ile;
        }
        void show() {
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                cout<<it->imie<<" "<<it->nazwisko<<" Wiek: "<<it->wiek<<", Telefon: "<<it->tel<<", Ulica: "<<it->ulica<<endl;
            }
        }
};
#endif // CONTACTS_H_INCLUDED
