#include <iostream>
#include <regex>
using namespace std;
bool isStreet (string str)
{
    return regex_match(str, regex("[A-Za-z ]+"));
}
bool isPostalCode (string str)
{
    return regex_match(str, regex("[0-9]{2}-[0-9]{3}"));
}
bool isHouseNumber (string str)
{
    return regex_match(str, regex("[1-9][0-9]*[A-Z]?"));
}
bool isflatNumber (string str)
{
    return regex_match(str, regex("[1-9][0-9]*"));
}
int main()
{
    cout<<isStreet("Jana Dlugosza")<<endl;
    cout<<isStreet("Jozefa-Pilsudskiego")<<endl;
    cout<<isPostalCode("24-300")<<endl;
    cout<<isPostalCode("2A-500")<<endl;
    cout<<isHouseNumber("32A")<<endl;
    cout<<isHouseNumber("**-BC")<<endl;
    cout<<isHouseNumber("14")<<endl;
    cout<<isflatNumber("50")<<endl;
    cout<<isflatNumber("3")<<endl;
    cout<<isflatNumber("AB32")<<endl;
    return 0;
}
