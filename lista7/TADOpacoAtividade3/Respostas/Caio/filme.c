#include <stdio.h>
#include <stdlib.h>

#include "filme.h"

struct Filme {
    char nome[MAX_CARACTERES];
    int codigo;
    unsigned int quantidadeEstoque, quantidadeAlugada;
    float valor;
};

tFilme *CriaFilme() {
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

    scanf("%s,%d,%d\n", filme->nome, &filme->valor, &filme->quantidadeEstoque);
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

int ObtemQtdAlugadaFilme(tFilme *filme) {
    return (*filme).quantidadeAlugada;
}

int EhMesmoCodigoFilme(tFilme *filme, int codigo) {
    return (ObterCodigoFilme(filme) == codigo);
}

void AlugaFilme(tFilme *filme) {
    filme->quantidadeAlugada++;
    filme->quantidadeEstoque--;
}

void DevolveFilme(tFilme *filme) {
    filme->quantidadeAlugada--;
    filme->quantidadeEstoque++;
}

int CompararNomesFilmes(tFilme *filme1, tFilme *filme2) {
    return ComparaStrings((*filme1).nome, (*filme2).nome);
}

void ImprimeNomeFilme(tFilme *filme) {
    printf("%s\n", (*filme).nome);
}

void DestruirFilme(tFilme *filme) {
    if (filme != NULL)
        free(filme);    
}