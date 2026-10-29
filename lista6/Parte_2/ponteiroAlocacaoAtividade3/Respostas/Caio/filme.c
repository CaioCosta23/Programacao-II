#include <stdio.h>
#include <stdlib.h>

#include "filme.h"

/**
 * @brief Verifica se um caractere é uma letra maiúscula;
 * 
 * @param caractere Caractere que será analisado;
 * @return unsigned short int 1 (verdadeiro) se o caractere é uma letra maiúscula ou 0 (falso), caso contrário;
 */
static unsigned short int verificaLetraMaiuscula(char caractere) {
    return ((caractere >= 'A') && (caractere <= 'Z'));
}

/**
 * @brief Verifca se um caractere é uma letra minúscula;
 * 
 * @param caractere Caractere que será analisado;
 * @return unsigned short int 1 (verdadeiro) se o caractere for uma letra minúscula ou 0 (falso), caso contrário;
 */
static unsigned short int verificaLetraMinuscula(char caractere) {
    return ((caractere >= 'a') && (caractere <= 'z'));
}

/**
 * @brief Verifica se um caractere é uma letra;
 * 
 * @param caractere Caractere que será verificado;
 * @return unsigned short int 1 (verdadeiro) se o caractere for uma letra ou 0 (falso), caso contrário;
 */
static unsigned short int verificaLetra(char caractere) {
    return ((verificaLetraMaiuscula(caractere)) || (verificaLetraMinuscula(caractere)));
}

/**
 * @brief Transforma um caractere que é uma letra maiúscula em uma letra minúscula;
 * 
 * @param letra Letra maiúscula que será transformada em uma letra minúscula;
 * @return char Letra maiúscula que será transformada em letra minúscula;
 */
static char transformaEmLetraMinuscula(char letra) {
    const unsigned short int DISTANCIA_ASCII = 32;

    return (letra + DISTANCIA_ASCII);
}

tFilme *CriarFilme() {
    tFilme *filme = NULL;

    filme = (tFilme*)malloc(sizeof(tFilme));

    if (filme == NULL) {
        printf("Erro! Alocacao de memoria de filme mal-sucedida.\n");
        exit(1);
    }

    filme->codigo = -1;
    filme->qtdAlugada = 0;
    filme->qtdEstoque = 0;
    filme->valor = 0;

    return filme;
}

void LeFilme(tFilme *filme, int codigo) {
    filme->codigo = codigo;
    
    scanf("%[^,],%d,%d\n", filme->nome, &filme->valor, &filme->qtdEstoque);
}

int ObterCodigoFilme(tFilme *filme) {
    return (*filme).codigo;
}

int ObterQtdEstoqueFilme(tFilme *filme) {
    return (*filme).qtdEstoque;
}

int ObterQtdAlugadaFilme(tFilme *filme) {
    return (*filme).qtdAlugada;
}

int ObterValorFilme(tFilme *filme) {
    return (*filme).valor;
}

int EhMesmoCodigoFilme(tFilme *filme, int codigo){
    return ((*filme).codigo == codigo);
}

int CompararNomesFilmes(tFilme *filme1, tFilme *filme2) {
    unsigned int tamanhoNomeFilme1, tamanhoNomeFilme2;
    unsigned int contador = 0;
    unsigned short int caractereVerificadoNome1, caractereVerificadoNome2; // Variável lógica para armazenar o reusltado da verificação se o caractere é uma letra ou não;

    while(((*filme1).nome[contador] != '\0') && ((*filme2).nome[contador] != '\0')) {
        caractereVerificadoNome1 = 0;
        caractereVerificadoNome2 = 0;

        if (verificaLetra((*filme1).nome[contador]))
            caractereVerificadoNome1 = 1;
        if (verificaLetra((*filme2).nome[contador]))
            caractereVerificadoNome2 = 1;

        if ((caractereVerificadoNome1) && (!(caractereVerificadoNome2))) {
            return 1;
        }else if ((!(caractereVerificadoNome1)) && (caractereVerificadoNome2)) {
            return -1;
        }else if ((!(caractereVerificadoNome1)) && (!caractereVerificadoNome2)) {
            if ((*filme1).nome[contador] > (*filme2).nome[contador])
                return 1;
            else if ((*filme1).nome[contador] < (*filme2).nome[contador])
                return -1;
        }else {
            char letraNome1, letraNome2;

            letraNome1 = (*filme1).nome[contador];
            letraNome2 = (*filme2).nome[contador];

            if (verificaLetraMaiuscula(letraNome1))
                letraNome1 = transformaEmLetraMinuscula(letraNome1);
            if (verificaLetraMaiuscula(letraNome2))
                letraNome2 = transformaEmLetraMinuscula(letraNome2);

            if (letraNome1 > letraNome2)
                return 1;
            else if (letraNome1 < letraNome2)
                return -1;
        }
        contador++;
    }

    if (((*filme1).nome[contador] == '\0') && ((*filme2).nome[contador] == '\0')) {
        return 0;
    }else {
        if ((*filme1).nome[contador] == '\0')
            return 1;
        else
            return -1;
    }
}

void AlugarFilme(tFilme *filme) {
    filme->qtdAlugada += 1;
    filme->qtdEstoque -= 1;
}

void DevolverFilme(tFilme *filme) {
    filme->qtdEstoque += 1;
    filme->qtdAlugada -= 1;
}

void ImprimirNomeFilme(tFilme *filme) {
    printf("%s", (*filme).nome);
}

void DestruirFilme(tFilme *filme) {
    if (filme != NULL) 
        free(filme);
}