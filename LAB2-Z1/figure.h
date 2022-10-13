#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
class Figure
 {
     private:
         float area;
         float obw;
    public:
         Figure();
         virtual ~Figure(); //wirtualny destruktor
         float getArea();
         void setArea(float area1);
         float getObw();
         void setObw(float area1);
         virtual void calculateArea()=0;//definicja metody CZYSTO WIRTUALNEJ
         virtual void show();
 };
 #endif // FIGURE_H_INCLUDED

