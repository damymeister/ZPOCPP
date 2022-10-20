#include <iostream>
template <typename T>
Array<T>::Array(int tabSize1)
{
    this->tabSize=tabSize1;
    this->tab = new T[tabSize];
    this->indexFreeTab = 0;
    cout<<"Konstruktor z podaniem rozmiaru"<<endl;
}
template <typename T>
Array<T>::Array()
{
    this->tabSize=10;
    this->tab = new T[tabSize];
    this->indexFreeTab = 0;
    cout<<"Konstruktor bez podania bezwzglednego rozmiaru"<<endl;
}
template <typename T>
Array<T>::~Array()
{
    delete [] this->tab;
    delete this;
}
template <typename T>
T Array<T>::sortAscendigly()
{
    for(int i= 0; i < this->indexFreeTab; i++)
    {
        for(int j = i+1; j < this->indexFreeTab;j++)
        {
            if(this->tab[i] > this->tab[j])
            {
                swap(this->tab[i], this->tab[j]);
            }
        }
    }
}
template <typename T>
T Array<T>::returnMaxfromTab()
{
    T tab_max = this->tab[0];
    for(int i=1; i < this->indexFreeTab; i++)
    {
        if(this->tab[i]>tab_max)
        {
            tab_max = this->tab[i];
        }
    }
    return tab_max;
}
template <typename T>
void Array<T>::show_tab()
{
    cout<<"Wyswietlam tablice: "<<endl;
    cout<<"[";
    for(int i=0; i < this->indexFreeTab; i++)
    {
        cout<<" "<<this->tab[i];
        if (i < this->indexFreeTab-1)
        {
            cout<<" , ";
        }
    }
    cout<<" ]"<<endl;
}
template <typename T>
void Array<T>::addTab(T value)
{
    if(this->indexFreeTab>=this->tabSize)
    {
        cout<<"Tablica jest pelna!"<<endl;
    }
    else
    {
        this->tab[indexFreeTab] = value;
        this->indexFreeTab ++;
    }
}
template <typename T>
T Array<T>::getTabIndex(int typedIndex)
{
   if(typedIndex>=this->indexFreeTab)
   {
       cout<<"Wprowadziles/as zly indeks!"<<endl;
   }
   else
   {
       return this->tab[typedIndex];
   }
}
//SPECJALIZACJA DLA TYPU STRING
template <>//Pusto bo nie potrzebujemy T
string Array <string>::returnMaxfromTab()
{
   string tab_max = this->tab[0];
    for(int i=1; i < this->indexFreeTab; i++)
    {
        if(this->tab[i].length()>tab_max.length())
        {
            tab_max = this->tab[i];
        }
    }
    return tab_max;
}
template <>//Pusto bo nie potrzebujemy T
string Array <string>::sortAscendigly()
{
   for(int i= 0; i < this->indexFreeTab; i++)
    {
        for(int j = i+1; j < this->indexFreeTab;j++)
        {
            if(this->tab[i].length() > this->tab[j].length())
            {
                swap(this->tab[i], this->tab[j]);
            }
        }
    }
}
