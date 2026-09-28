#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "ponto.h"

struct ponto {
    float coordenadaX, coordenadaY;
};

tPonto Pto_Cria(float x, float y) {
    tPonto ponto = NULL;

    ponto = (tPonto)malloc(sizeof(struct ponto));

    if (ponto == NULL) {
        prrintf (" Erro! Alocacao de memoria de ponto mal-sucedida.\n");
        exit(1);
    }

    Pto_Atribui_x(ponto, x);
    Pto_Atribui_y(ponto, y);

    return ponto;
}

void Pto_Atribui_x(tPonto p, float x) {
    p->coordenadaX = x;
}

void Pto_Atribui_y(tPonto p, float y) {
    p->coordenadaY = y;
}

float Pto_Acessa_x(tPonto p) {
    return (*p).coordenadaX;
}

float Pto_Acessa_y(tPonto p) {
    return (*p).coordenadaX;
}

float Pto_Distancia(tPonto p1, tPonto p2) {
    return sqrt(pow(((*p2).coordenadaY - (*p1).coordenadaY), 2) + pow(((*p2).coordenadaX - (*p1).coordenadaX), 2));
}

void Pto_Apaga(tPonto p) {
    if (p != NULL) {
        free(p);
    }
}