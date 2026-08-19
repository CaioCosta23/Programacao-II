#ifndef _data
#define _data

/**
 * @brief Verifica se uma data é válida;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 * @return int 1 (verdadeiro) se a data for válida, ou 0 (falso), caso contrário;
 */
int verificaDataValida(int dia, int mes, int ano);

/**
 * @brief Verifica se um ano é bissexto;
 * 
 * @param ano Ano da data de referência;
 * @return int 1 (verdadeiro) se o ano for bissexto, ou 0 (falso), caso contrário;
 */
int verificaBissexto(int ano);

/**
 * @brief Retorna o número de dias que um respectivo mês possui;
 * 
 * @param mes Mês da data referenciada;
 * @param ano Ano da data referenciada;
 * @return int Número de dias que o mês de referência possui;
 */
int numeroDiasMes(int mes, int ano);

/**
 * @brief 
 * 
 * @param dia1 Dia da primeira data a ser comparada;
 * @param mes1 Mês da primeira data a ser comparada;
 * @param ano1 Ano da primeira data a ser comparada;
 * @param dia2 Dia da segunda data a ser comparada;
 * @param mes2 Mês da segunda data a ser comparada;
 * @param ano2 Ano da segunda data a ser comparada;
 * @return int 1 se a primeria data for maior (posterior) que a segunda, -1 se a segunda data for maior (posterior) que a primeira, ou 0, caso as duas datas sejam iguais; 
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Calcula o numero de dias até o inicio de um determinado mês;
 * 
 * @param mes Mes da data referenciada;
 * @param ano Ano da data referenciada;
 * @return int Número de dias até até o início do mês;
 */
int calculaDiasAteMes(int mes, int ano);

/**
 * @brief Retorna a diferença (em dias) entre uma data e outra;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mês da primeira data;
 * @param ano1 Ano da primeira data;
 * @param dia2 Dia da segunda data;
 * @param mes2 Mês da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int Diferença (em número de dias) entre uma data e outra;
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Imprime o nome de um mês por extenso;
 * 
 * @param mes Mês da data referenciada;
 */
void imprimeMesExtenso(int mes);

/**
 * @brief Imprime uma data;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data;
 * @param ano Ano da data;
 */
void imprimeData(int dia, int mes, int ano);

/**
 * @brief Imprime a próxima data (no formato "dd/mm/AAAA");
 * 
 * @param dia Dia da data de referência;
 * @param mes Mês da data de referência;
 * @param ano ANo da data de Referência;
 */
void imprimeProximaData(int dia, int mes, int ano);

#endif