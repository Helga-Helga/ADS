/* 
 * File:   main.cpp
 * Author: olya
 *
 * Created on September 10, 2015, 1:47 PM
 */

#include <cstdlib>
#include "Header.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int power;
    float number;
    cout<<"Enter a valid non-zero number ";
    cin>>number;
    cout<<"Enter a positive integral number ";
    cin>>power;
    cout<<number<<"^"<<power<<"="<<exponentiation(power, number);

    return 0;
}

