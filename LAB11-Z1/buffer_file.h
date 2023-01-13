#ifndef BUFFER_FILE_H
#define BUFFER_FILE_H
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include "Buffer.h"
using namespace std;
class BufferFile : public Buffer {
    private:
        string path;
    public:
        BufferFile (string file_path)
        {
            this->path = file_path;
            cout<<"Konstruktor klasy BufferFile"<<endl;
        }
        ~BufferFile ()
        {
            cout<<"Destruktor klasy BufferFile"<<endl;
        }
        void add (int a) override
        {
            fstream f;
            f.open(this->path, ios::app);
            f<<a<<endl;
            f.close();
        }
        void write () override
        {
            fstream f;
            string l;
            f.open(this->path, ios::in);
            while (getline(f, l)) {
                cout<<l<<endl;
            }
            f.close();
        }
};
#endif // BUFFER_FILE_H_INCLUDED
