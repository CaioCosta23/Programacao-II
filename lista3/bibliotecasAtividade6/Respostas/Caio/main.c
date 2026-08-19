#include <stdio.h>
#include <stdlib.h>

#include "temperature_conversor.h"

#define CELSIUS 'c'
#define FAHRENHEINT 'f'
#define KELVIN 'k'

int main() {
    float temperatura;
    char escalaAlvo, escalaObjetivo;

    scanf("%f %c %c", &temperatura, &escalaAlvo, &escalaObjetivo);

    if (escalaAlvo == CELSIUS) {
        if (escalaObjetivo == FAHRENHEINT) {
            printf("Temperature: %.2fFº", convert_temperature(temperatura, convert_celsius_to_fahrenheit));
        }else if (escalaObjetivo == KELVIN) {
            printf("Temperature: %.2fK", convert_temperature(temperatura, convert_celsius_to_kelvin));
        }
    }else if (escalaAlvo == FAHRENHEINT) {
        if (escalaObjetivo == CELSIUS) {
            printf("Temperature: %.2fCº", convert_temperature(temperatura, convert_fahrenheit_to_celsius));
        }else if (escalaObjetivo == KELVIN) {
            printf("Temperature: %.2fK", convert_temperature(temperatura, convert_fahrenheit_to_kelvin));
        }
    }else if (escalaAlvo == KELVIN) {
        if (escalaObjetivo == CELSIUS) {
            printf("Temperature: %.2fCº", convert_temperature(temperatura, convert_kelvin_to_celsius));
        }else if (escalaObjetivo == FAHRENHEINT) {
            printf("Temperature: %.2fFº", convert_temperature(temperatura, convert_kelvin_to_fahrenheit));
        }
    }

    return 0;
}