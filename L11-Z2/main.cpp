#include <iostream>
#include <vector>
#include <memory>
#include "warehouse.h"
#include "shop.h"
using namespace std;
int main () {
    vector <shared_ptr<Warehouse>> Magazyny;
    vector <unique_ptr<Shop>> Sklepy;
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Laptop Lenovo", 5)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Laptop Asus", 3)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Laptop Acer", 4)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Laptop Dell", 3)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("MacBook", 5)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Laptop Samsung", 4)));
    for (int i = 0; i < 4; i++)
    {
        string sname = "Sklep ";
        sname += (char) (i + 49);
        Sklepy.push_back(unique_ptr<Shop>(new Shop(sname)));
        for (int j = i; j < i + 3; j++) Sklepy[i]->addWarehouse(Magazyny[j]);
        Sklepy[i]->show();
        Sklepy[i]->showWarehouses();
    }
    Sklepy[0]->sellProduct("Laptop Acer", 2);
    Sklepy[0]->showWarehouses();
    Sklepy[1]->sellProduct("Laptop Acer", 3); // Brak produktow
    Sklepy[0]->sellProduct("Laptop Acer", 2); // Brak produktow
    return 0;
}
