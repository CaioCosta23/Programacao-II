#include <stdio.h>
#include <stdlib.h>

#include "candidato.h"

#define TAMANHO_PALAVRA 50

/**
 * @brief Realoca a memória dinamicamente de um vetor/lista/'array' de caracteres;
 * 
 * @param vetorCaracteres (Ponteiro ou) Lista/Vetor/'Array' de caracteres;
 * @param tamanho Tamanho da memória que será realocada;
 * @return char* Ponteiro para o vetor/lista/'array' de caracteres que teve a memória realocada;
 */
static char *realocarMemoria(char *vetorCaracteres, unsigned int tamanho) {
    vetorCaracteres = (char*)realloc(vetorCaracteres, tamanho * sizeof(char));

    if (vetorCaracteres == NULL) {
        printf("Erro! Realocacao de memoria de veror de caracteres mal-sucedida.\n");
    }
    return vetorCaracteres;
}

/**
 * @brief Lê uma sequência de caracteres;
 * 
 * @param vetorCaracteres (Ponteiro ou) Lista/Vetor/'Array' de caracteres;
 */
static void leVetorCaracteres(char *vetorCaracteres) {
    unsigned int contador = 0, tamanho = TAMANHO_PALAVRA;
    char letra;
    const char VIRGULA = ',';
    const unsigned int DOBRO = 2;

    while(1) {
        scanf("%c", &letra);

        if (letra == VIRGULA) {
            scanf("%*c"); // Consome o espaço que vem após a leitura da vírgula;
            break;
        }

        if (contador == tamanho) {
            tamanho *= DOBRO;
            realocarMemoria(vetorCaracteres, tamanho);
        }
        vetorCaracteres[contador++] = letra;
    }
}

tCandidato *CriaCandidato() {
    tCandidato *candidato = NULL;

    candidato = (tCandidato*)malloc(sizeof(tCandidato));

    if (candidato == NULL) {
        printf("Erro! Alocacao de memoria do candidato mal-sucedida.\n");
        exit(1);
    }

    candidato->nome = NULL;

    candidato->nome = (char*)calloc(TAMANHO_PALAVRA, sizeof(char));

    if ((*candidato).nome == NULL) {
        printf("Erro! Alocacao de memoria do nome do candidato mal-sucedida.\n");
        exit(1);
    }

    candidato->partido = NULL;

    candidato->partido = (char*)calloc(TAMANHO_PALAVRA, sizeof(char));

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
    static unsigned int contagem = 0; // Variável criada para verificar se há uma quebra de linha vinda do arquivo principal com a leitura da quantidade de candidatos;

    if (contagem == 0) {
        scanf("%*c"); // Leitura de caractere de quebra de linha que veio de outro arquivo ou de última leitura que utilizou essa função;
        contagem++;
    }

    leVetorCaracteres((*candidato).nome);
    leVetorCaracteres((*candidato).partido);
    scanf("%c, %d\n", &candidato->cargo, &candidato->id);
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