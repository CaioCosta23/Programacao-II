#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

#define QUANTIDADE_NOTAS 3
#define TAMANHO_MAXIMO_NOME 50
#define MEDIA 7

struct Aluno {
    int matricula, quantidadeNotas;
    char *nome;
    float *notas;
};

tAluno *CriaAluno() {
    tAluno *aluno = NULL;

    aluno = (tAluno*)malloc(sizeof(tAluno));

    if (aluno == NULL) {
        printf("Erro! Alocacao de memoria de aluno mal-sucedida.\n");
        exit(1);
    }
    
    aluno->matricula = -1;
    aluno->nome = NULL;

    aluno->nome = (char*)calloc(TAMANHO_MAXIMO_NOME, sizeof(char));

    if ((*aluno).nome == NULL){
        printf("Erro! Alocacao de memoria do nome do aluno mal-sucedida.\n");
        ApagaAluno(aluno);
        exit(1);
    }

    aluno->notas = NULL;

    aluno->notas = (int*)calloc(QUANTIDADE_NOTAS, sizeof(int));

    if ((*aluno).nome == NULL){
        printf("Erro! Alocacao de memoria do nome do aluno mal-sucedida.\n");
        ApagaAluno(aluno);
        exit(1);
    }
    aluno->quantidadeNotas = QUANTIDADE_NOTAS;

    return aluno;
}

void LeAluno(tAluno *aluno) {
    char letra;
    unsigned int contador = 0;
    static unsigned int TAMANHO_VETOR = TAMANHO_MAXIMO_NOME;

    while(1){
        scanf("%c", letra);

        if (contador > TAMANHO_VETOR){
            TAMANHO_VETOR *= 2;
            aluno->nome = (char*)realloc((*aluno).nome, TAMANHO_VETOR  * sizeof(char));

            if ((*aluno).nome == NULL) {
                printf("Erro! Realocacao de memoria do nome do alluno mal-sucedida.\n");
                ApagaAluno(aluno);
                exit(1);
            }
        }
        
        aluno->nome[contador++] = letra;

        if (letra == '\0')
            break;
    }
    scanf("%d", &aluno->matricula);

    unsigned int n;

    for (n = 0; n < QUANTIDADE_NOTAS; n++)
        scanf("%d", &aluno->notas[n]);
    
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
    unsigned int n;
    float soma = 0;

    for(n = 0; n < (*aluno).quantidadeNotas; n++) {
        soma += (*aluno).notas[n];
    }
    return ((int)(soma / (float)(*aluno).quantidadeNotas));
}

int VerificaAprovacao(tAluno *aluno) {
    return (CalculaMediaAluno(aluno) >= 7);
}

void ImprimeAluno(tAluno *aluno) {
    if (VerificaAprovacao(aluno))
        printf("%s\n", (*aluno).nome);
}

void ApagaAluno(tAluno *aluno) {
    if (aluno != NULL){
        if ((*aluno).notas != NULL)
            free((*aluno).notas);
        free(aluno);
    }
    
}