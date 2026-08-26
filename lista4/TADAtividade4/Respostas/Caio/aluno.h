#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno {
    char nome[50];
    int matricula, n1, n2, n3;
} tAluno;

/**
 * @brief 
 * 
 * @param nome Nome do aluno;
 * @param matricula Número (ou ID - Identificador) da matrícula do aluno;
 * @param n1 Nota 1 do aluno;
 * @param n2 Nota 2 do aluno;
 * @param n3 Nota 3 do aluno;
 * @return tAluno Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados aluno;
 */
tAluno CriaAluno(char nome[], int matricula, int n1, int n2, int n3);

/**
 * @brief Lê os dados de um aluno;
 * 
 * @return tAluno Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados aluno inicializados com os dados lidos;
 */
tAluno LeAluno();

/**
 * @brief Compara as matrículas de dois alunos;
 * 
 * @param aluno1 Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados do primeiro aluno a ser comparado;
 * @param aluno2 Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados do segundo aluno a ser comparado;
 * @return int 1 se a matrícula do primeiro aluno for maior que a do segundo, -1 se a matrícula do segundo aluno for maior que a do primeiro aluno ou 0 caso a matrícula dos dois seja igual;
 */
int ComparaMatricula(tAluno aluno1, tAluno aluno2);

/**
 * @brief Calcula a média das notas de um aluno;
 * 
 * @param aluno Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados do aluno que terá sua médiade notas calculada;
 * @return int Valor da média das notas e um aluno;
 */
int calculaMediaAluno(tAluno aluno);

/**
 * @brief Verifica se um aluno está aprovado ou não;
 * 
 * @param aluno Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados do aluno a ser verifcada a aprovação;
 * @return int 1 (verdadeiro) se o aluno foi aprovado ou 0 (falso), caso contrário;
 */
int VerificaAprovacaoAluno(tAluno aluno);

/**
 * @brief Imprime os dados de um aluno;
 * 
 * @param aluno Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados do aluno;
 */
void imprimeAluno(tAluno aluno);

#endif