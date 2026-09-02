#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"

tFuncionario criaFuncionario(int id, float salario) {
    tFuncionario funcionario;

    funcionario.id = id;
    funcionario.salario = salario;

    return funcionario;
}

tFuncionario leFuncionario() {
    tFuncionario funcionario;
    int id;
    float salario;

    scanf("%d %f\n", &id, &salario);

    funcionario = criaFuncionario(id, salario);

    return funcionario;
}

int getIdFuncionario(tFuncionario funcionario) {
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario) {
    printf("- Funcionario %d: RS %.2f\n", getIdFuncionario(funcionario), funcionario.salario);
}