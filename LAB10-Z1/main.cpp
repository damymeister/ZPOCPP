#include <iostream>
#include <regex>
using namespace std;
bool Pattern(string s)
{
    return regex_match(s, regex("(\\+|\\-)[0-9]+[\\.][0-9]+"));
}
int main()
{
    cout<<Pattern("+1.543")<<endl;
    cout<<Pattern("+5.332")<<endl;
    cout<<Pattern("-1.2321")<<endl;
    cout<<Pattern("-3.543")<<endl;
    cout<<Pattern(".543")<<endl;
    return 0;
}
