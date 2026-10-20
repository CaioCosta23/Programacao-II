#include <stdio.h>
#include <stdlib.h>

#include "agencia.h"

#define TAMANHO_NOME 50
#define QUANTIDADE_CONTAS 10

struct Agencia {
    Vector *vetorContas;
    unsigned int id;
    char *nome;
};

tAgencia *CriaAgencia() {
    tAgencia *agencia = NULL;

    agencia = (tAgencia*)malloc(sizeof(tAgencia));

    if (agencia == NULL) {
        printf("Erro! Alocacao de memoria da agencia mal-sucedida.\n");
        exit(1);
    }

    agencia->vetorContas = VectorConstruct();

    agencia->nome = NULL;

    agencia->nome = (char*)calloc(TAMANHO_NOME, sizeof(char));

    if ((*agencia).nome == NULL) {
        printf("Erro! Alocacao de memoria do nome da agencia mal-sucedida.\n");
        DestroiAgencia((DataType) agencia);
        exit(1);
    }
    agencia->id = -1;

    return agencia;
}

void LeAgencia(tAgencia *agencia) {
    scanf("%d;%[^\n]\n", &agencia->id, agencia->nome);
}

void AdicionaConta (tAgencia *agencia, tConta *conta) {
    VectorPushBack((*agencia).vetorContas, (DataType)conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2) {
    return ((*agencia2).id == numAgencia);
}

float GetSaldoMedioAgencia(tAgencia *agencia) {
    unsigned int c, quantidadeContas;
    float soma = 0;

    quantidadeContas = VectorSize((*agencia).vetorContas);

    for(c = 0; c < quantidadeContas; c++)
        soma += GetSaldoConta((tConta*)VectorGet((*agencia).vetorContas, c));
    
    return (soma / (float)quantidadeContas);

}

void ImprimeDadosAgencia(tAgencia *agencia) {
    printf("\tNome: %s\n", (*agencia).nome);
    printf("\tNumero: %d\n", (*agencia).id);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize((*agencia).vetorContas));
    printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}

void DestroiAgencia(DataType agencia) {
    tAgencia *ponteiroAgencia = (tAgencia*)agencia;

    if (ponteiroAgencia != NULL) {
        if ((*ponteiroAgencia).vetorContas != NULL) {
            VectorDestroy((*ponteiroAgencia).vetorContas, DestroiConta);
        }
        if ((*ponteiroAgencia).nome != NULL)
            free((*ponteiroAgencia).nome);

        free(ponteiroAgencia);
    }
}