#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
tuple<int, double, string> stats (const vector<string> &Vec)
{
    double mean = 0.0;
    int lengthTheShortestString = (*min_element(Vec.begin(), Vec.end(), [] (string s1, string s2) { return s1.length() < s2.length(); })).length();

    for_each(Vec.begin(), Vec.end(), [&mean] (string s) { mean += (s.length() * 1.0); });
    mean = mean / (Vec.size() * 1.0);

    string longestString = *max_element(Vec.begin(), Vec.end(), [] (string s1, string s2) { return s1.length() < s2.length(); });
    return make_tuple(lengthTheShortestString, mean, longestString);
}
int main () {
    vector <string> S;
    S.push_back("Run");
    S.push_back("Running");
    S.push_back("Close");
    S.push_back("Closed");
    S.push_back("Nurmagomedov");
    S.push_back("Khabib");
    tuple<int, double, string> t = stats(S);
    cout<<"Dlugosc najkrotszego napisu: "<<get<0>(t)<<endl;
    cout<<"Srednia dlugosc napisu: "<<get<1>(t)<<endl;
    cout<<"Najdluzszy napis: "<<get<2>(t)<<endl;
    return 0;
}
