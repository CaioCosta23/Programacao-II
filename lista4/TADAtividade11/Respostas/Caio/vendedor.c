#include <stdio.h>
#include <stdlib.h>

#include "vendedor.h"

/**
 * @brief  Copia uma 'string 'para outra;
 * 
 * @param origem 'String' que será copiada;
 * @param destino 'String' que resceberár a outra;
 */
static void copiaString(char origem[500], char destino[50]) {
    unsigned  short int indice = 0;

    while(1) {
        destino[indice] = origem[indice];

        if ((origem[indice] == '\0') || (destino[indice] == '\0'))
            break;
        
        indice++;
    }
}

/**
 * @brief Compara duas 'strings' e verifica se são iguais;
 * 
 * @param origem Primeira 'string' da comparação;
 * @param comparado Segunda 'string' a ser comparada;
 * @return unsigned short int 1 ((vedadeiro) se as trings forem iguais ou 0 (falso), caso contrário;
 */
static unsigned short int comparaString(char origem[50], char comparado[50]) {
    unsigned short int indice = 0;
    unsigned short int iguais = 1; // Variável lógica;

    while(1) {
        if (origem[indice] != comparado[indice]) {
            iguais = 0;
            break;
        }

        if ((origem[indice] == '\0') || (comparado[indice] == '\0'))
            break;
        
        indice++;
    }
    return iguais;
}

tVendedor RegistraVendedor(char nome[50], float salario, float pcrt_comissao) {
    tVendedor vendedor;

    copiaString(nome, vendedor.nome);
    vendedor.salario = salario;
    vendedor.prct_comissao = pcrt_comissao;
    vendedor.valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]) {
    return comparaString(vendedor.nome, nome);
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor) {
    vendedor.valor_vendido += valor;

    return vendedor;
}

float GetSalario(tVendedor vendedor) {
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor) {
    return GetTotalVendido(vendedor) * vendedor.prct_comissao;
}

float GetTotalVendido(tVendedor vendedor) {
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor) {
    return GetSalario(vendedor) + GetComissao(vendedor);
}

void ImprimeRelatorioVendedor(tVendedor vendedor) {
    printf("\t%s > Total vendido: R$%.2f\n", vendedor.nome, GetTotalVendido(vendedor));
    printf("\t\tTotal recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}
