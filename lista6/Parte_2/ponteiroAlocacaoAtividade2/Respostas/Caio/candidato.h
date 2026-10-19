#ifndef _CANDIDATO_H_
#define _CANDIDATO_H_

typedef struct {
    char *nome, *partido;
    char cargo;
    int id, votos;
}tCandidato;

/**
 * @brief Cria (aloca a memória dinâmicamente de) um candidato;
 * 
 * @return tCandidato* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados inicializados) do candidato;
 */
tCandidato *CriaCandidato();

/**
 * @brief Lê os dados d eum candidato;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (a serem lidas) do candidato;
 */
void LeCandidato(tCandidato *candidato);

/**
 * @brief Verifica se o ID (identificador) do candidato é igual ao ID (identificador) recebido;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 * @param id ID (identificador) a ser comparado com o do candidato;
 * @return int 1 (verdadeiro) se o ID (identificador) recebido é igual ao do candidato ou 0 (falso) caso contrário;
 */
int VerificaIdCandidato(tCandidato *candidato, int id);

/**
 * @brief Verifica se um candidato é igual (é o mesmo) ao outro;
 * 
 * @param candidato1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do primeiro candidato a ser comparado com o segundo;
 * @param candidato2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do segundo candidato a ser comparado com o primeiro;
 * @return int 1 (verdadeiro) se os candidatos forem iguais (é o mesmo candidato) ou 0 (falso), caso contrário;
 */
int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2);

/**
 * @brief Obtém o cargo de um candidato;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 * @return char Cargo do candidato;
 */
char ObtemCargo(tCandidato *candidato);

/**
 * @brief Incrementa a quantidade de votos que um candidato possui;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 */
void IncrementaVotoCandidato(tCandidato *candidato);

/**
 * @brief Obtém o número de votos que um candidato possui;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 * @return int Quantidade de votos que o candidato possui;
 */
int ObtemVotos(tCandidato *candidato);

/**
 * @brief Calcula qual o percentual de votos (dentre o total de votos da eleição) que o condidato recebeu;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 * @param totalVotos Quantidade total de votos da eleição;
 * @return float Percentual de votos (dentre todos os votos da eleição) que o candidato recebeu;
 */
float CalculaPercentualVotos(tCandidato *candidato, int totalVotos);

/**
 * @brief Imprime os dados de um candidato;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 * @param percentualVotos Percentual de votos que o candidato recebeu (dentre todos os votos da eleição);
 */
void ImprimeCandidato(tCandidato *candidato, float percentualVotos);

/**
 * @brief Apaga (libera/ desaloca a memória alocada dinamicamente de) uma memória;
 * 
 * @param candidato Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do candidato;
 */
void ApagaCandidato(tCandidato *candidato);

#endif
