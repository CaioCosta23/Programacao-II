#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct Vector {
    data_type *data;
    unsigned int size, allocated;
};

#define INITIAL_SIZE 10

/**
 * @brief Realoca (dinamicamente) a memória o vetor/lista/'array' de dados do vetor;
 * 
 * @param vector Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do vetor;
 */
static void reallocateMemory(Vector *vector) {
    vector->allocated *= 2;

    vector->data = (data_type*)realloc((*vector).data, (*vector).allocated * sizeof(data_type));

    if ((*vector).data == NULL) {
        printf("Erro! Realocacao de memoria dos dados do vetor mal-sucedida.\n");
        exit(1);
    }
}

Vector *VectorConstruct() {
    Vector *vector = NULL;

    vector = (Vector*)malloc(sizeof(Vector));

    if (vector == NULL) {
        printf("Erro! Alocacao de memoria de vetor mal-sucedida!\n");
        exit(1);
    }

    vector->data = NULL;

    vector->data = (data_type*)malloc(INITIAL_SIZE * sizeof(data_type));

    if ((*vector).data == NULL) {
        printf("Erro! Alocacao de memoria de dados do vetor mal-sucedida!\n");
    }

    vector->size = 0;
    vector->allocated = INITIAL_SIZE;

    return vector;
}

void VectorPushBack(Vector *v, data_type val) {
    if ((*v).allocated == (*v).size)
        reallocateMemory(v);

    v->data[(*v).size++] = val;
}

data_type VectorGet(Vector *v, int i) {
    return (*v).data[i];
}

int VectorSize(Vector *v) {
    return (*v).size;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)) {
    if (v != NULL) {
        if ((*v).data != NULL) {
            unsigned int d;

            for(d = 0; d < (*v).size; d++)
                destroy((*v).data[d]);
            
            free((*v).data);
        }
        free(v);
    }
}