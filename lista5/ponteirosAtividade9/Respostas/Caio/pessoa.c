#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

/**
 * @brief Imprime o nome de uma pessoa;
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
    pessoa.pai = NULL;

    return pessoa;
}


void LePessoa(tPessoa *pessoa) {
    scanf("\n%[^\n]\n", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa) {
    return (((*pessoa).pai != NULL) || ((*pessoa).mae != NULL));
}


void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {
    int quantidadeAssociacoes, a, indiceMae, indicePai, indiceFilho;

    scanf("%d\n", &quantidadeAssociacoes);

    for(a = 0; a < quantidadeAssociacoes; a++) {
        scanf("mae: %d, pai: %d, filho: %d\n", &indiceMae, &indicePai, &indiceFilho);

        if (indiceFilho > -1) {
            if (indiceMae > -1)
                (*(pessoas + indiceFilho)).mae = (pessoas + indiceMae);
            
            if (indicePai > -1)
                (*(pessoas + indiceFilho)).pai = (pessoas + indicePai);
        }
    }
}


void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: ");
        imprimeNome(pessoa);

        if ((*pessoa).pai != NULL) {
            printf("PAI: ");
            imprimeNome((*pessoa).pai);
        }else {
            printf("PAI: NAO INFORMADO\n");
        }
        if ((*pessoa).mae != NULL) {
            printf("MAE: ");
            imprimeNome((*pessoa).mae);
        }else {
            printf("MAE: NAO INFORMADO\n");
        }
        printf("\n");
    }
}