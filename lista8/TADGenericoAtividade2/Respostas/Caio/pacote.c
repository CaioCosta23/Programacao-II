#include <stdio.h>
#include <stdlib.h>

#include "pacote.h"

struct pacote {
    void *dados;
    Type tipo;
    int numeroElementos;

};

tPacote *CriaPacote (Type type, int numElem) {
    tPacote *pacote = NULL;

    pacote = (tPacote*)malloc(sizeof(tPacote));

    if (pacote == NULL) {
        printf("Erro! Alocacao de memoria de pacote mal-sucedida.\n");
        exit(1);
    }

    if (type == INT) {
        pacote->tipo = INT;

        pacote->dados = NULL;

        pacote->dados = (int*)calloc(numElem, sizeof(int));

        if ((*pacote).dados == NULL) {
            printf("Erro! Alocacao de memoria de pacotes mal-sucedida.\n");
            exit(1);
        }
    }else if (type == CHAR) {
        pacote->tipo = CHAR;

        pacote->dados = NULL;

        pacote->dados = (char*)calloc(numElem, sizeof(char));

        if ((*pacote).dados == NULL) {
            printf("Erro! Alocacao de memoria de pacotes mal-sucedida.\n");
            exit(1);
        }
    }else {
        printf("Erro! Tipo de pacote desconhecido.\n");
        DestroiPacote(pacote);
        exit(1);
    }

    pacote->numeroElementos = numElem;

    return pacote;
}

void LePacote(tPacote *pac) {
    if ((*pac).tipo == INT) {
        unsigned short int d;

        for (d = 0; d < (*pac).numeroElementos; d++) {
            if (d < ((*pac).numeroElementos - 1))
                scanf("%d ", &((int*)(pac->dados))[d]);
            else
                scanf("%d\n", &((int*)(pac->dados))[d]);
        }
    }else if ((*pac).tipo == CHAR) {
        unsigned short int d;

        for (d = 0; d < (*pac).numeroElementos; d++)
            scanf("%c", &((char*)(pac->dados))[d]);
        scanf("%*[^\n]\n");
    }else {
        printf("Erro! Tipo nao identificado para leitura de dados do pacote.\n");
    }
}

void CalculaSomaVerificacaoPacote(tPacote *pac) {
    /*
    if (((*pac).tipo != INT) && ((*pac).tipo != CHAR)) {
        printf("Erro! Tipo de dado do pacote nao identifiado para a soma dos valores dos dados.\n");
        DestroiPacote(pac);
        exit(1);
    }

    unsigned short int d;

    for (d = 0; d < (*pac).numeroElementos; d++)
        pac->somaDados += ((int*)(*pac).dados)[d];
    printf("%d ", (*pac).somaDados);
*/
    
    if ((*pac).tipo == INT) {
         unsigned short int d;
         unsigned int somaDados = 0;

        for (d = 0; d < (*pac).numeroElementos; d++)
            somaDados += ((int*)(*pac).dados)[d];
        printf("%d ", somaDados);
    }else if ((*pac).tipo == CHAR){
        unsigned short int d;
        unsigned int somaDados = 0;

        for (d = 0; d < (*pac).numeroElementos; d++)
            somaDados += (int)((char*)(*pac).dados)[d];
        printf("%d ", somaDados);
    }else {
        printf("Erro! Tipo de dado do pacote nao identifiado para a soma dos valores dos dados.\n");
        DestroiPacote(pac);
        exit(1);
    }
}

void ImprimePacote(tPacote *pac) {
    CalculaSomaVerificacaoPacote(pac);

    if ((*pac).tipo == INT) {
        unsigned short int d;

        for (d = 0; d < (*pac).numeroElementos; d++)
            printf("%d ", ((int*)(pac->dados))[d]);
        printf("\n");
    }else if ((*pac).tipo == CHAR) {
        unsigned short int d;

        for (d = 0; d < (*pac).numeroElementos; d++)
            printf("%c", ((char*)(pac->dados))[d]);
        printf("\n");
    }else {
        printf("Erro! Tipo nao identificado para leitura de dados do pacote.\n");
    }
}

void DestroiPacote(tPacote *pac) {
    if (pac != NULL) {
        if ((*pac).dados != NULL)
            free((*pac).dados);
        free(pac);
    }
}