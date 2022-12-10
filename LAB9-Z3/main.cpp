#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
class Student{
     public:
    string imie;
    string nazwisko;
    string email;
    char plec;
    float ocena;
    Student(string imie1, string nazwisko1, char plec1, float ocena1, string email1) : imie(imie1) , nazwisko(nazwisko1), plec(plec1), ocena(ocena1), email(email1) {}
      void show () {
            cout<<left<<setw(20)<<setfill('_')<<this->imie;
            cout<<left<<setw(20)<<setfill('_')<<this->nazwisko;
            cout<<left<<setw(8)<<setfill('_')<<this->plec;
            cout<<left<<setw(9)<<setfill('_')<<fixed<<setprecision(1)<<this->ocena;
            cout<<left<<setw(20)<<setfill('_')<<this->email<<endl;
        }
};
void openFile (ifstream &p, string n = "plik.csv") {
    p.open(n);
    if (!p){
        throw runtime_error("Nie mozna otworzyc pliku!");
    }
    cout<<"Znaleziono: "<<n<<endl;
}
bool checkName (string n) {
    if (n.length() < 1)
    {
        return false;//Imie musi byc dlusze od 1 wyrazu
    }
    if (n.at(0) < 65 || n.at(0) > 90)
    {
        return false;
    }//Pierwsza litera imienia musi byc duza
    for (int i = 1; i < n.length(); i++) {
        if (n.at(i) < 97 || n.at(i) > 122)
        {
            return false;//imie musi zawierac male litery z wyjatkiem pierwszej
        }
    }
    return true;
}
bool checkSex (char s) {
    return (s == 'K' || s == 'M');
}
bool checkMark (float o) {
    return (o >= 2.0 && o <= 5.0);
}
bool checkEmail (string e) {
    if (e.length() == 0)
    {
        return true;//email nie moze miec 0 znakiw
    }
    for (int i = 0; i < e.length(); i++)
        {
        if (e.at(i) == '@') //Jezeli znajdzie malpe to ok jak nie to nie ok
        {
            return true;
        }
    }
    return false;
}
void showHeaders () {
    cout<<left<<setw(20)<<"[Imie]";
    cout<<left<<setw(20)<<"[Nazwisko]";
    cout<<left<<setw(8)<<"[Plec]";
    cout<<left<<setw(9)<<"[Ocena]";
    cout<<left<<setw(20)<<"(E-mail)"<<endl;
}
bool markCompare (Student s1, Student s2) {
    return s1.ocena < s2.ocena;
}
int main()
{
    vector <Student> k;
    ifstream p;
    string fileLine = "";
    int line_count = 0;
    cout<<"Podaj nazwe pliku z danymi: ";
    getline(cin, fileLine);
    try {
        if (fileLine.length() != 0)
        {
            openFile(p, fileLine);
        }
        else {
            fileLine = "plik.csv";
            openFile(p);
        }
    }
    catch (exception &ex) {
        cout<<"Nastapil blad w odczycie!"<<endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    string line, field;
    getline(p, line); // Pierwsza linia - naglowki
    while (getline(p, line)) {
        stringstream str(line);
        string imie, nazwisko, email = "";
        char plec;
        float ocena;
        int i = 0;
        while (getline(str, field, ';')) {
            if (i == 0) imie = field;
            if (i == 1) nazwisko = field;
            if (i == 2) plec = field.at(0);
            if (i == 3) ocena = stof(field);//Stof konwertuje stringa na floata
            if (i == 4) email = field;
            i++;
        }
        k.push_back(Student(imie, nazwisko, plec, ocena, email));
        line_count++;
    }
        p.close();
        cout<<"Ilosc wczytanych wierszy: "<<line_count<<endl;
          bool end = false;
          int opcja = 1;
    while (!end) {
        do {
            if (!cin) {
                cout<<"Nieprawidlowa opcja!"<<endl;
                cin.clear();
                cin.ignore();
            }
            cout<<"Podaj opcje (1~7): ";
            cin>>opcja;
        } while (!cin);
        switch (opcja) {
            case 1: {
                cout<<"Znalezionych wierszy: "<<k.size()<<endl;
                showHeaders();
                for (int i = 0; i < k.size(); i++)
                {
                    k[i].show();
                }
                break;
            }
                  case 2: {
                string imie;
                do {
                    cout<<"Podaj imie: ";
                    cin>>imie;
                    if (!checkName(imie)) {
                        cin.clear();
                        cout<<"Nieprawidlowe imie!"<<endl;
                    }
                } while (!checkName(imie));
                string nazwisko;
                do {
                    cout<<"Podaj nazwisko: ";
                    cin>>nazwisko;
                    if (!checkName(nazwisko)) {
                        cin.clear();
                        cout<<"Nieprawidlowe nazwisko!"<<endl;
                    }
                } while (!checkName(nazwisko));
                char plec;
                do {
                    cout<<"Podaj plec (K/M): ";
                    cin>>plec;
                    if (!checkSex(plec) || !cin) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowa plec!"<<endl;
                    }
                } while (!checkSex(plec) || !cin);
                float ocena;
                do {
                    cout<<"Podaj ocene (2.0 ~ 5.0): ";
                    cin>>ocena;
                    if (!checkMark(ocena) || !cin) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowa ocena!"<<endl;
                    }
                } while (!checkMark(ocena) || !cin);
                string email;
                do {
                    cin.ignore();
                    cout<<"Podaj E-mail [opcjonalny]: ";
                    getline(cin, email);
                    if (email.length() == 0) email = "";
                    if (!checkEmail(email)) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowy email!"<<endl;
                    }
                } while (!checkEmail(email));
                k.push_back(Student(imie, nazwisko, plec, ocena, email));
                fstream zapis;
                zapis.open(fileLine, ios::app);
                zapis<<endl<<imie<<";"<<nazwisko<<";"<<plec<<";"<<fixed<<setprecision(1)<<ocena<<";"<<email;
                zapis.close();
                cout<<"Zapisano"<<endl;
                break;
            }
            case 3: {
                string nazwisko;
                do {
                    cout<<"Podaj nazwisko: ";
                    cin>>nazwisko;
                    if (!checkName(nazwisko)) {
                        cin.clear();
                        cout<<"Nie ma takiego nazwiska w bazie!"<<endl;
                    }
                } while (!checkName(nazwisko));
                showHeaders();
                for (int i = 0; i < k.size(); i++)
                    {
                    if (k[i].nazwisko == nazwisko)
                    {
                        k[i].show();
                    }
                }
                break;
            }
            case 4: {
                fstream zapis;
                zapis.open("k.csv", ios::out);
                zapis<<"imie;nazwisko;plec;ocena;email";
                for (int i = 0; i < k.size(); i++) {
                    if (k[i].plec == 'K')
                    {
                        zapis<<endl<<k[i].imie<<";"<<k[i].nazwisko<<";"<<k[i].plec<<";"<<fixed<<setprecision(1)<<k[i].ocena<<";"<<k[i].email;
                    }
                }
                zapis.close();
                zapis.open("m.csv", ios::out);
                zapis<<"imie;nazwisko;plec;ocena;email";
                for (int i = 0; i < k.size(); i++) {
                    if (k[i].plec == 'M')
                    {
                        zapis<<endl<<k[i].imie<<";"<<k[i].nazwisko<<";"<<k[i].plec<<";"<<fixed<<setprecision(1)<<k[i].ocena<<";"<<k[i].email;
                    }
                }
                zapis.close();
                cout<<"Zapisano kobiety do pliku k.csv, a mezczyzn do m.csv"<<endl;
                break;
            }
            case 5: {
                unsigned ile;
                do {
                    cout<<"Podaj liczbe wierszy: ";
                    cin>>ile;
                    if (!cin || ile > k.size()) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Liczba jest wieksza niz ilosc wierszy!!"<<endl;
                    }
                } while (!cin || ile > k.size());
                showHeaders();
                for (int i = 0; i < ile; i++)
                {
                    k[i].show();
                }
                break;
            }
            case 6: {
                sort(k.begin(), k.end(), markCompare);
                cout<<"Posortowano studentow wzgledem oceny ROSNACO"<<endl;
                break;
            }
            case 7: {
                cout<<"It's Over"<<endl;
                end = true;
                break;
            }
            default: {cout<<"Wprowadz poprawna opcje!"<<endl; break;}
        }
    }
    return 0;
}
