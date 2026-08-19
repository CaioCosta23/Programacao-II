#include <stdio.h>
#include <stdlib.h>

#include "temperature_conversor.h"

#define MARCO_ESCALA_KELVIN 273.15
#define MARCA_ESCALA_FAHRENHEIT 32.00

float convert_celsius_to_kelvin(float temperature) {
    return temperature + MARCO_ESCALA_KELVIN;
}

float convert_celsius_to_fahrenheit(float temperature) {
    return (temperature * ((float)9 / (float)5) + MARCA_ESCALA_FAHRENHEIT);
}

float convert_kelvin_to_celsius(float temperature) {
    return temperature - MARCO_ESCALA_KELVIN;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    return convert_celsius_to_fahrenheit(convert_kelvin_to_celsius(temperature));
}

float convert_fahrenheit_to_celsius(float temperature) {
    return ((temperature - MARCA_ESCALA_FAHRENHEIT) * ((float)5 / (float)9));
}

float convert_fahrenheit_to_kelvin(float temperature) {
    return convert_celsius_to_kelvin(convert_fahrenheit_to_celsius(temperature));
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    return convert_func(temperature);
}