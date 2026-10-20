#include <stdio.h>
#include <stdlib.h>

#include "conta.h"

#define TAMANHO_NOME 50

struct Conta {
    unsigned int id;
    char *nomeUsuario;
    float saldo;
};


/**
 * @brief Realoca a memória dinamicamente para receber um nome;
 * 
 * @param nome (Ponteiro ou) Lista/vetor'array' de caracteres que representam o nome do usuário da conta;
 * @param tamanho 
 * @return char* Ponteiro para o nome lido do usuário;
 */
static char *realocarMemoria(char *nome, unsigned int tamanho) {
    nome = (char*)realloc(nome, tamanho * sizeof(char));

    if (nome == NULL) {
        printf("Errro! Realocacao de memoria do nome do ussuario da conta mal-sucedida.\n");
        exit(1);
    }
    return nome;
}

/**
 * @brief Lê o nome de um ususário de uma conta;
 * 
 * @param nome (Ponteiro ou) Lista/vetor'array' de caracteres que representam o nome do usuário da conta;
 */
static void leNome(char *nome) {
    unsigned int contador = 0, tamanho = TAMANHO_NOME;
    char letra;
    const char PONTO_VIRGULA = ';';
    const unsigned int DOBRO = 2;

    while(1) {
        scanf("%c", &letra);

        if (letra == PONTO_VIRGULA)
            break;
        
        if (contador == tamanho) {
            tamanho *= DOBRO;
            nome = realocarMemoria(nome, tamanho);
        }
        nome[contador++] = letra;
    }
}


tConta *CriaConta() {
    tConta *conta = NULL;

    conta = (tConta*)malloc(sizeof(tConta));

    if (conta == NULL) {
        printf("Erro! Alocacao de memoria da conta mal-sucedida!\n");
        exit(1);
    }

    conta->nomeUsuario = NULL;

    conta->nomeUsuario = (char*)calloc(TAMANHO_NOME, sizeof(char));

    if ((*conta).nomeUsuario == NULL) {
        printf("Erro! Alocacao de memoria de nome do usuario da conta mal-sucedida.\n");
        DestroiConta((DataType)conta);
        exit(1);
    }

    conta->id = -1;

    return conta;
}

void LeConta(tConta *conta) {
    scanf("%d;", &conta->id);

    leNome((*conta).nomeUsuario);

    scanf("%f\n", &conta->saldo);
}


float GetSaldoConta(tConta *conta) {
    return (*conta).saldo;
}

void DestroiConta(DataType conta) {
    tConta *ponteiroConta = (tConta*)conta;

    if (ponteiroConta != NULL) {
        if ((*ponteiroConta).nomeUsuario != NULL)
            free((*ponteiroConta).nomeUsuario);

        free(ponteiroConta);
    }
}