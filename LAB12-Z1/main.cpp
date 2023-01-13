#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void show (const vector <int> &Vec) {
    for_each(Vec.begin(), Vec.end(), [] (int el) -> void { cout<<el<<"|"; });
    cout<<endl;
}
double mean(const vector <int> &Vec){
    double suma = 0.0;
    for_each(Vec.begin(), Vec.end(), [&suma] (int el) { suma = suma + (el * 1.0); });
    return suma / (Vec.size() *  1.0);
}
int howmanyEven(const vector <int> &Vec)
{
    int ile = 0;
    for_each(Vec.begin(), Vec.end(), [&ile] (int el) -> void {if(el % 2 == 0) ile = ile + 1;});
    return ile;
}
void removeNegative (vector <int> &Vec) {
    Vec.erase(remove_if(Vec.begin(), Vec.end(), [] (int el) { return el < 0; }), Vec.end());
}
void sortby(vector <int> &Vec) {
    sort(Vec.begin(), Vec.end(), [] (int el, int el2) { return (el % 2 < el2 % 2); });
}
void replaceWithOpposite (vector <int> &Vec) {
    transform(Vec.begin(), Vec.end(), Vec.begin(), [] (int el) { return -el; });
}
int count(const vector <int> &Vec, int val)
{
      return count_if(Vec.begin(), Vec.end(), [val] (int el) { return (el < val); });
}
int main()
{
    vector <int> A = {5, 3, 1, -6, -2, 0, 9};
    show(A);
    cout<<"Srednia jest rowna: ";
    cout<<mean(A)<<endl;
    cout<<"Jak duzo parzystych: ";
    cout<<howmanyEven(A)<<endl;
    cout<<"Po usunieciu ujemnych: ";
    removeNegative(A);
    show(A);
    sortby(A);
    cout<<"Parzyste, nieparzyste: ";
    show(A);
    replaceWithOpposite(A);
    cout<<"Po nadpisaniu kazdego elementu liczba przeciwna: ";
    show(A);
    cout<<"Ile liczb mniejszych od zera: "<<count(A,0);
    return 0;
}
