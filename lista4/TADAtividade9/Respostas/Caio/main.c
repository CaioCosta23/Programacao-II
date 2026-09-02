#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"

/**
 * @brief Programa que lê informações e cadastra empresas e funcionários e as exibe na tela;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeEmpresas, e;

    scanf("%d", &quantidadeEmpresas);

    tEmpresa empresas[quantidadeEmpresas];

    for(e = 0; e < quantidadeEmpresas; e++) {
        empresas[e] = leEmpresa();
    }

    for(e = 0; e < quantidadeEmpresas; e++) {
        imprimeEmpresa(empresas[e]);
    }

    return 0;
}