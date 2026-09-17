#ifndef _TDEPARTAMENTO
#define _TDEPARTAMENTO

#define STRING_MAX 50

typedef struct departamento {
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], diretor[STRING_MAX], nome[STRING_MAX];
    int m1, m2, m3;
}tDepartamento;

/**
 * @brief Cria um departamento;
 * 
 * @param curso1 Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que representa o nome do curso 1 do departamento; 
 * @param curso2 Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que representa o nome do curso 2 do departamento;
 * @param curso3 Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que representa o nome do curso 3 do departamento;
 * @param nome Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que representa o nome do departamento;
 * @param m1 Média das notas do curso 1;
 * @param m2 Média das notas do curso 2;
 * @param m3 Média das notas do curso 3;
 * @param diretor Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que representa o nome do diretor do departamento;
 * @return tDepartamento Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um departamento;
 */
tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor);

/**
 * @brief Ordena os departamentos (na lista/vetor/'array' de departamentos) pela média das notas "médias" de cada um dos cursos (em ordem decrescente);
 * 
 * @param vetor_deptos Ponteiro para o vetor/lista/'array' de Tipos Abstratos de Dados (T.A.D.s) que representa as estruturas que contém as informações dos departamentos (com os dados atualizados);
 * @param num_deptos Número de departamentos na lista/vetor/'array' de departamentos;
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos);

/**
 * @brief Imprime as informações de um departamento;
 * 
 * @param depto Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de um departamento (com os dados atualizados);
 */
void ImprimeAtributosDepartamento(tDepartamento depto);

#endif