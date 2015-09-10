#include "Header.h"

float exponentiation(int power, float number){
    if (power==0) return 1;
    return number*exponentiation(power-1, number);
}

