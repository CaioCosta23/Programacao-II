#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"

float Calcular(float num1, float num2, CalculadoraCallback operacao) {
    return (operacao(num1, num2));
}