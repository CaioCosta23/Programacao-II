#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

/**
 * @brief Programa que lê os dados de um determinado círculo (ponto que representa o centro e também o raio),
 * e lê os dados de um ponto (coordenadas X e Y) e verifica se o pontro está dentro do círculo;
 * 
 * @return int Programa principal;
 */
int main() {
    tCirculo circulo;
    tPonto ponto;
    float coordenadaXCentroCirculo, coordenadaYCentroCirculo, raio,  coordenadaXPonto, coordenadaYPonto;

    scanf("%f %f %f %f %f", &coordenadaXCentroCirculo, &coordenadaYCentroCirculo, &raio, &coordenadaXPonto, &coordenadaYPonto);

    circulo = Circulo_Cria(coordenadaXCentroCirculo, coordenadaYCentroCirculo, raio);
    ponto = Pto_Cria(coordenadaXPonto, coordenadaYPonto);

    printf("%d", Circulo_Interior(circulo, ponto));

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}