#include <fstream>
#include <string>
#include <iostream>
using namespace std;
void openFile (ifstream &plik, string n) {
    plik.open(n);
    if (!plik)
    {
        throw runtime_error("Could not open file!");
    }
}
int CommentIndex (string line) {
    for (int i = 1; i < line.length(); i++) {
        if (line.at(i) == '/' && line.at(i-1) == '/')
        {
        return (i-1);
        }
    }
    return -1;
}
bool IsEmpty (string line, int c_index) {
    for (int i = 0; i < c_index; i++) {
        if (line.at(i) > 32) {
            return false;
        }
    }
    return true;
}
void showPart (string line, int c_index) {
    if (IsEmpty(line, c_index))
    {
        return;
    }
    for (int i = 0; i < c_index; i++) {
        cout<<line.at(i);
    }
    cout<<endl;
}
int main()
{
ifstream plik;
    try {
        openFile(plik, "tekstowy.txt");
    }
    catch (exception &ex) {
        cout<<"Nie udalo sie wczytac pliku!"<<endl;
        cin.ignore();
        cin.get();
        return 0;
    }
     string line;
    while (getline(plik, line)) {
        if (CommentIndex(line) == -1)
        {
            cout<<line<<endl;
        }
        else
        {
            showPart(line, CommentIndex(line));
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}
