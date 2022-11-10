#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void show(set <int> secik )
{
    set <int> :: iterator itr;
    cout<<"{ ";
        for (itr = secik.begin(); itr != secik.end(); itr++)
        {
            cout<<*itr<<" ";
        }
    cout<<"}"<<endl;
}
void uniqueElements(set <int> s1, set <int> s2){
    set <int> sUnion, sIntersec, sUDiffer;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<set<int>>(sUnion, sUnion.begin()));//Sumujemy oba zbiory
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<set<int>>(sIntersec, sIntersec.begin()));//Liczymy czesc wspolna zbiorow
    set_difference(sUnion.begin(), sUnion.end(), sIntersec.begin(), sIntersec.end(), insert_iterator<set<int>>(sUDiffer, sUDiffer.begin()));//Od sumy zbiorow odjemujemy czesc wspolna zbiorow
    show(s1);
    show(s2);
    show(sUnion);//Suma zbiorow
    show(sIntersec);//Iloczyn zbiorow
    show(sUDiffer);//Suma - iloczyn (zbiorow)
}
int main()
{
    set <int> s1 = {3,4,8,11,13,16,18}; // 4,8,13,18 unikatowe
    set <int> s2 = {3,5,9,11,14,16,17,19}; //5,9,14,17,19 unikatowe
    uniqueElements(s1,s2);
    return 0;
}
