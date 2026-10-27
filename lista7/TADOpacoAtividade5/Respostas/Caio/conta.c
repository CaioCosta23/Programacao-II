#include <stdio.h>
#include <stdlib.h>

#include "conta.h"
#include "usuario.h"

struct Conta {
    int numero;
    float saldo;
    tUsuario *usuario;
};

tConta *CriaConta() {
    tConta *conta = NULL;

    conta = (tConta*)malloc(sizeof(tConta));

    if (conta == NULL) {
        printf("Erro! Alocacao de memoria de conta mal-sucedida.\n");
        exit(1);
    }

    conta->usuario = CriaUsuario();
    conta->numero = -1;
    conta->saldo = 0;

    return conta;
}

void LeConta(tConta *conta) {
    scanf("%d\n", &conta->numero);
    LeUsuario(conta->usuario);
}

int VerificaConta(tConta *conta, int numero) {
    return ((*conta).numero == numero);
}

void SaqueConta(tConta *conta, float valor) {
    if ((*conta).saldo >= 0)
        conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor) {
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor) {
    if ((*origem).saldo >= 0) {
        SaqueConta(origem, valor);
        DepositoConta(destino, valor);
    }    
}

void ImprimeConta(tConta *conta) {
    printf("Conta: %d\n", (*conta).numero);
    printf("Saldo: R$ %.2f\n", (*conta).saldo);
    ImprimeUsuario((*conta).usuario);
}

void DestroiConta(tConta *conta) {
    if (conta != NULL) {
        DestroiUsuario((*conta).usuario);
        free(conta);
    }
}