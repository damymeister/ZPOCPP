#include <QCoreApplication>
#include <QSet>
#include <iostream>
using namespace std;
void czyJestPangramem (string text)//Pangram zawiera wszystkie elementy alfabetu
{
    int len = text.length();
    QSet<char> s;//Set zawiera tylko niepowtarzajace sie elementy
    for (int i = 0; i < len; i++)
    {
        if (text.at(i) >= 65 && text.at(i) <= 90)
        {
            s.insert((char) (text.at(i) + 32));
        }
        if (text.at(i) >= 97 && text.at(i) <= 122)
        {
            s.insert(text.at(i));
        }
    }
    if (s.count() == 26)
    {
        cout<<"Wyraz jest Pangramem!"<<endl;
    }
    else
    {
    cout<<"Wyraz nie jest Pangramem!"<<endl;
    }
}
int main(int argc, char *argv[])
{
    czyJestPangramem("The quick brown fox jumps over the lazy dog");
    czyJestPangramem("czyjestempangramem");
}
