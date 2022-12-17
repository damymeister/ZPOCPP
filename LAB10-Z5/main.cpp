#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Osoba {
    public:
        string name, surname, age, phone, email;
        Osoba(string imie, string nazw, string wiek, string tel, string email) : name(imie), surname(nazw), age(wiek), phone(tel), email(email) {}
        string getDomainName ()
        {
            int pos = this->email.find('@') + 1;
            return this->email.substr(pos);//zwraca nastepny po @
        }
        bool isLastPhoneDigitEven ()
        {
            return (int) (this->phone.at(8))  % 2 == 0;
        }
        bool isSurnameDouble ()
        {
            return (this->surname.find("-") != string::npos);//npos - brak pozycji (czyli nie znaleziono pozycji)
        }
};
void openFile (ifstream &p, string n = "../L10-Z4/dane.csv") {
    p.open(n);
    if (!p)
    {
        throw runtime_error("Could not open file!");
    }
    cout<<"Znaleziono: "<<n<<endl;
}
set<string> uniqueDomains (vector <Osoba> k)
{
    set<string> ud;
    vector<string> repeated;
    for (int i = 0; i < k.size(); i++)
        {
            if (ud.find(k[i].getDomainName()) != ud.end())
            {
                repeated.push_back(k[i].getDomainName());
            }
            else
            {
                ud.insert(k[i].getDomainName());
            }
        }
    for (int i = 0; i < repeated.size(); i++)
        {
            ud.erase(repeated[i]);
        }
    return ud;
}
map<string, int> mapNameCount (vector <Osoba> k) //Zlicza ilosc wystapien danego imienia
{
    map<string, int> names;
    for (unsigned i = 0; i < k.size(); i++)
        {
            ++names[k[i].name];
        }
    return names;
}
int main()
{
    string fname;
    ifstream p;
    vector <Osoba> k;
    cout<<"Podaj nazwe pliku [../L10-Z4/dane.csv]: ";
    getline(cin, fname);
    try {
        if (fname.length() != 0) openFile(p, fname);
        else
            {
            fname = "../L10-Z4/dane.csv";
            openFile(p);
            }
    }
    catch (exception &ex) {
        cout<<"Blad odczytu pliku!"<<endl;
        cin.ignore();
        cin.get();
        return 0;
    }
       string line, field;
    while (getline(p, line)) {
        if (!line.empty()) {
            stringstream str(line);
            string imie, nazwisko, wiek, tel, email;
            int i = 0;
            while (getline(str, field, ';')) {
                if (i == 0) imie = field;
                if (i == 1) nazwisko = field;
                if (i == 2) wiek = field;
                if (i == 3) tel = field;
                if (i == 4) email = field;
                i++;
            }
            k.push_back(Osoba(imie, nazwisko, wiek, tel, email));
        }
    }
    p.close();

    cout<<"Unikatowe domeny: ";
    set <string> ud = uniqueDomains(k);
    for (auto it = ud.cbegin(); it != ud.cend(); ++it)
    {
        cout<<*it<<", ";
    }
    cout<<endl;
    cout<<"Numery telefonow konczace sie cyfra parzysta: ";
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i].isLastPhoneDigitEven())
        {
            cout<<k[i].phone<<", ";
        }
    }
    cout<<endl;
    cout<<"Nazwiska laczone znakiem -: ";
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i].isSurnameDouble())
        {
            cout<<k[i].surname<<", ";
        }
    }
    cout<<endl;
    cout<<"Ilosc wystapien danego imienia:"<<endl;
    map <string, int> m = mapNameCount(k);
    for (map<string,int>::iterator i = m.begin(); i != m.end(); ++i)
    {
        cout<<i->first<<" - "<<i->second<<endl;
    }
    return 0;
}
