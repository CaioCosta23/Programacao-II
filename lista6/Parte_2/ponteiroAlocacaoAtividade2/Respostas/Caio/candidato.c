#include <stdio.h>
#include <stdlib.h>

#include "candidato.h"

#define INITIAL_SIZE 50

tCandidato *CriaCandidato() {
    tCandidato *candidato = NULL;

    candidato = (tCandidato*)malloc(sizeof(tCandidato));

    if (candidato == NULL) {
        printf("Erro! Alocacao de memoria do candidato mal-sucedida.\n");
        exit(1);
    }

    candidato->nome = NULL;

    candidato->nome = (char*)calloc(INITIAL_SIZE, sizeof(char));

    if ((*candidato).nome == NULL) {
        printf("Erro! Alocacao de memoria do nome do candidato mal-sucedida.\n");
        exit(1);
    }

    candidato->partido = NULL;

    candidato->partido = (char*)calloc(INITIAL_SIZE, sizeof(char));

    if ((*candidato).partido == NULL) {
        printf("Erro! Alocacao de memoria do nome do partido do candidato mal-sucedida.\n");
        exit(1);
    }

    candidato->cargo = '\0';
    candidato->id = -1;
    candidato->votos = 0;

    return candidato;
}

void LeCandidato(tCandidato *candidato) {
    scanf("\n%[^,], %[^,], %c, %d\n", candidato->nome, candidato->partido, &candidato->cargo, &candidato->id);
}

int VerificaIdCandidato(tCandidato *candidato, int id) {
    return ((*candidato).id == id);
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2) {
    return ((*candidato1).id == (*candidato2).id);
}

char ObtemCargo(tCandidato *candidato) {
    return (*candidato).cargo;
}

void IncrementaVotoCandidato(tCandidato *candidato) {
    candidato->votos += 1;
}

int ObtemVotos(tCandidato *candidato) {
    return (*candidato).votos;
}

float CalculaPercentualVotos(tCandidato *candidato, int totalVotos) {
    return (((float)(*candidato).votos / (float)totalVotos) * 100);
}

void ImprimeCandidato(tCandidato *candidato, float percentualVotos) {
    printf("%s (%s), %d voto(s), %.2f%%\n", (*candidato).nome, (*candidato).partido, (*candidato).votos, percentualVotos);
}

void ApagaCandidato(tCandidato *candidato) {
    if (candidato != NULL) {
        if ((*candidato).nome != NULL)
            free((*candidato).nome);
        if ((*candidato).partido != NULL)
            free((*candidato).partido);
        
        free(candidato);
    }
}