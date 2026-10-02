#include <stdio.h>
#include <stdlib.h>

#include "gerenciadorpacotes.h"

#define QUANTIDADE_PACOTES 50

struct gerenciadorpacotes{
    tPacote **pacotes;
    unsigned int numeroPacotes;
    unsigned short numeroMaximoPacotes;
};

tGerenciador *CriaGerenciador() {
    tGerenciador *gerenciador = NULL;

    gerenciador = (tGerenciador*)malloc(sizeof(tGerenciador));

    if (gerenciador == NULL) {
        printf("Erro! Alocacao de memoria para gerenciador mal-sucedida.\n");
        exit(1);
    }
    gerenciador->pacotes = NULL;

    gerenciador->pacotes = (tPacote**)malloc(QUANTIDADE_PACOTES *  sizeof(tPacote*));

    if ((*gerenciador).pacotes == NULL) {
        printf("Erro! alocacao de memoria para vetor/lista/'array' de pacotes do gerenciador mal-sucedida.\n");
        DestroiGerenciador(gerenciador);
        exit(1);
    }
    gerenciador->numeroPacotes = 0;
    gerenciador->numeroMaximoPacotes = QUANTIDADE_PACOTES;
    
    return  gerenciador;
}

void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac) {
    const static unsigned short int AUMENTO = 2;

    if ((*geren).numeroPacotes == (*geren).numeroMaximoPacotes) {
        geren->numeroMaximoPacotes *= AUMENTO;

        geren->pacotes = (tPacote**)realloc((*geren).pacotes, (*geren).numeroMaximoPacotes * sizeof(tPacote*));

        if ((*geren).pacotes == NULL) {
            printf("Erro! Realocacao de memoria do vetor/lista/'array'  de pacotes do gerenciador mal-sucediida.\n");
            DestroiGerenciador(geren);
            exit(1);
        }
    }
    geren->pacotes[(*geren).numeroPacotes++] = pac;
}

void ImprimirPacoteNoIndice(tGerenciador *geren, int idx) {
    ImprimePacote((*geren).pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador *geren) {
    unsigned int p;

    for (p = 0; p < (*geren).numeroPacotes; p++)
        ImprimirPacoteNoIndice(geren, p);
}

void DestroiGerenciador(tGerenciador *geren) {
    if (geren != NULL) {
        if ((*geren).pacotes != NULL) {
            unsigned int p;

            for(p = 0; p < (*geren).numeroPacotes; p++)
                DestroiPacote((*geren).pacotes[p]);

            free((*geren).pacotes);
        }
        free(geren);
    }
}