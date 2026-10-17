#include <stdio.h>
#include <stdlib.h>

#include "relatorio.h"

#include "aluno.h"


#define MASCULINO 'M'
#define FEMININO 'F'
#define OUTROS 'O'

#define MEDIA 7

/**
 * @brief Obtém a média das notas dos alunos;
 * 
 * @param vetor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura do tipo vetor que contém as informações (dados atualizados) da lista de alunos;
 * @return float Média dos alunos;
 */
static float calculaMediaNotasAlunos(Vector *vetor) {
    unsigned int a, tamanhoVetor;
    float media = 0;

    tamanhoVetor = VectorSize(vetor);

    for (a = 0; a < tamanhoVetor; a++)
        media += GetNotaAluno((tAluno*)VectorGet(vetor, a));

    return (media / tamanhoVetor);
}

/**
 * @brief Obtém a quantidade de alunos (de um determinado gênero) que foram aprovados;
 * 
 * @param vetor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura do tipo vetor que contém as informações (dados atualizados) da lista de alunos;
 * @param genero Gênero dos alunos que serão verificados seestão ou não aprovados;
 * @return unsigned int Quantidade de alunos (de um determinado gênero) que foram aprovados;
 */
static unsigned int quantidadeAlunosAprovados(Vector *vetor, char genero) {
    unsigned int a, tamanhoVetor;
    unsigned int aprovados = 0;
    tAluno *aluno;

    tamanhoVetor = VectorSize(vetor);

    for (a = 0; a < tamanhoVetor; a++)
        aluno = (tAluno*)VectorGet(vetor, a);

        if (GetGeneroAluno(aluno) == genero)
            if (GetNotaAluno(aluno) >= MEDIA)
                aprovados += 1;

    return aprovados;
}


void ImprimeRelatorio(Vector *alunos) {
    float mediaNotas;
    unsigned int quantidadeAlunos, quantidadeAprovacoesMasculinas, quantidadeAprovacoesFemininas, quantidadeAprovacoesOutros;

    mediaNotas = calculaMediaNotasAlunos(alunos);
    quantidadeAlunos = VectorSize(alunos);
    quantidadeAprovacoesMasculinas = quantidadeAlunosAprovados(alunos, MASCULINO);
    quantidadeAprovacoesFemininas = quantidadeAlunosAprovados(alunos, FEMININO);
    quantidadeAprovacoesOutros = quantidadeAlunosAprovados(alunos, OUTROS);

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (((quantidadeAprovacoesMasculinas + quantidadeAprovacoesFemininas + quantidadeAprovacoesOutros) / quantidadeAlunos) * 100));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", ((quantidadeAprovacoesMasculinas / quantidadeAlunos) * 100));
    printf("Feminino: %.2f%%\n", ((quantidadeAprovacoesFemininas / quantidadeAlunos) * 100));
    printf("Outro: %.2f%%\n", ((quantidadeAprovacoesOutros / quantidadeAlunos) * 100));
}