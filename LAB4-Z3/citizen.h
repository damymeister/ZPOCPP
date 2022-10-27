#ifndef CITIZEN_H_INCLUDED
#define CITIZEN_H_INCLUDED
using namespace std;
class Citizen
{
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;
public:
    Citizen();
    Citizen(string name1, string surname1, int age1, char sex1, string postal_code1);
    void show();
    string getName();
    string getSurname();
    int getAge();
    char getSex();
    string getPostal_Code();
};
#endif // CITIZEN_H_INCLUDED
