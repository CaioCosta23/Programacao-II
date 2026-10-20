#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

#define TAMANHO_NOME 50

struct Banco {
    Vector *vetorAgencias;
    char *nome;
};

/**
 * @brief Realoca a memóoria dinamicamente para receber um nome;
 * 
 * @param nome (Ponteiro ou) Lista/vetor/'array' de caracteres que contém o nome;
 * @param tamanho Tamanho da memória a ser realocada;
 * @return char* Ponteiro para a memória realocada;
 */
static char *reallocarMemoria(char *nome, unsigned int tamanho) {
    nome = (char*)realloc(nome, tamanho * sizeof(char));

    if (nome == NULL) {
        printf("Erro! Realocacao de memoria do nome do banco mal-sucedida.\n");
        exit(1);
    }
    return nome;
}

/**
 * @brief Lê um nome;
 * 
 * @param nome (Ponteiro ou) Lista/vetor/'array' de caracteres que contém o nome;
 */
static void leNome(char *nome) {
    unsigned int contador = 0, tamanho = TAMANHO_NOME;
    char letra;
    const char QUEBRA_LINHA = '\n';
    const unsigned int DOBRO = 2;

    while(1) {
        scanf("%c", &letra);

        if (letra == QUEBRA_LINHA)
            break;

        if (contador == tamanho) {
            tamanho *= DOBRO;
            nome = reallocarMemoria(nome, tamanho);
        }
        nome[contador++] = letra;
    }
}

tBanco *CriaBanco() {
    tBanco *banco = NULL;

    banco = (tBanco*)malloc(sizeof(tBanco));

    if (banco == NULL) {
        printf("Erro! Alocacao de memoria de banco mal-sucedida!\n");
        exit(1);
    }

    banco->vetorAgencias = VectorConstruct();
    banco->nome = NULL;

    banco->nome = (char*)calloc(TAMANHO_NOME, sizeof(char));

    if ((*banco).nome == NULL) {
        printf("Erro! Alocacao de memoria do nome do banco mal-sucedida.\n");
        DestroiBanco(banco);
        exit(1);
    }

    return banco;
}

void LeBanco(tBanco *banco) {
    leNome((*banco).nome);
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {
    VectorPushBack((*banco).vetorAgencias, (DataType*)agencia);
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {
    unsigned int a;
    tAgencia *agencia;

    for(a = 0; a < VectorSize((*banco).vetorAgencias); a++) {
        agencia = (tAgencia*)VectorGet((*banco).vetorAgencias, a);

        if (ComparaAgencia(numAgencia, agencia))
            AdicionaConta(agencia, cliente);
    }
}

void ImprimeRelatorioBanco(tBanco *banco) {
    unsigned int quantidadeAgencias;

    printf("%s\n", (*banco).nome);
    printf("Lista de agencias:\n");

    quantidadeAgencias = VectorSize((*banco).vetorAgencias);

    if (quantidadeAgencias > 0) {
        unsigned int a;

        for(a = 0; a < quantidadeAgencias; a++)
            ImprimeDadosAgencia((tAgencia*)VectorGet((*banco).vetorAgencias, a));
    }
}

void DestroiBanco(tBanco *banco) {
    if (banco != NULL) {
        if ((*banco).vetorAgencias != NULL)
            VectorDestroy((*banco).vetorAgencias, DestroiAgencia);
        if ((*banco).nome != NULL)
            free((*banco).nome);

        free(banco);
    }
}