#ifndef MAXBUFOR_H_INCLUDED
#define MAXBUFOR_H_INCLUDED
#include "bufor.h"
class MaxBufor : public Bufor
{
    public:
        MaxBufor(int n1);
        double calculate();
        void add(int value);
};
#endif // MAXBUFOR_H_INCLUDED
