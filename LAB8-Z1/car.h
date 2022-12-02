#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car {
private:
    string marka, model, vin;
    int year;
public:
    Car (string marka1, string model1, string vin1, int year1) : marka(marka1), model(model1), vin(vin1), year(year1) {}
    void show ()
    {
        cout<<this->marka<<" "<<this->model<<" "<<this->year<<", VIN: "<<this->vin<<endl;
    }
    string getMarka() const;
    string getVin() const;
    int getYear() const;
};

inline string Car::getMarka() const
{
    return marka;
}

inline string Car::getVin() const
{
    return vin;
}

inline int Car::getYear() const
{
    return year;
}

#endif // CAR_H
