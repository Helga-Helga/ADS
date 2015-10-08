#include "Header.h"

int fibonacci(unsigned int n){
    static int known[50];
    if (known[n] != 0) return known[n];
    int t = n;
    if (n < 1) return 0;
    else if (n==1) return 1;
    else if (n > 1) t=fibonacci(n-1)+fibonacci(n-2);
    return known[n]=t;
}

int F(unsigned int n) {
    if (n < 1) return 0;
    else if (n == 1) return 1;
    return F(n-1) + F(n-2);
}