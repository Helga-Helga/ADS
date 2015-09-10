#include "Header.h"

float exponentiation(unsigned int power, float number){
    if (power==0) return 1;
    return number*exponentiation(power-1, number);
}

