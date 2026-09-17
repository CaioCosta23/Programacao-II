#include <stdio.h>
#include <stdlib.h>

#include "departamento.h"

/**
 * @brief Copia uma 'string' para outra;
 * 
 * @param origem Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que será copiada;
 * @param destino Ponteiro para a 'string' (vetor/lista/'array' de caracteres) que receberá a cópia;
 */
static void copiaString(char *origem, char *destino) {
    int posicao = -1;

    do {
        posicao++;
        *(destino + posicao) = *(origem + posicao);
    }while(*(origem + posicao) != '\0');
}

/**
 * @brief Calcula a média da média das notas dos cursos de um departamento;
 * 
 * @param media1 Média das notas do curso 1 de um departamento;
 * @param media2 Média das notas do curso 2 de um departamento;
 * @param media3 Média das notas do curso 3 de um departamento;
 * @return float Média das médias das notas dos cursos de um departamento;
 */
static float calculaMediaNotasDepartamento(int media1, int media2, int media3) {
    const unsigned int numeroMedias = 3;
    
    return (media1 + media2 + media3) / numeroMedias;
}

/**
 * @brief Troca a posição de dois departamentos em um vetor/lista/'array' de departamentos;
 * 
 * @param departamentos Ponteiro para uma lista/vetor/'array' Tipos Abstratos de Dados (T.A.D.s) que representa estruturas com as informações do departamentos (com os dados atualizados);
 * @param indice1 Índice do primeiro departamento no vetor/lista/'array' de departamentos, que será trocado de posição com o outro;
 * @param indice2 Índice do segundo departamento no vetor/lista/'array' de departamentos, que será trocado de posição com o outro;
 */
static void trocaPosicoesDepartamento(tDepartamento *departamentos, int indice1, int indice2) {
    tDepartamento auxiliar;

    auxiliar = *(departamentos + indice1);
    *(departamentos + indice1) = *(departamentos + indice2);
    *(departamentos + indice2) = auxiliar;
}


tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3, int m1, int m2, int m3, char *diretor) {
    tDepartamento departamento;

    copiaString(curso1, departamento.curso1);
    copiaString(curso2, departamento.curso2);
    copiaString(curso3, departamento.curso3);

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;

    copiaString(diretor, departamento.diretor);

    return departamento;
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos) {
    unsigned int d1, d2;

    for (d1 = 0; d1 < (num_deptos - 1); d1++) {
        for (d2 = d1 + 1; d2 < num_deptos; d2++) {
            if (calculaMediaNotasDepartamento((*(vetor_deptos + d1)).m1, (*(vetor_deptos + d1)).m2, (*(vetor_deptos + d1)).m3) < 
                calculaMediaNotasDepartamento((*(vetor_deptos + d2)).m1, (*(vetor_deptos + d2)).m2, (*(vetor_deptos + d2)).m3))
                    trocaPosicoesDepartamento(vetor_deptos, d1, d2);
        }
    }
}

void ImprimeAtributosDepartamento(tDepartamento depto) {
    printf("Departamento: %s\n", depto.nome);
    printf("Diretor: %s\n", depto.diretor);
    printf("1o curso: %s\n", depto.curso1);
    printf("Media do 1o curso: %d\n", depto.m1);
    printf("2o curso: %s\n", depto.curso2);
    printf("Media do 2o curso: %d\n", depto.m2);
    printf("3o curso: %s\n", depto.curso3);
    printf("Media do 3o curso: %d\n", depto.m3);
}