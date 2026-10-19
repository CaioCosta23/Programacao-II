#include <stdio.h>
#include <stdlib.h>

#include "eleitor.h"

tEleitor *CriaEleitor() {
    tEleitor *eleitor = NULL;

    eleitor = (tEleitor*)malloc(sizeof(tEleitor));

    if (eleitor == NULL) {
        printf("Erro! Alocacao de memoria de eleitor mal-sucedida.\n");
        exit(1);
    }

    eleitor->id = -1;
    eleitor->votoG = 0;
    eleitor->votoP = 0;
    
    return eleitor;
}

void LeElietor(tEleitor *eleitor) {
    scanf("%d\n", &eleitor->id);
}

int ObtemVotoPresidente(tEleitor *eleitor) {
    return (*eleitor).votoP;
}

int ObtemVotoGovernador(tEleitor *eleitor) {
    return (*eleitor).votoG;
}

int EhMesmoEleitor(tEleitor *eleitor1, tEleitor *eleitor2) {
    return ((*eleitor1).id == (*eleitor2). id);
}

void ApagaEleitor(tEleitor *eleitor) {
    if (eleitor != NULL)
        free(eleitor);
}