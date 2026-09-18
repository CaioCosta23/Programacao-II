#include <stdio.h>
#include <stdlib.h>

#include "pessoa.h"

/**
 * @brief Verifica se uma pessoa existe no vetor/lista/'array' de pessoas;
 * 
 * @param indicePessoa Índice da posição da pessoa na llista/vetor/'array' de pessoas;
 * @return unsigned short int 1(verdadeiro) se a pesoa existir dentro da lista/vetor/'array' de pessoas ou 0 (falso), caso contrário;
 * 
 * @OBS: O código do arquivo em si, sempre irá supor que o índice nunca será maior que o tamanho da lista/vetor/'array' de pessoas;
 */
static unsigned short int verificaExistenciaPessoa(unsigned int indicePessoa) {
    return (indicePessoa > -1);
}

/**
 * @brief Imprime o nome de uma pessoa;
 * 
 * @param pessoa Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações de uma pessoa (com os dados atualizados);
 */
static void imprimeNome(tPessoa *pessoa) {
    printf("%s", (*pessoa).nome);
}

tPessoa CriaPessoa() {
    tPessoa pessoa;
    
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;

    return pessoa;
}


void LePessoa(tPessoa *pessoa) {
    scanf("%[^\n]\n", pessoa->nome);
}

int VerificaSeTemPaiPessoa(tPessoa *pessoa) {
    return (((*pessoa).pai != NULL) || ((*pessoa).mae != NULL));
}


void AssociaFamiliasGrupoPessoas(tPessoa *pessoas) {
    int unsigned indiceMae, indicePai, indiceFilho;

    scanf("mae: %d, pai: %d, filho: %d\n", &indiceMae, &indicePai, &indiceFilho);

    if (verificaExistenciaPessoa(indiceMae))
        (*(pessoas + indiceFilho)).mae = (pessoas + indiceMae);
    if (verificaExistenciaPessoa(indicePai))
        (*(pessoas + indiceFilho)).pai = (pessoas + indicePai);
}


void ImprimePessoa(tPessoa *pessoa) {
    if (VerificaSeTemPaiPessoa(pessoa)){
        printf("NOME COMPLETO: ");
        imprimeNome(pessoa);

        if ((*pessoa).pai != NULL) {
            printf("PAI: ");
            imprimeNome((*pessoa).pai);
        }
        if ((*pessoa).mae != NULL) {
            printf("MAE: ");
            imprimeNome((*pessoa).mae);
        }
    }
}