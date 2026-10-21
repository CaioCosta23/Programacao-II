#ifndef _ELEICAO_H
#define _ELEICAO_H_

#include "candidato.h"
#include "eleitor.h"

typedef struct {
    tCandidato **presidentes, **governadores;
    tEleitor **eleitores;
    int totalPresidentes, votosBrancosPresidente, votosNulosPresidente,
        totalGovernadores, votosBrancosGovernador, votosNulosGovernador,
        totalEleitores;
}tEleicao;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma eleição;
 * 
 * @return tEleicao* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados inicializados) da eleição;
 */
tEleicao *InicializaEleicao();

/**
 * @brief Realiza o processo de eleição;
 * 
 * @param eleicao Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) da eleição;
 */
void RealizaEleicao(tEleicao *eleicao);

/**
 * @brief Imprime resultado da eleição na tela à partir da apuração dos votos;
 * 
 * @param eleicao Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) da eleição;
 */
void ImprimeResultadoEleicao(tEleicao *eleicao);

/**
 * @brief Apaga (libera/ desaloca a memória dinamicamente de) uma eleição;
 * 
 * @param eleicao Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) da eleição;
 */
void ApagaEleicao(tEleicao *eleicao);

#endif