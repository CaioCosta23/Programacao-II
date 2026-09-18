#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

/**
 * @brief Programa que lê uma quantidade o nome de pessoas e associa seu paraentesco;
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned int quantidadePessoas, p;

    scanf("%d\n", &quantidadePessoas);

    tPessoa pessoas[quantidadePessoas];

    for(p = 0; p < quantidadePessoas; p++) {
        pessoas[p] = CriaPessoa();
        LePessoa(&pessoas[p]);
    }

    AssociaFamiliasGruposPessoas(pessoas);

    for(p = 0; p < quantidadePessoas; p++)
        ImprimePessoa(&pessoas[p]);

    return 0;
}