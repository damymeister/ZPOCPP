#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED
#include "citizen.h"
#include <vector>
class City
{
private:
    string city_name;
    vector <Citizen> citizens;

public:
    City(string city_name1);
    void addCitizen(Citizen newcitizen);
    void deleteCitizen(string surname, int age);
    void show_citizens();
    void show_city();
    int women();
    int city_citizens();
    int adults();
    int postal_codes(int czydrukuj);
};
#endif // CITY_H_INCLUDED
