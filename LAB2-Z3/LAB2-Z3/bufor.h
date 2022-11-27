#ifndef BUFOR_H_INCLUDED
#define BUFOR_H_INCLUDED
class Bufor
{
    private:
        int *tab;//Wskaznik reprezentujacy dynamiczna tablice liczb calkowitych
        int n; //Rozmiar tablicy
        int index;//Indeks pierwszego wolnego miejsca w tablicy
    public:
        Bufor();
        Bufor(int n1);
        virtual ~Bufor();
        virtual void add(int value);
        virtual double calculate()=0;//Metoda czysto wirtualna
        int getIndex();//Zwraca indeks pierwszego wolengo miejsca tablicy
        int getSize();//Zwraca rozmiar tablicy
        int getTab(int i);//Zwraca i-ty element tablicy
        int getFirst();//Zwraca pierwszy dostepny indeks
        void setFirst(int value);
        void setTab(int pos, int value);
        void print();//Wyswietla zawartosc tablicy
};
#endif // BUFOR_H_INCLUDED
