#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * @brief Programa que Cria um vetor (alocando suas posições na memória dinamicamente),
 * lê os dados do vetor e calcula a média dos valores do vetor (e desaloca dinamicamente as posições do vetor);
 * 
 * @return int Programa principal;
 */
int main() {
    int tamanho;
    int *vetor;

    scanf("%d", &tamanho);


    vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);

    printf("%.2f\n", CalculaMedia(vetor, tamanho));

    LiberaVetor(vetor);


    return 0;
}