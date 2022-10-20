#include <iostream>
using namespace std;
template <typename T>
T returnMin(T* tab, int n)
{
    T minn=tab[0];
    for(int i=1;i<n;i++)
    {
        if(tab[i]<minn)
        {
            tab[i]=minn;
        }
    }
    return minn;
}
int main()
{
    int tab[5]={3,5,6,2,1};
   cout<<returnMin(tab,5)<<endl;
    return 0;
}
