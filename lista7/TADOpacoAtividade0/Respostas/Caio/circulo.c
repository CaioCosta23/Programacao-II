#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

struct circulo {
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria(float x, float y, float r) {
    tCirculo circulo = NULL;

    circulo = (tCirculo)malloc(sizeof(struct circulo));

    if (circulo == NULL) {
        printf("Erro! Alocacao de memoria de circulo mal-sucedida.\n");
        exit(1);
    }
    Circulo_Atribui_Centro(circulo, Pto_Cria(x, y));
    Circulo_Atribui_Raio(circulo, r);

    return circulo;
}

void Circulo_Atribui_Centro(tCirculo c, tPonto p) {
    c->centro = p;
}

void Circulo_Atribui_Raio(tCirculo c, float r) {
    c->raio = r;
}

float Circulo_Acessa_Raio(tCirculo c) {
    return (*c).raio;
}

tPonto Circulo_Acessa_Centro(tCirculo c) {
    return (*c).centro;
}

int Circulo_Interior(tCirculo c, tPonto p) {
    return (Pto_Distancia(p, Circulo_Acessa_Centro(c)) <= (*c).raio);
}

void Circulo_Apaga(tCirculo c) {
    if (c != NULL)
        if ((*c).centro != NULL)
            Pto_Apaga((*c).centro);

        free(c);
}