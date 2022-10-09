#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
using namespace std;
class Animal
{
    private:
        int limbNr;
        string name;
        bool protectedAnimal;
    public:
        Animal();
        Animal(int limbNr1, string name1, bool protectedAnimal1);
        void setLimbNr(int NewLimbNr);
        void setName(string NewName);
        void setProtectedAnimal(bool NewProtectedAnimal);
        int getLimbNr();
        string getName();
        bool getProtectedAnimal();
        void giveVoice();
        void info();
};
#endif // ANIMAL_H_INCLUDED
