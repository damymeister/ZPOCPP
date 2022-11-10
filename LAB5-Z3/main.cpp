#include <iostream>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
char findAddedChar(string s1, string s2)
{
    map  <char, int> map1, map2;//Map1 zawiera string1 rozbity na pojedyncze znaki
    for (int i = 0; i < s1.length(); i++)
        {
            ++map1[s1.at(i)];// w - 0 ; y -1, r - 2, a - 3 , z - 4
        }
    for (int i = 0; i < s2.length(); i++)//Map 2 zawiera string2 rozbity na pojedncze znaki
        {
            ++map2[s2.at(i)];// r - 0 , y  - 1, w - 2 , z - 3, a - 5 , n - 6
        }
    map<char, int>::iterator i; //Tworzymy iterator do przeszukania map2
    for(i=map2.begin(); i!=map2.end(); ++i)
        {
            char key = i->first;//Klucz
            int value = i->second;//Wartosc
            if (key != map1.find(key)->first || value != map1.find(key)->second)
                {
                    return key;
                }
        }
        return 0;
}
int main()
{
    string s1 = "wyraz";
    string s2 = "rywzan"; //n - dodatkowy znak
    char addedChar = findAddedChar(s1,s2);
    cout<<"Znak ktorego nie ma w pierwszym ciagu to: "<<addedChar<<endl;
    return 0;
}
