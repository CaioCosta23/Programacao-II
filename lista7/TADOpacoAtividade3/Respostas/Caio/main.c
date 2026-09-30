#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"

#define CADASTRAR  "Cadastrar"
#define ALUGAR "Alugar"
#define DEVOLVER "Devolver"
#define CONSULTAR_ESTOQUE "Estoque"

/**
 * @brief Compara duas 'string's (vetores/listas/'array's de caracteres) e verifica se as duas são iguais;
 * 
 * @param string1 Primeira 'string' (vetor/lista/'array' de caracteres) a ser comparada com a outra;
 * @param string2 Segunda 'string' (vetor/lista/'array' de caracteres) a ser comparada com a outra;
 * @return unsigned short int 1 (verdadeiro) se as duas strings forem iguais ou 0 (falso), cso contrário;
 */
static unsigned short int ComparaStrings(char string1[], char string2[]){
    unsigned int posicao = 0;
    unsigned short int iguais = 1;

    while(string1[posicao] != '\0') {
        if (string1[posicao] != string2[posicao]) {
            iguais = 0;
            break;
        }
        posicao++;
    }
    return iguais;
}

/**
 * @brief Programa que simula uma locadora;
 * 
 * @return int Programa principal;
 */
int main () {
    tLocadora * locadora;
    char operacao[MAX_CARACTERES];

    locadora = CriarLocadora();

    while(scanf("%s\n", operacao) == 1){
        if (ComparaStrings(operacao, CADASTRAR))
            LerCadastroLocadora(locadora);
        else if (ComparaStrings(operacao, ALUGAR))
            LerAluguelLocadora(locadora);
        else if (ComparaStrings(operacao, DEVOLVER))
            LerDevolucaoLocadora(locadora);
        else if (ComparaStrings(operacao, CONSULTAR_ESTOQUE))
            ConsultarEstoqueLocadora(locadora);
        scanf("%*[^\n]\n");
    }
    ConsultarLucroLocadora(locadora);

    DestruirLocadora(locadora);

    return 0;
}