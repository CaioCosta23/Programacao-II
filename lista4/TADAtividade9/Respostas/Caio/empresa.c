#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"

#define MAXIMO_FUNCIONARIOS 20

static int verificaFuncionario(tEmpresa empresa, tFuncionario funcionario) {
    int f;
    unsigned short int jaExiste = 0; // Variável lógica;

    for(f = 0; f < empresa.qtdFuncionarios; f++) {
        if (getIdFuncionario(empresa.funcionarios[f]) == getIdFuncionario(funcionario)) {
            jaExiste = 1;
        }
    }
    return jaExiste;
}

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;

    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa() {
    tEmpresa empresa;
    int id, quantidadeCandidatos;

    scanf("%d ",&id);

    empresa = criaEmpresa(id);

    scanf("%d", &quantidadeCandidatos);

    int f;

    for (f = 0; f < quantidadeCandidatos; f++) {
        empresa = contrataFuncionarioEmpresa(empresa, leFuncionario());
    }
    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    if (verificaFuncionario(empresa, funcionario))
        empresa.funcionarios[empresa.qtdFuncionarios++] = funcionario;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    int f;

    printf("Empresa %d", empresa.id);

    for(f = 0; f < empresa.qtdFuncionarios; f++) {
        imprimeFuncionario(empresa.funcionarios[f]);
    }

}