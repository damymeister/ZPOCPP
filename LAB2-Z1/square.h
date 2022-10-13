#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include "figure.h"
class Square: public Figure
{
    private:
        float a;
    public:
        Square(float a1);
        ~Square();
        virtual void calculateArea() override;//deklaracja metody wirtualnej
        virtual void show() override;

};
#endif // SQUARE_H_INCLUDED

