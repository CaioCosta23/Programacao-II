#ifndef _ELEITOR_H_
#define _ELEITOR_H_

typedef struct {
    int id, votoP, votoG;
}tEleitor;

/**
 * @brief Cria (aloca a memória dinamicamente de) um eleitor;
 * 
 * @return tEleitor* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados inicializados) do eleitor;
 */
tEleitor *CriaEleitor();

/**
 * @brief Lê os dados/informações de um eleitor;
 * 
 * @param eleitor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (a serem lidas) do eleitor;
 */
void LeElietor(tEleitor *eleitor);

/**
 * @brief Obtém o voto de um eleitor para presidente;
 * 
 * @param eleitor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do eleitor;
 * @return int Voto do eleitor para presidente;
 */
int ObtemVotoPresidente(tEleitor *eleitor);

/**
 * @brief Obtém o voto de um eleitor, para governador;
 * 
 * @param eleitor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do eleitor;
 * @return int Voto do eleitor para governador;
 */
int ObtemVotoGovernador(tEleitor *eleitor);

/**
 * @brief Compara e verifica se dois eleitores são iguais (são o mesmo eleitor);
 * 
 * @param eleitor1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do primeiro eleitor a ser comparado com o segundo;
 * @param eleitor2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do segundo eleitor a ser comparado com o primeiro;
 * @return int 1 (verdadeiro) se os eleitores comparados forem iguais (forem o mesmo eleitor) ou 0 (falso), caso contrário;
 */
int EhMesmoEleitor(tEleitor *eleitor1, tEleitor *eleitor2);

/**
 * @brief Apaga (libera/desaloca a memória dinmicamente) de um eleitor;
 * 
 * @param eleitor Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do eleitor;
 */
void ApagaEleitor(tEleitor *eleitor);

#endif