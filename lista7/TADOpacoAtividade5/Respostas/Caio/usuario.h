#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario tUsuario;

/**
 * @brief Cria (aloca a memória dinamicamente de) um usuário;
 * 
 * @return tUsuario* Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados inicializados) do usuário;
 */
tUsuario *CriaUsuario();

/**
 * @brief Lê os dados/informações de um usuário;
 * 
 * @param user Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (a serem lidas) do usuário;
 */
void LeUsuario(tUsuario *user);

/**
 * @brief Imprime os dados de um usuário;
 * 
 * @param user Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do usuário;
 */
void ImprimeUsuario(tUsuario *user);

/**
 * @brief Destrói (libera/desaloca a memória dinamicamente de) um usuário;
 * 
 * @param user Ponteiro para Tipo Abstrato de Dados (T.A.D.) que representa a estrutura que contém as informações (com dados atualizados) do usuário;
 */
void DestroiUsuario (tUsuario *user);

#endif