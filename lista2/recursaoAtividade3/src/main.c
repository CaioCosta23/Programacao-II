#include <stdio.h>
#include <stdlib.h>

int contaOcorrencias(int vetor[], int quantidadeElementos, int procurado);

/**
 * @brief Programa que lê determinada quantidade de vetores, u, elemeno a ser procurado,
 * os elementos em si do vetor, e retorna a quantidade de vezes que o elemento procurado apareceu no vetor;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeVetores, quantidadeElementos, procurado, v, e;

    scanf("%d\n", &quantidadeVetores);

    for(v = 0; v < quantidadeVetores; v++) {
        scanf("%d %d\n", &procurado, &quantidadeElementos);

        int elementos[quantidadeElementos];

        for(e = 0; e < quantidadeElementos; e++) {
            scanf("%d", &elementos[e]);
        }
        printf("%d\n", contaOcorrencias(elementos, quantidadeElementos, procurado));
    }

    return 0;
}

int contaOcorrencias(int vetor[], int quantidadeElementos, int procurado) {
    int ocorrencias = 0;
    const unsigned short int semSoma = 0, comSoma = 1;

    if (quantidadeElementos > 0) {
        if (vetor[quantidadeElementos - 1] == procurado)
            return contaOcorrencias(vetor, (quantidadeElementos - 1), procurado) + comSoma;
        else 
            return contaOcorrencias(vetor, (quantidadeElementos - 1), procurado) + semSoma;
    }
    return ocorrencias;
}