#include <stdio.h>
#include <stdlib.h>

#include "evento.h"

void cadastrarEvento(Evento *eventos, int *numEventos) {
    if (*numEventos == MAX_EVENTOS) {
        printf("Limite de eventos atingido!\n");
    }else {
        scanf("[^\n]\n", (eventos + *numEventos)->nome);
        scanf("%d %d %d\n", &(eventos + *numEventos)->dia, &(eventos + *numEventos)->mes, &(eventos + *numEventos)->ano);
        printf("Evento cadastrado com sucesso!\n");
    }
}

void trocarDataEvento(Evento *eventos, int *numEventos) {
    unsigned int posicao;

    scanf("%hd\n", &posicao);

    if ((posicao < 0) || (posicao >= *numEventos)) {
        printf("Indice invalido!\n");
    }else {
        scanf("%d %d %d\n", &(eventos + posicao)->dia, &(eventos + posicao)->mes, &(eventos + posicao)->ano);
        printf("Data modificada  com sucesso!\n");
    }
}

void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos) {
    if (((*indiceA < 0) || (*indiceA >= *numEventos)) || ((*indiceB < 0) || (indiceB >= *numEventos))) {
        printf("Indices invalidos!\n");
    }else {
        Evento auxiliar;

        auxiliar = *(eventos + *indiceA);
        *(eventos + *indiceA) = *(eventos + *indiceB);
        *(eventos + *indiceB) = auxiliar;

        printf("Eventos trocados com sucesso!\n");
    }
}

void exibirEventos(Evento *eventos, int *numEventos) {
    int e;

    if (*numEventos == 0)
        printf("Nenhum evento cadastrado.\n");   
    else 
        for (e = 0; e < *numEventos; e++)
            printf("%d - %s - %02d/%02d/%04d\n", e, (*(eventos + e)).nome, (*(eventos + e)).dia, (*(eventos + e)).mes, (*(eventos + e)).ano);
    
}