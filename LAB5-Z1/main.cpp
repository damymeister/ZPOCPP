#include <iostream>
#include <vector>
#include <set>
using namespace std;
pair <int,int> returnSumAndDuplicate(vector <int> v);
int main()
{
vector <int> v ={1,3,4,5,7,7,9};
    cout<<"Wartosc zduplikowana: "<<returnSumAndDuplicate(v).first<<endl;
    cout<<"Suma unikatowych elementow "<<returnSumAndDuplicate(v).second<<endl;
    return 0;
}
pair <int,int> returnSumAndDuplicate(vector <int> v)
{
    set <int> s;
    int suma = 0;
    int znaleziony = 0;
    for(int i = 0; i< v.size();i++ )
        if(s.count(v[i]))
    {
        znaleziony = v[i];
        suma -=  znaleziony;
    }
    else
    {
        s.insert(v[i]);
        suma += v[i];
    }
    return {znaleziony,suma};
}
