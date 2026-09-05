#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "departamento.h"

/**
 * @brief Copia uma o conteúdo de uma 'string' (lista/vetor/'array' de caracteres) para outra (lista/vetor/'array' de caracteres) 
 * 
 * @param origem Vetor/lista/aarray de caracteres de onde será copiada a 'string';
 * @param destino Vetor/lista/array de caracteres para onde será copiada a string;
 */
static void copiaString(char origem[], char destino[]) {
    unsigned short int indice = 0;

    while(1) {
        destino[indice] = origem[indice];

        if (origem[indice] == '\0')
            break;

        indice++;
    }
}

/**
 * @brief Troca dois itens de uma lista de lugar;
 * 
 * @param lista Lista/vetor/'array' de Tipos Abstratos de Dados (T.A.D.s) que representam estruturas que contém os dados (atualizados) dos departamentos;
 * @param indice1 Índice do primeiro item (departamento) dentro da lista/vetor/'array';
 * @param indice2 Índice do segundo item (departamento) dentro da lista/vetor/'array';
 */
static void trocaPosicoes(tDepartamento lista[], int indice1, int indice2) {
    tDepartamento auxiliar;

    auxiliar = lista[indice1];
    lista[indice1] = lista[indice2];
    lista[indice2] = auxiliar;
}

tDepartamento criaDepartamento(char c1[], char c2[], char c3[], char nome[], int m1, int m2, int m3, char diretor[]) {
    tDepartamento departamento;
    
    copiaString(c1, departamento.c1);
    copiaString(c2, departamento.c2);
    copiaString(c3, departamento.c3);
    copiaString(nome, departamento.nome);
    copiaString(diretor, departamento.diretor);

    if (validaMediaDepartamento(m1))
        departamento.m1 = m1;
    else
        departamento.m1 = 0;
    
    if (validaMediaDepartamento(m2))
        departamento.m2 = m2;
    else
        departamento.m2 = 0;
    
    if (validaMediaDepartamento(m3))
        departamento.m3 = m3;
    else
        departamento.m3 = 0;

    return departamento;
}

int validaMediaDepartamento(int media) {
    return ((media >= 0) && (media <= 10));
}

double calculaDesvioPadraoDepartamento(tDepartamento depto) {
    double media;
    const unsigned short int quantidadeCursos = 3;

    media = calculaMediaGeralDepartamento(depto);

    return sqrt(((pow(((double)depto.m1 - media), 2)) + (pow(((double)depto.m2 - media), 2)) + (pow(((double)depto.m3 - media), 2))) / quantidadeCursos);
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
    const unsigned short int quantidadeCursos = 3;

    return ((double)depto.m1 + (double)depto.m2 +(double)depto.m3) / quantidadeCursos;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
    int d1, d2;
    double mediaReferencia;

    for(d1 = 0; d1 < tamanho - 1; d1++) {
        mediaReferencia = calculaMediaGeralDepartamento(d[d1]);
        for(d2 = d1 + 1; d2 < tamanho; d2++) {
            if (mediaReferencia < calculaMediaGeralDepartamento(d[d2]))
                trocaPosicoes(d, d1, d2);
        }
    }
}

void imprimeAtributosDepartamento(tDepartamento depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2lf\n", calculaMediaGeralDepartamento(depto));
    printf("desvio padrao => %.2lf\n", calculaDesvioPadraoDepartamento(depto));

    printf("\n");
}