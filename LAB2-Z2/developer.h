#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED
#include "employee.h"
class Developer:public Employee
{
    public:
        Developer ();
        Developer(string surname1, int age1, int experience1, int salary1);
        float calculateBonus(int value);
};
#endif // DEVELOPER_H_INCLUDED
