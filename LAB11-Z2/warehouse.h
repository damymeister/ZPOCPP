#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>
using namespace std;
class Warehouse {
    private:
        string name;
        unsigned count;
    public:
        Warehouse(const string& productName, unsigned productCount) : name(productName), count(productCount) {}
        ~Warehouse () { cout<<"Destruktor klasy Warehouse"<<endl; }
        inline string getName () {return this->name;}
        inline unsigned getCount () {return this->count;}
        inline void setName (const string& productName) {this->name = productName;}
        inline void setCount (unsigned productCount) {this->count = productCount;}
        void show () { cout<<this->name<<"-  Ilosc: "<<this->count<<endl; }
};
#endif // !WAREHOUSE_H
