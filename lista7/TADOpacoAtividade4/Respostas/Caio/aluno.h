#ifndef _ALUNO_H_
#define _ALUNO_H_

typedef struct Aluno tAluno;

/**
 * @brief Cria (aloca a memória dinamicamente de) um aluno;
 * 
 * @return tAluno* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um aluno;
 */
tAluno *CriaAluno();

/**
 * @brief Lê os dados de um aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um aluno;
 */
void LeAluno(tAluno *aluno);

/**
 * @brief Compara a matrícula de dois alunos;
 * 
 * @param aluno1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) do primeiro aluno a ter a matrícula comparada com a matrícula do segundo aluno;
 * @param aluno2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) do segundo aluno a ter a matrícula comparada com a matrícula do primeiro aluno;
 * @return int 1 se a matrícula do primeiro aluno for maior que a matrícula do segundo,
 * -1 se a matrícula do segundo aluno for maior que a matrícula do primeiro ou 0 caso as matriculas dos alunos seeejam iguais;
 */
int ComparaMatricula(tAluno *aluno1, tAluno *aluno2);

/**
 * @brief Calcula a méida das notas do aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um aluno;
 * @return int Valor da média das notas do aluno;
 */
int CalculaMediaAluno(tAluno *aluno);

/**
 * @brief Verifica se um aluno foi ou não aprovado;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um aluno;
 * @return int 1 (verdadeiro) se o aluno estiver aprovado ou 0 (falso), caso contrário;
 * @OBS: O aluno estará aprovado se a m´´´edia de suas notas for maior ou igual à 7;
 */
int VerificaAprovacao(tAluno *aluno);

/**
 * @brief Imprime oos dados do aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um aluno;
 */
void ImprimeAluno(tAluno *aluno);

/**
 * @brief Apaga (libera/desaloca a mem´oriaaa dinamicamente de) um aluno;
 * 
 * @param aluno Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um aluno;
 */
void ApagaAluno(tAluno *aluno);

#endif