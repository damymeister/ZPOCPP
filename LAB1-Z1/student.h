#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include "person.h"
using namespace std;
class Student : public Person
{
    private:
        string index;
    public:
        Student(string index1, string name1, string surname1, int age1);
        Student();
        void setIndex(string index1);
        string getIndex();
        void showInfoStudent();
};
#endif // STUDENT_H_INCLUDED
