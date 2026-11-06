#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

#define TAMANHO_INICIAL_NOME 30

#define PARADA '\n'

/**
 * @brief Realoca a memória (dinamicamente) para receber um nome (com um novo tamanho)
 * 
 * @param nome Ponteiro (Lista/vetor/'array' de caracteres) para um nome;
 * @param tamanhoNome Tamanho do nome (novo tamanho que representa quatidade de caracteres que a lista/vetor/'array' comportará);
 * @return char* Ponteiro (Lista/vetor/'array' de caracteres) para um nome com seu tamanho (em meória dinamicamente alocada) realocada;
 */
static char *realocaVetorNome(char *nome, unsigned int tamanhoNome) {
    nome = (char*)realloc(nome, tamanhoNome * sizeof(nome));

    if (nome == NULL) {
        printf("Erro! Realocacao de memoria para nome do aluno mal-sucedida.\n");
        exit(1);
    }

    return nome;
}

/**
 * @brief Lê um nome;
 * 
 * @param nome Ponteiro (Lista/vetor/'array' de caracteres) para um nome;
 */
static void LeNome(char *nome) {
    unsigned int contador = 0;
    char letra;
    unsigned int espacoNome;

    espacoNome = TAMANHO_INICIAL_NOME;

    while(1) {
        scanf("%c", &letra);

        if (espacoNome == contador) {
            espacoNome *= 2;
            nome = realocaVetorNome(nome, espacoNome);
        }

        if (letra == PARADA) {
            nome[contador] = '\0';
            break;
        }

        nome[contador++] = letra;
    }
}

tAluno *CriaAluno() {
    tAluno *aluno = NULL;

    aluno = (tAluno*)malloc(sizeof(tAluno));

    if (aluno == NULL) {
        printf("Erro! Alocacao de memoria de aluno mal-sucedida.\n");
        exit(1);
    }

    aluno->nome = NULL;

    aluno->nome = (char*)calloc(TAMANHO_INICIAL_NOME, sizeof(char));

    if ((*aluno).nome == NULL) {
        printf("Erro! Alocacao de memoria do nome do aluno mal-sucedida.\n");
        ApagaAluno(aluno);
        exit(1);
    }

    aluno->matricula = -1;
    aluno->n1 = 0;
    aluno->n2 = 0;
    aluno->n3 = 0;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    LeNome(aluno->nome);
    scanf("%d\n", &aluno->matricula);
    scanf("%d %d %d\n", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno *aluno1, tAluno *aluno2) {
    if ((*aluno1).matricula > (*aluno2).matricula)
        return 1;
    else if ((*aluno1).matricula < (*aluno2).matricula)
        return -1;
    else
        return 0;
}

int CalculaMediaAluno(tAluno *aluno) {
    const static unsigned int QUANTIDADE_NOTAS = 3;

    return (((*aluno).n1 + (*aluno).n2 + (*aluno).n3) / QUANTIDADE_NOTAS);
}

int VerificaAprovacao(tAluno *aluno) {
    const static unsigned short int MEDIA = 7;

    return (CalculaMediaAluno(aluno) >= MEDIA);
}

void ImprimeAluno(tAluno *aluno) {
    printf("%s\n", (*aluno).nome);
}

void ApagaAluno(tAluno *aluno) {
    if (aluno != NULL) {
        if ((*aluno).nome != NULL)
            free((*aluno).nome);

        free(aluno);
    }
}