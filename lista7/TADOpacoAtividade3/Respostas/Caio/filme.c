#include <stdio.h>
#include <stdlib.h>

#include "filme.h"

struct Filme {
    char nome[MAX_CARACTERES];
    int codigo;
    unsigned int quantidadeEstoque, quantidadeAlugada;
    float valor;
};


/**
 * @brief Compara duas 'strings' (lista/vetor/'array') de caracteres e indica qual é a maior (qual vem depois na ordem alfabética);
 * 
 * @param string1 Primeira 'string' (lista/vetor/'array') de caracteres que será comparada com outra;
 * @param string2 Segunda 'string' (lista/vetor/'array') de caracteres que será comparada com outra;
 * @return short int 1 Se a primeira string for maior (ou vier depois na ordem alfabética) que a primeira, -1 se a segunda for maior (ou vir depois na ordem alfabética) que a primeira ou 0 caso as duas 'string's sejam iguais;
 */
static short int ComparaStrings(char string1[], char string2[]) {
    short int contador = -1;
    short int resultado = 0; // variável lógica;

    do {
        contador++;

        if (string1[contador] > string2[contador])
            resultado = 1;
        else if (string1[contador] < string2[contador])
        resultado = -1;    
    } while((string1[contador] == string2[contador]) && ((string1[contador] != '0') && (string2[contador] != '\0')) && (contador < MAX_CARACTERES));

    return resultado;
}

tFilme *CriarFilme() {
    tFilme *filme = NULL;

    filme = (tFilme*)malloc(sizeof(tFilme));

    if (filme == NULL) {
        printf("Erro! Alocacao de memoria do filme mal-sucedida.\n");
        exit(1);
    }

    unsigned short int c;

    for(c = 0; c < MAX_CARACTERES; c++) {
        filme->nome[c] = '\0';
    }
    filme->codigo = -1;
    filme->quantidadeAlugada = 0;
    filme->quantidadeEstoque = 0;
    filme->valor = 0;

    return filme;
}


void LeFilme(tFilme *filme, int codigo) {
    filme->codigo = codigo;

    scanf("%[^,],%f,%d\n", filme->nome, &filme->valor, &filme->quantidadeEstoque);
}

int ObterCodigoFilme(tFilme *filme) {
    return (*filme).codigo;
}

int ObterValorFilme(tFilme *filme) {
    return (int)(*filme).valor;
}

int ObterQtdEstoqueFilme(tFilme *filme) {
    return (*filme).quantidadeEstoque;
}

int ObterQtdAlugadaFilme(tFilme *filme) {
    return (*filme).quantidadeAlugada;
}

int EhMesmoCodigoFilme(tFilme *filme, int codigo) {
    return (ObterCodigoFilme(filme) == codigo);
}

void AlugarFilme(tFilme *filme) {
    filme->quantidadeAlugada++;
    filme->quantidadeEstoque--;
}

void DevolverFilme(tFilme *filme) {
    filme->quantidadeAlugada--;
    filme->quantidadeEstoque++;
}

int CompararNomesFilmes(tFilme *filme1, tFilme *filme2) {
    return ComparaStrings((*filme1).nome, (*filme2).nome);
}

void ImprimirNomeFilme(tFilme *filme) {
    printf("%s", (*filme).nome);
}

void DestruirFilme(tFilme *filme) {
    if (filme != NULL)
        free(filme);    
}