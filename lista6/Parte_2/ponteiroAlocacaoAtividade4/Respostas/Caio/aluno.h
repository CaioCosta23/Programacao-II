#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno {
    char *nome;
    int matricula, n1, n2, n3;
}tAluno;

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @return tAluno* Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados inicializados) de um aluno;
 */
tAluno *CriaAluno();

/**
 * @brief Lê as informações (dados) de um aluno
 * 
 * @param aluno Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados à serem lidos) de um aluno;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara a matrícula de um aluno com outro;
 * 
 * @param aluno1 Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do primeiro aluno que terá sua matrícula comparada com a matrícula do segundo aluno;
 * @param aluno2 Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do segundo aluno que terá sua matrícula comparada com a matrícula do primeiro aluno;
 * @return int 1 se a matricula do primeiro aluno for maior que a matrícula do segundo ou -1 se a matrícula do segundo for maior que a do primeiro ou 0 caso matrícula dos alunos sejam iguais;
 */
int ComparaMatricula(tAluno *aluno1, tAluno *aluno2);

/**
 * @brief Calcula média das notas de um aluno
 * 
 * @param aluno Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do aluno;
 * @return int Média (valor inteiro arredondado) das notas dos alunos;
 */
int CalculaMediaAluno(tAluno *aluno);

/**
 * @brief Verifica se um aluno foi aprovado (se a média das notas do mesmo é maior ou igual a média geral necessária para aprovação);
 * 
 * @param aluno Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do aluno;
 * @return int 1 (verdadeiro) se o aluno foi aprovado ou 0 (falso), caso contrário;
 */
int VerificaAprovacao(tAluno *aluno);

/**
 * @brief Imprime as informações de um aluno;
 * 
 * @param aluno Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do aluno;
 */
void ImprimeAluno(tAluno *aluno);

/**
 * @brief Apaga (libera/desaloca a memória dinamicamente de) um aluno;
 * 
 * @param aluno Ponteiro para o Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (dados atualizados) do aluno;
 */
void ApagaAluno(tAluno *aluno);

#endif