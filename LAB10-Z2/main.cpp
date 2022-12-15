#include <iostream>
#include <regex>
using namespace std;
bool dateFound(string str) {
    return regex_match(str, regex("([0-1][0-9]|[2][0-3]):[0-5][0-9](:[0-5][0-9])?"));
}
int main () {
    cout<<dateFound("21:54")<<endl;
    cout<<dateFound("22:53:23")<<endl;
    cout<<dateFound("01:51:21")<<endl;
    cout<<dateFound("12:61:23")<<endl;
    cout<<dateFound("3:23:54")<<endl;
    cin.ignore();
    cin.get();
    return 0;
}
