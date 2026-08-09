#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define ERROU 0
#define ACERTOU 1

typedef struct{
    float x, y, raio;
}Alvo;

typedef struct{
    float x, y, raio;
}Disparo;

Alvo leAlvo();
Disparo leDisparo();
void imprimeResultado();

int verificaColisao(Alvo alvo, Disparo disparo) {
    unsigned short int resultado = ERROU;
    double distancia;

    // Calcula a distancia do centro do alvo até o centro do disparo;
    distancia = sqrt((pow((disparo.y - alvo.y), 2)) + (pow((disparo.x - alvo.x), 2)));

    if(distancia <= (alvo.raio + disparo.raio))
        resultado = ACERTOU;

    return resultado;
}

/**
 * @brief 
 * 
 * @return int Programa principal
 */
int main() {
    float xAlvo, yAlvo, xDisparo, yDisparo, raioAlvo, raioDisparo;
    Alvo alvo;
    Disparo disparo;

    alvo = leAlvo();
    disparo = leDisparo();

    imprimeResultado(alvo, disparo);

    return 0;
}

Alvo leAlvo(){
    Alvo alvo;

    scanf("%f %f %f\n", &alvo.x, &alvo.y, &alvo.raio);
    
    return alvo;
}

Disparo leDisparo(){
    Disparo disparo;

    scanf("%f %f %f\n", &disparo.x, &disparo.y, &disparo.raio);
    
    return disparo;
}

void imprimeResultado(Alvo alvo, Disparo disparo) {
    if (verificaColisao(alvo, disparo))
        printf("ACERTOU");
    else
        printf("ERROU");
}