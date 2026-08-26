#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

// Função auxiliar para copiar um nome (apenas para não utilizar a biblioteca <string.h> com a função strcpy(destino, origem), que tanbém copia uma string para outra);
static void copiaNome(tAluno aluno, char nome[]) {
    unsigned int indice = 0;

    do {
        aluno.nome[indice] = nome[indice];
        indice++;
    }while(nome[indice] != 0);
}

tAluno CriaAluno(char nome[], int matricula, int n1, int n2, int n3) {
    tAluno aluno;

    copiaNome(aluno, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno() {
    tAluno aluno;

    const unsigned short int tamanhoNome = 50;

    char nome[tamanhoNome];
    int matricula;
    unsigned short int n1, n2, n3;

    scanf("%49s\n", nome);
    scanf("%d\n", &matricula);
    scanf("%hd %hd %hd\n", &n1, &n2, &n3);

    aluno = CriaAluno(nome, matricula, n1, n2, n3);

    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    else if (aluno2.matricula > aluno1.matricula)
        return -1;
    
    return 0;
}

int calculaMediaAluno(tAluno aluno) {
    const unsigned int quantidadeNotas = 3;
    
    return (aluno.n1 + aluno.n2 + aluno.n3) / quantidadeNotas;
}

int VerificaAprovacaoAluno(tAluno aluno) {
    const unsigned short int mediaAprovacao = 7;

    if (calculaMediaAluno(aluno) >= mediaAprovacao)
        return 1;
    
    return 0;
}

void imprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}