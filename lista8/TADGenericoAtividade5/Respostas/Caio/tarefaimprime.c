#include <stdio.h>
#include <stdlib.h>

#include "tarefaimprime.h"

struct impr {
    char *mensagem;
};

/**
 * @brief Obtém o tamanho de uma mensagem (lista/vetor/'array' de caracteres);
 * 
 * @param mensagem (Ponteiro para) Lista/Vetor/'Array' de caracteres;
 * @return unsigned int Tamanho da mensagem(lista/vetor/'array' de caracteres);
 */
static unsigned int obtemTamanhoMensagem(char * mensagem) {
    unsigned int contador = 0;

    while(mensagem[contador] != '\0')
        contador++;

    return contador;
}

/**
 * @brief Copia uma mensagem de uma lista/vetor/'array' de caracteres para outro;
 * 
 * @param origem (Ponteiro para) Lista/Vetor/'Array' de caracteres de origem, de onde será copiada a mensagem;
 * @param destino (Ponteiro para) Lista/Vetor/'Array' de caracteres de destino, para onde será copiada a mensgaem;
 */
static void copiaMensagem(char *origem, char *destino) {
    unsigned int contador = 0;

    while(origem[contador] != '\0'){
        destino[contador] = origem[contador];
        contador++;
    }
    destino[contador] = '\0';
}


tImpr *CriaTarefaSoma(char msg) {
    tImpr *impressao = NULL;

    impressao = (tImpr*)malloc(sizeof(tImpr));

    if (impressao == NULL) {
        printf("Erro! Alocacao de memoria de estrutura de soma mal-sucedida.\n");
        exit(1);
    }
    
    impressao->mensagem = NULL;

    impressao->mensagem = (char*)calloc((obtemTamanhoMensagem(msg) + 1), sizeof(char));

    if ((*impressao).mensagem == NULL) {
        printf("Erro! Alocacao de memoria da mensagem da tarefa de impressao mal-sucedida.\n");
        DestroiTarefaImprimir((void*)impressao);
        exit(1);
    }

    copiaMensagem(msg, (*impressao).mensagem);

    return impressao;
}

void ExecutaTarefaImprimir(void *imp) {
    tImpr *impressao = (tImpr*)imp;

    printf("%s\n", (*impressao).mensagem);
}

void DestroiTarefaImprimir(void *imp) {
    tImpr *impressao = (tImpr*)imp;

    if (impressao != NULL) {
        if ((*impressao).mensagem != NULL)
            free((*impressao).mensagem);
        free(impressao);
    }
}