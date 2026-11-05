#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"

#define MAXIMO_CARACTERES_OPCAO 10

#define CADASTRAR "Cadastrar"
#define ALUGAR "Alugar"
#define DEVOLVER "Devolver"
#define ESTOQUE "Estoque"

/**
 * @brief Contabiliza a quantidade de caracteres que uma palavra possui;
 * 
 * @param palavra Palavra (lista/vetor/'array' de caracteres) que terá a quantidade de caracteres contabilizada;
 * @return unsigned int Quantidade de caracteres da palavra (lista/vetor/'array' de caracteres);
 */
static unsigned int contabilizaTamanhoPalavra(char palavra[]) {
    unsigned int contador = 0;

    while(palavra[contador++] != '\0');

    return contador;
}

/**
 * @brief Compara duas palavras (lista/vetor/'array' de caracteres);
 * 
 * @param opcao Palavra digitada como opção de entrada que será comparada com uma das palavras são base de escolha do programa;
 * @param base Palavra base de escolha do programa que será comparada com a opção digitada;
 * @return unsigned short int 1 (verdadeiro) se as palavras (lista/vetor/'array') de caracteres for igual ou 0 (falso), caso contrário;
 */
static unsigned short int comparaOpcoes(char opcao[], char base[]) {
    unsigned int contador = 0;

    if (contabilizaTamanhoPalavra(opcao) != contabilizaTamanhoPalavra(base))
        return 0;

    while(opcao[contador] != '\0') {
        if ((opcao[contador] != base[contador]))
            return 0;
        contador++;
    }
    return 1;
}


/**
 * @brief Programa que simula o funcionamento de uma locadora;
 * 
 * @return int Programa principal;
 */
int main() {
    tLocadora *locadora;
    char opcao[MAXIMO_CARACTERES_OPCAO];

    locadora = CriarLocadora();
    
    while(scanf("%s\n", opcao) == 1) {
        if (comparaOpcoes(opcao, CADASTRAR)) {
            LerCadastroLocadora(locadora);
            printf("\n");
        }else if (comparaOpcoes(opcao, ALUGAR)) {
            LerAluguelLocadora(locadora);
            printf("\n");
        }else if (comparaOpcoes(opcao, DEVOLVER)) {
            LerDevolucaoLocadora(locadora);
            printf("\n");
        }else if (comparaOpcoes(opcao, ESTOQUE)) {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            printf("\n");
        }else {
            printf("Entrada/Formato invalido!\n");
        }
        scanf("%*[^\n]\n");
    }

    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}