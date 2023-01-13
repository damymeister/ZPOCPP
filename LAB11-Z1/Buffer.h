#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
using namespace std;
class Buffer {
    public:
        virtual void add (int a) = 0;
        virtual void write () = 0;
        Buffer () { cout<<"Konstruktor klasy Buffer"<<endl;}
        ~Buffer () { cout<<"Destruktor klasy Buffer"<<endl;}
};
#endif
