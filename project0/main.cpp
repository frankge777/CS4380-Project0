#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include "myUFls.h"

using namespace std;

int main(){
    int baseten;
    string basetwo;
    cout << "Enter a non-negaFve base 10 integer between 0 and 4294967295 (with no commas) and hit Enter/Return:" << endl;
    cin >> baseten;

    if(baseten < 0 || cin.fail() || baseten > 4294967295){
        cout << "Invalid input!" << endl;
        return 1;
    }
    basetwo = convTen2Two(baseten);
    cout << basetwo << endl;



    return 0;
}