#include <iostream>
#include <string>
#include <algorithm>
#include "myUFls.h"
using namespace std;
string convTen2Two(unsigned int baseTenValue){
    string basetwo;
    if (baseTenValue == 0) {
        return "0";
    }

    while(baseTenValue > 0){
        basetwo.push_back((baseTenValue % 2) + '0');
        baseTenValue /= 2;
    }
    reverse(basetwo.begin(), basetwo.end()); 
    return basetwo;
}