#ifndef _USUARIO_H_
#define _USUARIO_H_

/**
 * @brief Criação do tipo Abstrato de dados e declaração de funções da biblioteca;
 * 
 * @OBS: O atributo "nome" está com tamanhos diferemntes na função de criar usuário e na
 * definição do tipo abstrato de dados por causa da configuração entregue no exercício;
 */

typedef struct Usuario {
    char nome[50], cpf[50];
}tUsuario;

/**
 * @brief Cria e inicializa os dados de um usuário;
 * 
 * @param nome Nome do usuário
 * @param cpf CPF do usuário;
 * @return tUsuario Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados inicializados de um usuário;
 */
tUsuario CriaUsuario(char nome[20], char cpf[15]);

/**
 * @brief Impriem os dados de um usuário;
 * 
 * @param user Tipo de Dados Abstrato (T.A.D.) que representa a estrutura que contém os dados (atualizados) de um usuário;
 */
void ImprimeUsuario(tUsuario user);

#endif