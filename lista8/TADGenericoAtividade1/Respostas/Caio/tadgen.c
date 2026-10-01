#include <stdio.h>
#include <stdlib.h>

#include "tadgen.h"

struct generic {
    void *data;
    Type type;
    int size;
};

tGeneric *CriaGenerico (Type type, int numElem) {
    tGeneric *genericTad = NULL;

    genericTad = (tGeneric*)malloc(sizeof(tGeneric));

    if (genericTad == NULL) {
        printf("Erro na alocacao de memoria de estrutura generica mal-sucedida.\n");
        exit(1);
    }
    genericTad->data = NULL;

    switch(type){
        case INT:
            genericTad->data = (int*)calloc(numElem, sizeof(int));

            if ((*genericTad).data == NULL) {
                printf("Erro! Alocacao de memoria de dado genérico mal-sucedida.\n");
                DestroiGenerico(genericTad);
                exit(1);
            }
            break;
        case FLOAT:
            genericTad->data = (float*)calloc(numElem, sizeof(float));

            if ((*genericTad).data == NULL) {
                printf("Erro! Alocacao de memoria de dado genérico mal-sucedida.\n");
                DestroiGenerico(genericTad);
                exit(1);
            }
            break;
        default:
            printf("Tipo nao identificado.\n");
            break;
    }

    genericTad->size = numElem;
    genericTad->type = type;

    return genericTad;
}

void LeGenerico(tGeneric *gen) {
    unsigned int d;

    printf("\nDigite o vetor:\n");

    switch(gen->type){
        case INT:
            for(d = 0; d < (*gen).size; d++)
                scanf("%d", (((int*)(gen->data)) + d));
            
            break;
        case FLOAT:
            for(d = 0; d < (*gen).size; d++)
                scanf("%f", (((float*)(gen->data)) + d));
            break;
        default:
            printf("Tipo nao identificado.\n");
            
            for(d = 0; d < (*gen).size; d++)
                scanf("%*[^\n]\n");
            break;
    }
}


void ImprimeGenerico(tGeneric *gen) {
    unsigned short int d;

    for(d = 0; d < (*gen).size; d++) {
        if ((*gen).type == INT)
            printf("%d ", ((int*)(*gen).data)[d]);
        else if ((*gen).type == FLOAT)
            printf("%.2f ", ((float*)(*gen).data)[d]);
    }
}

void DestroiGenerico(tGeneric *gen) {
    if (gen != NULL) {
        if ((*gen).data != NULL)
            free((*gen).data);
        free(gen);
    }
}