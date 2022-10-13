#ifndef TEAMLEADER_H_INCLUDED
#define TEAMLEADER_H_INCLUDED
#include "employee.h"
class Teamleader:public Employee
{
    public:
        Teamleader();
        Teamleader(string surname1, int age1, int experience1, int salary1);
        float calculateBonus(int value);
        void show() override ;
};
#endif // TEAMLEADER_H_INCLUDED
