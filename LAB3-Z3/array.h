#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
using namespace std;
template <typename T>
class Array
{
private:
    int tabSize;
    int indexFreeTab;//Indeks ostatniego wolnego miejsca w tablicy
    T *tab;//Pole do przechowywania tablicy
public:
    Array(int tabSize1);
    Array();
    ~Array();
    T sortAscendigly();//Sortuj rosnaco
    T returnMaxfromTab();//Zwroc element maksymalny z tablicy
    void show_tab();
    void addTab(T value);//Dodaj element do tablicy
    T getTabIndex(int typedIndex);//Zwroc element tablicy o indeksie
};
#include "array.tpp"
#endif // ARRAY_H_INCLUDED
