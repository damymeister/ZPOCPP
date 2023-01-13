#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car {
    private:
        string model;
        int rok;
        float pojemnosc;
    public:
        Car (const string &m, int r, float p) : model(m), rok(r), pojemnosc(p) {}
        string getModel () { return model; }
        int getRok () { return rok; }
        float getPojemnosc () { return pojemnosc; }
        void setModel (const string &m) { this->model = m; }
        void setRok (unsigned r) { this->rok = r; }
        void setPojemnosc (float p) { this->pojemnosc = p; }
        void show () { cout<<model<<" - "<<rok<<" - "<<pojemnosc<<endl; }
};
#endif // !CAR_H
