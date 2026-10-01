#include <stdio.h>
#include <stdlib.h>

#include "tadgen.h"

int main() {
    unsigned int quantidadeElementos, type;
    tGeneric *genericTad;
    unsigned short int erro = 0; // Variável lógica;

    printf("tad_gen_01\n");
    printf("Digite o tipo e o numero de elementos:\n");
    scanf("%d %d\n", type, quantidadeElementos);

    switch(type) {
        case INT:
            genericTad = CriaGenerico(INT, quantidadeElementos);
            break;
        case FLOAT:
            genericTad = CriaGenerico(FLOAT, quantidadeElementos);
            break;
        default:
            printf("Tipo de dado Incorreto!\n");
            erro = 1;
            break;
    }
    if (!(erro)) {
        printf("Digite o vetor:\n");

        LeGenerico(genericTad);
        ImprimeGenerico(genericTad);
        DestroiGenerico(genericTad);
    }

    return 0;
}