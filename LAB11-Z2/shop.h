#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <vector>
#include <memory>
#include "warehouse.h"
using namespace std;
class Shop {
    private:
        string name;
        vector <shared_ptr<Warehouse>> warehouses;
    public:
        Shop (const string& shopName) : name(shopName) {}

        ~Shop ()
        {
            cout<<"Destruktor klasy Shop"<<endl;
            for (unsigned i = 0; i < this->warehouses.size(); i++)
            {
                this->warehouses[i].reset();
            }
            warehouses.clear();
        }

        void addWarehouse (shared_ptr<Warehouse> w) { this->warehouses.push_back(w); }

        void sellProduct (const string &productName, unsigned productCount)
        {
            for (unsigned i = 0; i < this->warehouses.size(); i++)
                {
                    unsigned wcount = this->warehouses[i]->getCount();
                    if (productName == this->warehouses[i]->getName() && productCount <= wcount)
                    {
                        this->warehouses[i]->setCount(wcount - productCount);
                        cout<<"Sprzedano "<<productCount<<"x "<<productName<<" (Pozostalo: "<<this->warehouses[i]->getCount()<<")"<<endl;
                        return;
                    }
                }
            cout<<"Nie znaleziono produktu "<<productCount<<"x "<<productName<<endl;
        }
        void showWarehouses ()
        {
            for (unsigned i = 0; i < this->warehouses.size(); i++) this->warehouses[i]->show();
        }
        void show ()
        {
            cout<<name<<endl;
        }
};
#endif // !SHOP_H
