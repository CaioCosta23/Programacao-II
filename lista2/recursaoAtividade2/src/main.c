#include <stdio.h>
#include <stdlib.h>

int somaElementosPares(int elementos[], int quantidadeElementos);

int main() {
    int quantidadeRodadas, quantidadeElementos, r, e;

    scanf("%d\n", &quantidadeRodadas);

    for (r = 0; r < quantidadeRodadas; r++) {
        scanf("%d\n", &quantidadeElementos);

        int elementos[quantidadeElementos];

        for(e = 0; e < quantidadeElementos; e++) {
            scanf("%d", &elementos[e]);
        }
        printf("%d\n", somaElementosPares(elementos, quantidadeElementos));
    }
    return 0;
}


int somaElementosPares(int elementos[], int quantidadeElementos){
    const static unsigned short int semValor = 0;
    int somaPares = 0;

    if (quantidadeElementos > 0){
        //printf("%d", elementos[quantidadeElementos - 1]);

        if (elementos[quantidadeElementos - 1] % 2 == 0){
            return elementos[quantidadeElementos - 1] + somaElementosPares(elementos, (quantidadeElementos - 1));
        }else{
            return somaElementosPares(elementos, (quantidadeElementos - 1));
        }
    }
    return somaPares;
}