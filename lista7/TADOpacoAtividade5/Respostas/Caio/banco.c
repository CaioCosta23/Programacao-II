#include <stdio.h>
#include <stdlib.h>

#include "banco.h"
#include "conta.h"

#define QUANTIDADE_INICIAL_CONTAS 10

struct Banco {
    tConta **contas;
    unsigned int quantidadeContas;
    unsigned int contasReservadas;
};

/**
 * @brief Realoca a memória dinamicamente para um vetor/lista/'array' de contas de um banco;
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 */
static void realocarMemoriaVetor(tBanco *banco) {
    banco->contasReservadas *= 2;

    banco->contas = (tConta**)realloc((*banco).contas, (*banco).contasReservadas * sizeof(tConta*));

    if ((*banco).contas == NULL) {
        printf("Erro! Realocacao de memoria de vetor/lista/'array' de contas do banco mal-sucedida.\n");
        exit(1);
    }
}

/**
 * @brief Verifica se uma conta existe dentro do banco (e caso exista, retorna o índice da posição da mesma dentro da lista/vetor/'array' de contas do banco);
 * 
 * @param banco Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a esrutura que contém as informações (dados atualizados) do banco;
 * @param contaProcurada Número da conta procurada dentro do banco;
 * @return int Índice (posição) da conta na lista/vetor/'array' de contas do banco ou -1 caso a conta não exista dentro do banco;
 */
static int verificaExistenciaConta(tBanco *banco, unsigned int contaProcurada) {
    int c;

    for(c = 0; c < (*banco).quantidadeContas; c++)
        if (VerificaConta((*banco).contas[c], contaProcurada))
            return c;
    
    return -1;
}


tBanco *CriaBanco() {
    tBanco *banco = NULL;

    banco = (tBanco*)malloc(sizeof(tBanco));

    if (banco == NULL) {
        printf("Erro! Alocacao de memoria para banco mal-sucedida.\n");
        exit(1);
    }

    banco->contas = NULL;

    banco->contas = (tConta**)malloc(QUANTIDADE_INICIAL_CONTAS * sizeof(tConta*));

    if ((*banco).contas == NULL) {
        printf("Erro! Alocacao de memoria para lista de contas do banco mal-sucedida.\n");
        DestroiBanco(banco);
        exit(1);
    }

    banco->quantidadeContas = 0;
    banco->contasReservadas = QUANTIDADE_INICIAL_CONTAS;

    return banco;
}

void AbreContaBanco(tBanco *banco) {
    if ((*banco).quantidadeContas == (*banco).contasReservadas)
        realocarMemoriaVetor(banco);
    
    banco->contas[(*banco).quantidadeContas] = CriaConta();
    LeConta((*banco).contas[(*banco).quantidadeContas++]);
}

void SaqueContaBanco(tBanco *banco) {
    unsigned int contaProcurada, indiceContaProcurada;
    float valor;

    scanf("%d %f\n", &contaProcurada, &valor);

    indiceContaProcurada = verificaExistenciaConta(banco, contaProcurada);

    if (indiceContaProcurada >= 0)
        SaqueConta((*banco).contas[indiceContaProcurada], valor);
}

void DepositoContaBanco(tBanco *banco) {
    unsigned int contaProcurada, indiceContaProcurada;
    float valor;

    scanf("%d %f\n", &contaProcurada, &valor);

    indiceContaProcurada = verificaExistenciaConta(banco, contaProcurada);

    if (indiceContaProcurada >= 0)
        DepositoConta((*banco).contas[indiceContaProcurada], valor);
}

void TransferenciaContaBanco(tBanco *banco) {
    unsigned int contaOrigem, contaDestino, indiceContaOrigem, indiceContaDestino;
    float valor;

    scanf("%d %d %f\n", &contaOrigem, &contaDestino, &valor);

    indiceContaOrigem = verificaExistenciaConta(banco, contaOrigem);
    indiceContaDestino = verificaExistenciaConta(banco, contaDestino);

    if ((indiceContaOrigem >= 0) && (indiceContaDestino >= 0))
        TransferenciaConta((*banco).contas[indiceContaOrigem], (*banco).contas[indiceContaDestino], valor);
}

void ImprimeRelatorioBanco(tBanco *banco) {
    unsigned int c;

    printf("===| Imprimindo Relatorio |===\n");

    for(c = 0; c < (*banco).quantidadeContas; c++)
        ImprimeConta((*banco).contas[c]);

}

void DestroiBanco(tBanco *banco) {
    if (banco != NULL) {
        if ((*banco).contas != NULL) {
            unsigned int c;

            for(c = 0; c < (*banco).quantidadeContas; c++)
                DestroiConta((*banco).contas[c]);
            
            free((*banco).contas);
        }
        free(banco);
    }
}