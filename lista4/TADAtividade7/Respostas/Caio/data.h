#ifndef _data
#define _data

typedef struct Data {
    int dia, mes, ano;
}tData;

/**
 * @brief Cria uma (estrutura de dados que representa uma) data;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @return tData Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados inicializados da data criada;
 */
tData CriaData(int dia, int mes, int ano);

/**
 * @brief Verifca se uma data é válida;
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 * @return int 1 (verdadeiro) se a data for válida ou 0 (falso), caso contrário;
 */
int VerificaDataValida(tData data);

/**
 * @brief Verifica se o ano de uma data é bissexto;
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 * @return int 1 (verdadeiro) se o ano da data for bissexto ou 0 (falso), caso contrário;
 */
int VerificaBissexto(tData data);

/**
 * @brief Obtém o número de dias de um mês (neste caso, da data passada como parâmetro);
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 * @return int Número de dias do mês da data;
 */
int NumeroDiasMes(tData data);

/**
 * @brief Compara duas datas, verificando qul delas é maior (posterior ou depois) que a outra;
 * 
 * @param data1 Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da primeira data;
 * @param data2 Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da segunda data;
 * @return int 1 se a primeira data for maior (posterior ou depois) que a segunda data, ou -1 se a segundaa data for maior (posterior ou depois) que a primeira data, ou 0 se as datas forem iguais;
 */
int ComparaData(tData data1, tData data2);

/**
 * @brief Calcula o número de dias até um mês;
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 * @return int Número de dias até determinado mês;
 */
int CalculaDiasAteMes(tData data);

/**
 * @brief Calcula a diferença (em dias) de uma data para a outra;
 * 
 * @param data1 Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da primeira data;
 * @param data2 Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da segunda data;
 * @return int Número de dias de uma data  até a outra;
 */
int CalculaDiferencaDias(tData data1, tData data2);

/**
 * @brief Imprime o nome de um mês (por extenso);
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 */
void ImprimeMesExtenso(tData data);

/**
 * @brief  Imprime uma data por extenso;
 * 
 * @param data Tipo de Dados Abstratos (T.A.D.) que representa a estrutura que contém os dados (atualizados) da data;
 */
void ImprimeDataExtenso(tData data);

#endif