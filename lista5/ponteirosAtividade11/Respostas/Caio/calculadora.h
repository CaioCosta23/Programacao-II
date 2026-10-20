#ifndef _CALCULADORA_H_
#define _CALCULADORA_H_


typedef float (*CalculadoraCallback)(float, float); // Renomeação do ponteiro para a função;

/**
 * @brief Realiza uma operação matemática entre dois números;
 * 
 * @param num1 Primeiro número envolvido no cálculo;
 * @param num2 Segundo número envolvido no cálculo;
 * @param operacao Ponteiro para função ('callback') que fará referência ao tipo de operação à ser realizada;
 * @return float Valor resultante do cálculo;
 */
float Calcular(float num1, float num2, CalculadoraCallback operacao);

#endif