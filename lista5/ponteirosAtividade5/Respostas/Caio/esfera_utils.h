#ifndef _ESFERA_UTILS_H
#define _ESFERA_UTILS_H

#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera;
 * 
 * @param R Raio da esfera;
 * @param volume Ponteiro para o valor do volume (que será calculado) da esfrera ;
 */
void CalculaVolume(float R, float *volume);

/**
 * @brief Calcula a área de uma esfera;
 * 
 * @param R Raio da esfera;
 * @param area Ponteiro para o valor da área (que será calculada) da esfera;
 */
void CalculaArea(float R, float *area);

#endif