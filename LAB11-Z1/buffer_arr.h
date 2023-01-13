#ifndef BUFFER_ARR_H
#define BUFFER_ARR_H
#include <iostream>
#include <memory>
#include "Buffer.h"
using namespace std;
class BufferArr : public Buffer {
    private:
        int *t;
        int s;
        int curr;
    public:
        BufferArr (int size)
        {
            this->s = size;
            this->t = new int[this->s];
            this->curr = 0;
            cout<<"Konstruktor klasy BufferArr"<<endl;
        }
        ~BufferArr ()
        {
            cout<<"Destruktor klasy BufferArr"<<endl;
            delete [] this->t;
        }
        int getSize () {return this->s;}
        void add (int a) override
        {
            if (curr < s) {
                this->t[this->curr] = a;
                curr++;
                return;
            }
            cout<<"Nie ma miejsca zeby dodac kolejne elementy!"<<endl;
        }
        void write () override {
            cout<<"[";
            for (int i = 0; i < this->curr; i++)
            {
                cout<<this->t[i];
                if (i < this->curr - 1)
                {
                cout<<",";
                }
            }
            cout<<"]"<<endl;
        }
};
#endif

