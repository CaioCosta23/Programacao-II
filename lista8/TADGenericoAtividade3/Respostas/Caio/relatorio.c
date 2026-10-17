#include <stdio.h>
#include <stdlib.h>

#include "relatorio.h"

#include "aluno.h"


#define MASCULINO 'M'
#define FEMININO 'F'
#define OUTROS 'O'

#define MEDIA 6

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
 * @brief Obtém a quantidadede alunos aprovados;
 * 
 * @param vetor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura do tipo vetor que contém as informações (dados atualizados) da lista de alunos;
 * @return unsigned int Quantidade de alunos aprovados;
 */
static unsigned int quantidadeAlunosAprovados(Vector *vetor) {
    unsigned int a;
    unsigned int aprovados = 0;

    for (a = 0; a < VectorSize(vetor); a++) 
        if (GetNotaAluno((tAluno*)VectorGet(vetor, a)) >= MEDIA)
            aprovados += 1;
    
    return aprovados;
}

/**
 * @brief Obtém a quantidade de alunos de um determinado gênero;
 * 
 * @param vetor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura do tipo vetor que contém as informações (dados atualizados) da lista de alunos;
 * @param genero Gênero dos alunos dos alunos a serem contabilizados;
 * @return unsigned int Quantidade de alunos de um determinado gênero;
 */
static unsigned int quantidadeAlunosPorGenero(Vector *vetor, char genero) {
    unsigned int a;
    unsigned int alunos = 0;

    for (a = 0; a < VectorSize(vetor); a++) 
        if (GetGeneroAluno((tAluno*)VectorGet(vetor, a)) == genero)
            alunos += 1;
    
    return alunos;
}


void ImprimeRelatorio(Vector *alunos) {
    float mediaNotas;
    unsigned int quantidadeTotalAlunos, quantidadeAlunosMasculinos, quantidadeAlunosFemininas;
    float porcentagemAlunosMasculinos, porcentagemAlunasFemininas;

    mediaNotas = calculaMediaNotasAlunos(alunos);
    quantidadeTotalAlunos = VectorSize(alunos);
    porcentagemAlunosMasculinos = ((float)quantidadeAlunosPorGenero(alunos, MASCULINO) / (float)quantidadeTotalAlunos) * (float)100;
    porcentagemAlunasFemininas = ((float)quantidadeAlunosPorGenero(alunos, FEMININO) / (float)quantidadeTotalAlunos) * (float)100;

    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (((float)quantidadeAlunosAprovados(alunos) / (float)quantidadeTotalAlunos) * (float)100));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", porcentagemAlunosMasculinos);
    printf("Feminino: %.2f%%\n", porcentagemAlunasFemininas);
    printf("Outro: %.2f%%\n", ((float)100 - porcentagemAlunosMasculinos - porcentagemAlunasFemininas));
}