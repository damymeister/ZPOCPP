#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED
#include <iostream>
#include "animal.h"
using namespace std;
class Cat : public Animal
{
    private:
      int levelOfMouseHunting;
      int mice [5];
    public:
       Cat(int limbNr1, string name1, bool protectedAnimal1);
       Cat();
       void initMice();
       void initCat(int levelOfMouseHunting1);
       void setLevelOfMouseHunting(int value);
       int getLevelOfMouseHunting();
       int getMice(int index);
       void giveVoice();
       void info();
};
#endif // CAT_H_INCLUDED
