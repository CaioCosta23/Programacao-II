#ifndef _depto
#define _depto

#define STRING_MAX 101

typedef struct Departamento {
    char nome[STRING_MAX], c1[STRING_MAX],c2[STRING_MAX], c3[STRING_MAX], diretor[STRING_MAX];
    int m1, m2,m3;
    float media_geral;
}tDepartamento;


/**
 * @brief Cria um departamento com dados inicializados;
 * 
 * @param c1 Nome do curso 1 do departamento;
 * @param c2 Nome do curso 2 do departamento;
 * @param c3 Nome do curso 3 do departamento;
 * @param nome Nome do departamento;
 * @param m1 Média do curso 1 do departamento;
 * @param m2 Média do curso 2 do departamento;
 * @param m3 Média do curso 3 do departamento;
 * @param diretor Nome do diretor do departamento;
 * @return tDepartamento Tipo Abstrato de Dados (T.A.D.) que representa a estrutura com os dados do departamento com informações inicializadas; 
 */
tDepartamento criaDepartamento(char c1[], char c2[], char c3[], char nome[STRING_MAX], int m1, int m2, int m3, char diretor[]);

/**
 * @brief Verifica se a média de um departamento tem valor válido;
 * 
 * @param media Média de um departamento;
 * @return int 1 (verdadeiro) se a média for válida ou 0 (falso), caos contrário;
 */
int valorMediaDepartamento(int media);

/**
 * @brief Calcula o desvio padrão da média das notas de um departamento;
 * 
 * @param depto Tipo Abstrato de Dados (T.A.D.) que representa a estrutura de dados que contém as informações de um departamento;
 * @return double Valor do desvio padrão das médias de um departamento;
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto);

/**
 * @brief Calcula a média das notas do departamento;
 * 
 * @param depto Tipo Abstrato de Dados (T.A.D.) que representa a estrutura de dados que contém as informações de um departamento;
 * @return double Média (geral) das notas do departamento;
 */
double calculaMediaGeralDepartamento(tDepartamento depto);

/**
 * @brief Ordena uma lista/vetor/array de departamentos em ordem decrescente pelas médias de cada departamento;
 * 
 * @param d Lista/vetor/array de Tipos Abstratos de Dados (T.A.D.s) que representam uma lista de estruturas de dados que contém as informações de departamentos;
 * @param tamanho Tamanho da lista/vetor/array de departamentos;
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho);

/**
 * @brief Imprime as informações de um departamento;
 * 
 * @param depto Tipo Abstrato de Dados (T.A.D.) que representa a estrutura de dados que contém as informações de um departamento;
 */
void imprimeAtributosDepartamento(tDepartamento depto);

#endif