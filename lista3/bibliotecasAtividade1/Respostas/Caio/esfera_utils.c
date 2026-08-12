#include <math.h>

#include "esfera_utils.h"


float calcula_volume(float R) {
    const float fracaoBase = 4.0 / 3.0;
    const int expoentePotencia = 3;

    return fracaoBase * PI * (pow(R, expoentePotencia));
}


float calcula_area(float R) {
    const int constante = 4;
    const int expoentePotencia = 2;

    return constante * PI * (pow(R, expoentePotencia));
}

