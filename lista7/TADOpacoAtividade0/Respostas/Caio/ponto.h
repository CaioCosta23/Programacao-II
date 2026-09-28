#ifndef _PONTO
#define _PONTO

typedef struct Ponto *tPonto;

/**
 * @brief Cria (aloca a memória dinamicamente de) um ponto;
 * 
 * @param x Coordenada X do ponto;
 * @param y Coordenada Y do ponto;
 * @return tPonto (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (inicializados) de um ponto;
 */
tPonto Pto_Cria(float x, float y);

/**
 * @brief Atribui a coordenada X do ponto, um novo valor;
 * 
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 * @param x Novo valor da coordenada X;
 */
void Pto_Atribui_x(tPonto p, float x);

/**
 * @brief Atribui a coordenada Y do ponto, um novo valor;
 * 
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 * @param y Novo valor da coordenada Y do ponto;
 */
void Pto_Atribui_y(tPonto p, float y);

/**
 * @brief Acessa a coordenada X do ponto;
 * 
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 * @return float Coordenada X do ponto;
 */
float Pto_Acessa_x(tPonto p);

/**
 * @brief Acessa a coordenada Y de um ponto;
 * 
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 * @return float Coordenada Y do ponto;
 */
float Pto_Acessa_y(tPonto p);

/**
 * @brief Calcula a distância entre dois pontos;
 * 
 * @param p1 (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) do primeiro ponto;
 * @param p2 (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) do segundo ponto;
 * @return float Valor da distâvia entre os dois pontos;
 */
float Pto_Distancia(tPonto p1, tPonto p2);

/**
 * @brief Apaga (libera/desaloca dinamicamente a memóoria de) um ponto;
 * 
 * @param p (Ponteiro para) Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um ponto;
 */
void Pto_Apaga(tPonto p);

#endif