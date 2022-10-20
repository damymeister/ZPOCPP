#include <iostream>
#include "Adding.h"
#include "student.h"
using namespace std;
template <typename T>
void showAll(T* tab[], int n)
{
 for(int i=0;i<n;i++)
 tab[i]->show();
}
int main()
{
Adding<int> a1(5);
a1.add(6);
a1.show();
Adding<string> a2("Pro");
a2.add("gramowanie");
a2.show();
Student<float> s(5,"Ala");
s.showMark();
Student<int> s1(5,"Ala");
s1.showMark();
Student<string> s2(5,"Ala");
s2.showMark();
Adding<int>* arrAdd[3];
for(int i=0;i<3;i++)
{
    arrAdd[i]=new Adding<int>(i);
}
showAll(arrAdd,3);
Student<string>* arrStu[2];
for(int i=0;i<3;i++)
 {
    arrStu[i]=new Student<string>(i+2,"Ala");
 }
showAll(arrStu,3);
for(int i=0; i<3; i++)
    delete arrAdd[i];
for(int i=0; i<2; i++)
    delete arrStu[i];
return 0;
}
