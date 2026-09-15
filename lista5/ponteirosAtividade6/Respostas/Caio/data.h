#ifndef DATA_H
#define DATA_H

typedef struct Data {
    int dia, mes, ano;
}tData;

/**
 * @brief Inicializa os dados de uma data;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data (com seus dados inicializados);
 */
void InicializaDataParam(int dia, int mes, int ano, tData *data);

/**
 * @brief Lê os dados de uma data;
 * 
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data;
 */
void LeData(tData *data);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data (com os dados atualizados);
 * @return int 1 (verdadeiro) se o ano eh bissexto ou 0 (falso) caso contrário;
 */
int EhBissexyto(tData *data);

/**
 * @brief Informa a quantidade de dias que um mês possui;
 * 
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data (com os dados atualizados);
 * @return int Quantidade de dias do mês da data;
 */
int InformaQtdDiasNoMes(tData *data);

/**
 * @brief Avança o dia de uma data para o dia/data seguinte;
 * 
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data (com os dados atualizados);
 */
void AvancaParaDiaSeguinte(tData *data);

/**
 * @brief Verifica se duas datas são iguais;
 * 
 * @param data1 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da primeira data (com os dados atualizados);
 * @param data2 Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da segunda data (com os dados atualizados);
 * @return int 1 (verdadeiro) se as datas são iguai ou 0 (falso), caso contrário;
 */
int EhIgual(tData *data1, tData data2);

/**
 * @brief Imprime os dados de uma data;
 * 
 * @param data Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações da data (com os dados atualizados);
 */
void ImprimeData(tData *data);

#endif