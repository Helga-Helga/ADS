#include "Header.h"

int gcd(int m, int n){
    if ((n==0)&&(m==0)){
        throw invalid_argument("Invalid syntax.");
    }         
            
    if (n==0) {
        return (m < 0)? -m : m;
    }
    return gcd(n, m%n);
}
