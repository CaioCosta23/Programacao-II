#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

/**
 * @brief Programa que lê os dados de uma lista de pessoas e associa seu parentesco;
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned int quantidadePessoas, p;

    scanf("%d\n", &quantidadePessoas);

    tPessoa pessoas[quantidadePessoas];

    for(p = 0; p < quantidadePessoas; p++) {
        pessoas[p] = CriaPessoa();
        LePessoas(&pessoas[p]);
    }
    AssociaFamiliasGruposPessoas(pessoas, quantidadePessoas);

    for(p = 0; p < quantidadePessoas; p++)
        ImprimePessoa(&pessoas[p]);

    return 0;
}