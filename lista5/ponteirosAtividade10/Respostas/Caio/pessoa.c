#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

/**
 * @brief Verifica se a posição de uma pessoa está dentro dos limites de uma lista/vetor/'array' de pessoas;
 * 
 * @param posicao Posicão em que indica que a pessoa está na lista/vetor/'array' de pessoas;
 * @param quantidadePessoas Quantidade de pessoas mna lista/vetor/'array' de pessoas;
 * @return unsigned int 1 (verdadeiro) se a pessoa está em uma posição dentro da lista/vetor/'array' de pessoas ou 0 (caso contrário);
 */
static unsigned int verificaPosicaoLista(int posicao, int quantidadePessoas) {
    return ((posicao > -1) && (posicao < quantidadePessoas));
}

/**
 * @brief Verifica se a pessoa possui irmão(ã);
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 * @return int 1 (verdadeiro) se a pessoa possui irmão(ã) ou 0 (falso), caso contrário;
 */
static unsigned int verificaSeTemIrmaoPessoa(tPessoa *pessoa) {
    return ((*pessoa).irmao != NULL);
}

/**
 * @brief Imprime o nome de uma pessoa
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 */
static void imprimeNome(tPessoa *pessoa) {
    printf("%s\n", (*pessoa).nome);
}


tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa. pai = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa) {
    scanf("\n%[^\n]\n", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    return (((*pessoa).mae != NULL) || ((*pessoa).pai != NULL));
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    return ((((*pessoa1).pai == (*pessoa2).pai) && ((*pessoa1).pai != NULL) && ((*pessoa2).pai != NULL)) || (((*pessoa1).mae == (*pessoa2).mae) && ((*pessoa1).mae != NULL) && ((*pessoa2).mae != NULL)));
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    unsigned int quantidadeAssociacoes, a, p;
    int indiceMae, indicePai, indiceFilho;

    scanf("%d\n", &quantidadeAssociacoes);

    for(a = 0; a < quantidadeAssociacoes; a++) {
        scanf("mae: %d, pai: %d, filho: %d\n", &indiceMae, &indicePai, &indiceFilho);

        if (verificaPosicaoLista(indiceFilho, numPessoas)) {
            if (verificaPosicaoLista(indiceMae, numPessoas))
                (pessoas + indiceFilho)->mae = (pessoas + indiceMae);
            if (verificaPosicaoLista(indicePai, numPessoas))
                (pessoas + indiceFilho)->pai = (pessoas + indicePai);
        }
    }

    for(a = 0; a < numPessoas; a++) {
        for(p = 0; p < numPessoas; p++) {
            if (a == p)
                continue;
            if (VerificaIrmaoPessoa(&pessoas[a], &pessoas[p])) {
                (pessoas + a)->irmao = (pessoas + p);
                break;
            }
        }
    }
}


void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);
        
        printf("PAI: ");
        if ((*pessoa).pai != NULL)
            imprimeNome((*pessoa).pai);
        else
            printf("NAO INFORMADO\n"); 
        
        printf("MAE: ");
        if ((*pessoa).mae != NULL)
            imprimeNome((*pessoa).mae);
        else
            printf("NAO INFORMADO\n"); 

        printf("IRMAO: ");
        if (verificaSeTemIrmaoPessoa(pessoa))
            imprimeNome((*pessoa).irmao);
        else
            printf("NAO INFORMADO\n");   
        
        printf("\n");
    }
}