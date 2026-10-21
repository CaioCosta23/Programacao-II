#include <stdio.h>
#include <stdlib.h>

#include "eleicao.h"

#define QUANTIDADE_INICIAL_CANDIDATOS 10
#define QUANTIDADE_INICIAL_ELEITORES 50

#define PRESIDENTE 'P'
#define GOVERNADOR 'G'

/**
 * @brief Realoca a memória dinamicamente de uma lista/vetor/'array' de candidatos;
 * 
 * @param candidatos (Ponteiro para ponteiro ou) Ponteiro para lista de Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém as informações dos candidatos;
 * @param tamanho Tamanho da memória que será realocada;
 */
static void realocarMemoriaVetorCandidatos(tCandidato **candidatos, unsigned int tamanho) {
    candidatos = (tCandidato**)realloc(candidatos, tamanho * sizeof(tCandidato*));

    if (candidatos == NULL) {
        printf("Erro! Realocacao de memoria de lista/vetor/'array' candidatos mal-sucedida.\n");
        exit(1);
    }
}

/**
 * @brief Realoca a memória dinamicamente de uma lista/vetor/'array' de eleitores;
 * 
 * @param eleitores (Ponteiro para ponteiro ou) Ponteiro para lista de Tipos Abstratos de Dados (T.A.D.s) que representam as estruturas que contém as informações dos eleitores;
 * @param tamanho Tamanho da memória que será realocada;
 */
static void realocarMemoriaVetorEleitores(tEleitor **eleitores, unsigned int tamanho) {
    eleitores = (tEleitor**)realloc(eleitores, tamanho * sizeof(tEleitor*));

    if (eleitores == NULL) {
        printf("Erro! Realocacao de memoria de lista/vetor/'array' eleitores mal-sucedida.\n");
        exit(1);
    }
}


tEleicao *InicializaEleicao() {
    tEleicao *eleicao = NULL;

    eleicao = (tEleicao*)malloc(sizeof(tEleicao));

    if (eleicao == NULL) {
        printf("Erro! Alocacao de memoria para eleicao mal-sucedida.\n");
        exit(1);
    }

    eleicao->presidentes = NULL;

    eleicao->presidentes = (tCandidato**)malloc(QUANTIDADE_INICIAL_CANDIDATOS * sizeof(tCandidato*));

    if ((*eleicao).presidentes == NULL) {
        printf("Erro! Alocacao de memoria para lista de candidato a presidencia mal-sucedida.\n");
        ApagaEleicao(eleicao);
        exit(1);
    }

    eleicao->governadores = NULL;

    eleicao->governadores = (tCandidato**)malloc(QUANTIDADE_INICIAL_CANDIDATOS * sizeof(tCandidato*));

    if ((*eleicao).governadores == NULL) {
        printf("Erro! Alocacao de memoria para lista de candidato a governador mal-sucedida.\n");
        ApagaEleicao(eleicao);
        exit(1);
    }

    eleicao->eleitores = NULL;

    eleicao->eleitores = (tEleitor**)malloc(QUANTIDADE_INICIAL_ELEITORES * sizeof(tEleitor*));

    if ((*eleicao).eleitores == NULL) {
        printf("Erro! Alocacao de memoria para lista de eleitores mal-sucedida.\n");
        ApagaEleicao(eleicao);
        exit(1);
    }

    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;
    eleicao->totalEleitores = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosPresidente = 0;
    eleicao->votosNulosGovernador = 0;

    return eleicao;
}

void RealizaEleicao(tEleicao *eleicao) {
    unsigned int quantidadeCandidatos, c, quantidadeVotos, v, e;
    tCandidato *candidato;
    char cargo;
    tEleitor *eleitor;
    unsigned short int presidenteEncontrado, governadorEncontrado;
    int votoPresidente, votoGovernador;
    const unsigned short int VOTO_BRANCO = 0;

    scanf("%d", &quantidadeCandidatos);

    if (quantidadeCandidatos > QUANTIDADE_INICIAL_CANDIDATOS) {
        realocarMemoriaVetorCandidatos((*eleicao).presidentes, quantidadeCandidatos);
        realocarMemoriaVetorCandidatos((*eleicao).governadores, quantidadeCandidatos);
    }
    
    for(c = 0; c < quantidadeCandidatos; c++) {
        candidato = CriaCandidato();

        LeCandidato(candidato);

        cargo = ObtemCargo(candidato);

        if (cargo == PRESIDENTE)
            eleicao->presidentes[(*eleicao).totalPresidentes++] = candidato;
        else if (cargo == GOVERNADOR)
            eleicao->governadores[(*eleicao).totalGovernadores++] = candidato;
        else
            ApagaCandidato(candidato);
    }

    scanf("%d\n", &quantidadeVotos);

    if (quantidadeVotos > QUANTIDADE_INICIAL_ELEITORES)
        realocarMemoriaVetorEleitores((*eleicao).eleitores, quantidadeVotos);

    for(v = 0; v < quantidadeVotos; v++) {
        eleitor = CriaEleitor();

        LeEleitor(eleitor);

        if ((*eleicao).totalEleitores >= 1) {
            for(e = 0; e < (*eleicao).totalEleitores; e++)
                if (EhMesmoEleitor(eleitor, (*eleicao).eleitores[e])) {
                    printf("ELEICAO ANULADA\n");
                    ApagaEleitor(eleitor);
                    ApagaEleicao(eleicao);
                    exit(1);
                }
        }
        eleicao->eleitores[(*eleicao).totalEleitores++] = eleitor;
    }
/**/
    for(e = 0; e < (*eleicao).totalEleitores; e++) {
        presidenteEncontrado = 0;
        governadorEncontrado = 0;

        votoPresidente = ObtemVotoPresidente((*eleicao).eleitores[e]);
        votoGovernador = ObtemVotoGovernador((*eleicao).eleitores[e]);

        for(c = 0; c < (*eleicao).totalPresidentes; c++) {
            if (VerificaIdCandidato((*eleicao).presidentes[c], votoPresidente)) {
                IncrementaVotoCandidato((*eleicao).presidentes[c]);
                presidenteEncontrado = 1;
            }
        }
        if (!(presidenteEncontrado)) {
            if (votoPresidente == VOTO_BRANCO)
                eleicao->votosBrancosPresidente += 1;
            else
                eleicao->votosNulosPresidente += 1;
        }

        for(c = 0; c < (*eleicao).totalGovernadores; c++) {
            if (VerificaIdCandidato((*eleicao).governadores[c], votoGovernador)) {
                IncrementaVotoCandidato((*eleicao).governadores[c]);
                governadorEncontrado = 1;
            }
        }
        if (!(governadorEncontrado)) {
            if (votoGovernador == VOTO_BRANCO)
                eleicao->votosBrancosGovernador += 1;
            else
                eleicao->votosNulosGovernador += 1;
        }
    }
}

void ImprimeResultadoEleicao(tEleicao *eleicao) {
    unsigned short int empate; // Variável lógica;
    unsigned int quantidadeVotosCandidato, maiorQuantidadeVotos, indiceMaisVotado, p, g;
    unsigned int totalVotosPresidente = 0, totalVotosGovernador = 0;

    empate = 0;

    printf("- PRESIDENTE ELEITO: ");

    for(p = 0; p < (*eleicao).totalPresidentes; p++) {
        quantidadeVotosCandidato = ObtemVotos((*eleicao).presidentes[p]);
        
        if ((p == 0) || (quantidadeVotosCandidato > maiorQuantidadeVotos)) {
            maiorQuantidadeVotos = quantidadeVotosCandidato;
            indiceMaisVotado = p;
            empate = 0;
        }else if (quantidadeVotosCandidato == maiorQuantidadeVotos) {
            empate = 1;
        }
        totalVotosPresidente += quantidadeVotosCandidato;
    }
    if (empate) 
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else
        if (((*eleicao).votosBrancosPresidente + (*eleicao).votosNulosPresidente) > maiorQuantidadeVotos)
            printf("SEM DECISAO\n");
        else
            ImprimeCandidato((*eleicao).presidentes[indiceMaisVotado], CalculaPercentualVotos((*eleicao).presidentes[indiceMaisVotado], (totalVotosPresidente + (*eleicao).votosNulosPresidente + (*eleicao).votosBrancosPresidente)));

    empate = 0;

    printf("- GOVERNADOR ELEITO: ");

    for(g = 0; g < (*eleicao).totalGovernadores; g++) {
        quantidadeVotosCandidato = ObtemVotos((*eleicao).governadores[g]);
        
        if ((g == 0) || (quantidadeVotosCandidato > maiorQuantidadeVotos)) {
            maiorQuantidadeVotos = quantidadeVotosCandidato;
            indiceMaisVotado = g;
            empate = 0;
        }else if (quantidadeVotosCandidato == maiorQuantidadeVotos) {
            empate = 1;
        }
        totalVotosGovernador += quantidadeVotosCandidato;
    }

    if (empate) 
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else
        if (((*eleicao).votosBrancosGovernador + (*eleicao).votosNulosGovernador) > maiorQuantidadeVotos)
            printf("SEM DECISAO\n");
        else
            ImprimeCandidato((*eleicao).governadores[indiceMaisVotado], CalculaPercentualVotos((*eleicao).governadores[indiceMaisVotado], (totalVotosGovernador + (*eleicao).votosNulosGovernador + (*eleicao).votosBrancosGovernador)));

    printf("- NULOS E BRANCOS: %d, %d\n", ((*eleicao).votosNulosPresidente + (*eleicao).votosNulosGovernador), ((*eleicao).votosBrancosPresidente + (*eleicao).votosBrancosGovernador));
}

void ApagaEleicao(tEleicao *eleicao) {
    if (eleicao != NULL) {
        if ((*eleicao).presidentes != NULL) {
            unsigned int p;

            for(p = 0; p < (*eleicao).totalPresidentes; p++)
                ApagaCandidato((*eleicao).presidentes[p]);

            free((*eleicao).presidentes);
        }
        if ((*eleicao).governadores != NULL) {
            unsigned int g;

            for(g = 0; g < (*eleicao).totalGovernadores; g++)
                ApagaCandidato((*eleicao).governadores[g]);

            free((*eleicao).governadores);
        }
        if ((*eleicao).eleitores != NULL) {
            unsigned int e;

            for(e = 0; e < (*eleicao).totalEleitores; e++)
                ApagaEleitor((*eleicao).eleitores[e]);

            free((*eleicao).eleitores);
        }
        free(eleicao);
    }
}