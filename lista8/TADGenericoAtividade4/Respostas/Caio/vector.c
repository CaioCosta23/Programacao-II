#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define INITIAL_SIZE 10

struct Vector{
    DataType *data;
    unsigned int size, allocated;
};

/**
 * @brief Realoca a meória dinamicamente para uma estrutura de dados do tipo vetor;
 * 
 * @param vector Ponteiro para Tipo Abstrato de Dados da estrutura que contém as informções (dados atualizados) vetor;
 */
static void reallocMemory(Vector *vector) {
    const unsigned int DOUBLE = 2;

    vector->allocated *= DOUBLE;

    vector->data = (DataType*)realloc((*vector).data, (*vector).allocated * sizeof(DataType));

    if ((*vector).data == NULL) {
        printf("Erro! Realocacao de memoria de vetor de dados da estrutura de dados do vetor mal-sucedida.\n");
        exit(1);
    }
}


Vector *VectorConstruct() {
    Vector *vector = NULL;

    vector = (Vector*)malloc(sizeof(Vector));

    if (vector == NULL) {
        printf("Erro! Alocacao de memoria de estrutura de dados de vetor mal-sucedida.\n");
        exit(1);
    }

    vector->data = NULL;

    vector->data = (DataType*)malloc(INITIAL_SIZE * sizeof(DataType));

    if((*vector).data == NULL) {
        printf("Erro! Alocacao de memoria de vetor de dados da estrutura de dados de vetor mal-sucedida.\n");
        exit(1);
    }

    vector->size = 0;
    vector->allocated = INITIAL_SIZE;

    return vector;
}

void VectorPushBack(Vector *v, DataType val) {
    if ((*v).size == (*v).allocated)
        reallocMemory(v);

    v->data[(*v).size++] = val;
}

DataType VectorGet(Vector *v, int i) {
    return (*v).data[i];
}

int VectorSize(Vector *v) {
    return (*v).size;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    if (v != NULL) {
        if ((*v).data != NULL) {
            unsigned int d;

            for(d = 0; d < v->size; d++)
                destroy((*v).data[d]);

            free((*v).data);
        }
        free(v);
    }
}