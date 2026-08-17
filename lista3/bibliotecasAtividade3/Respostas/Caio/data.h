#ifndef _data
#define _data

/**
 * @brief Verifica se uma data é válida (baseado no calendário do sistema);
 * 
 * @param dia Dia de uma data;
 * @param mes Mês de uma data;
 * @param ano Ano de uma data;
 * @return int 1 (verdadeiro) se a data for válida (no calendário), ou 0 (falso) caso contrário;
 */
int verificaDataValida(int dia, int mes, int ano);

/**
 * @brief VErifica se um ano é bissexto;
 * 
 * @param ano Ano de uma data;
 * @return int 1 (verdadeiro) se o  ano for bissexto, ou 0 (falso), caso contrário;
 */
int verificaBissexto(int ano);

/**
 * @brief Indica o número e dias que um mês possui;
 * 
 * @param mes Mês da data que será usada como referÊncia;
 * @param ano ano da data que será usada como referência;
 * @return int Número de dias do mês da data usada como referência;
 */
int numeroDiasMes(int mes, int ano);

/**
 * @brief Compara duas datas e verifica qual delas é posterior a outra ou se as duas datas são iguais;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mês da segunda data;
 * @param ano1 Ano da primeira data;
 * @param dia2 Dia da segunda data;
 * @param mes2 Mês da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int 1 se a primeira data for maior que a segunda, ou -1 se a segunda data for maior que a primeira, ou 0 se as duas datas forem iguais;
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Retorna a diferença (em dias) entre a primeira e a segunda nota;
 * 
 * @param dia1 Dia da primeira data;
 * @param mes1 Mês da primeira data;
 * @param ano1 Ano da primeira data;
 * @param dia2 Dia da Segunda data;
 * @param mes2 mês da segunda data;
 * @param ano2 Ano da segunda data;
 * @return int Diferença (em dias) entre a primeira e a segunda data;
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

/**
 * @brief Imprime um mês por extenso;
 * 
 * @param mes Mês da data usada como referência;
 */
void imprimeMesExtenso(int mes);

/**
 * @brief Imprime uma data por extenso;
 * 
 * @param dia Dia da data;
 * @param mes Mês da data
 * @param ano Ano da data;
 */
void imprimeDataExtenso(int dia, int mes, int ano);

#endif