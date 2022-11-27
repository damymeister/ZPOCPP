#ifndef MEANBUFOR_H_INCLUDED
#define MEANBUFOR_H_INCLUDED
#include "bufor.h"
class MeanBufor : public Bufor
{
    public:
     MeanBufor(int n1);
     double calculate();
};
#endif // MEANBUFOR_H_INCLUDED
