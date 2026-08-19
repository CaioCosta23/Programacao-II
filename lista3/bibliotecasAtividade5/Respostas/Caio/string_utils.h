#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

/**
 * @brief Obtém o tamanho de uma string;
 * 
 * @param str String a ter seu tamanho calculado
 * @return int Tamanho (Numero de caracteres) de uma String;
 */
int string_length(char str[]);

/**
 * @brief Copia o conteúdo de uma string para outra;
 * 
 * @param src String que será copiada;
 * @param dest String que receberá a cópia;
 */
void string_copy(char src[], char dest[]);

/**
 * @brief Converte todos os caracteres de uma String para maiúsculo;
 * 
 * @param str String que terá seus caracteres convertidos em caracteres maiúsculo;
 */
void string_upper(char str[]);

/**
 * @brief Converte todos os caracteres de uma String para minúsculo;
 * 
 * @param str String que terá seus caracteres convertidos em caracteres minúsculo;
 */
void string_lower(char str[]);

/**
 * @brief Inverte uma string;
 * 
 * @param str String a ser invertida;
 */
void string_reverse(char str[]);

#endif