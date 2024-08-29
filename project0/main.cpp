#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
11111111
using namespace std;
string convTen2Two(unsigned int baseTenValue){
    string basetwo;
    if (baseTenValue == 0) {
        return "0";
    }

    while(baseTenValue > 0){
        basetwo.push_back(baseTenValue % 2);
        baseTenValue /= 2;
    }
    reverse(basetwo.begin(), basetwo.end()); 
    return basetwo;
}
int main(){
    int baseten;
    vector<int> basetwo;
    cout << "Enter a non-negaFve base 10 integer between 0 and 4294967295 (with no commas) and hit Enter/Return:" << endl;
    cin >> baseten;
    if(baseten < 0 || cin.fail() || baseten > 4294967295){
        cout << "Invalid input!" << endl;
        return 1;
    }
    while(baseten > 0){
        basetwo.push_back(baseten % 2);
        baseten /= 2;
    }
    for (int i = basetwo.size() - 1; i >= 0; i--) {
        cout << basetwo[i];
    }
    cout << endl;



    return 0;
}