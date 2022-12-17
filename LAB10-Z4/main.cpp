#include <iostream>
#include <regex>
#include <fstream>
using namespace std;
bool isName (string str)
{
    return regex_match(str, regex("[A-Z][a-z]+"));
}
bool isSurname (string str)
{
    return regex_match(str, regex("[A-Z][a-z]+(-[A-Z][a-z]+)?"));
}
bool isAge (string str)
{
    return regex_match(str, regex("([0]|[1-9][0-9]?)"));
}
bool isPhone (string str)
{
    return regex_match(str, regex("[1-9][0-9]{8}"));
}
bool isEmail (string str)
{
    return regex_match(str, regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"));
}
int main()
{
    string name, surname, age, phone, email;
    do {
        cout<<"Podaj imie: ";
        cin>>name;
    } while (!isName(name));
    do {
        cout<<"Podaj nazwisko: ";
        cin>>surname;
    } while (!isSurname(surname));
    do {
        cout<<"Podaj wiek (0 - 99): ";
        cin>>age;
    } while (!isAge(age));
    do {
        cout<<"Podaj nr telefonu: ";
        cin>>phone;
    } while (!isPhone(phone));
    do {
        cout<<"Podaj email: ";
        cin>>email;
    } while (!isEmail(email));
    cout<<"Wprowadzone dane sa poprawne !"<<endl;
    string file;
    cout<<"Podaj nazwe pliku do ktorego chcesz zapisac dane: ";
    cin>>file;
    fstream f;
    f.open(file, ios::app);
    f<<name<<";"<<surname<<";"<<age<<";"<<phone<<";"<<email<<endl;
    f.close();
    cout<<"Zapisano!"<<endl;
    return 0;
}
