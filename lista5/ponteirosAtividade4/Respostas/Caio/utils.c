#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void LeNumeros(int *array, int tamanho) {
    int a;

    for(a = 0; a < tamanho; a++) {
        scanf("%d", *(array + a));
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media) {
    int a;
    int soma = 0;;

    for(a = 0; a < tamanho; a++) {
        if (a == 0) {
            *maior = *(array + a);
            *menor = *(array + a);
        }else {
            if (*(array + a) > *maior)
                *maior = *(array + a);
            
            if(*(array + a) < *menor)
                *menor = *(array + a);
        }

        soma += *(array + a);
    }
    *media = (float)soma / (float)tamanho;
}