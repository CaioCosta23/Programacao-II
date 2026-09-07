#include <stdio.h>
#include <stdlib.h>

#include "vendedor.h"

/**
 * @brief  Copia uma 'string 'para outra;
 * 
 * @param origem 'String' que será copiada;
 * @param destino 'String' que resceberár a outra;
 */
static void copiaString(char origem[], char destino[]) {
    unsigned int indice = 0;

    while(1) {
        destino[indice] = origem[indice];

        if ((origem == '\0') || (destino == '\0'))
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
static unsigned short int comparaString(char origem[], char comparado[]) {
    unsigned int indice = 0;
    unsigned short int iguais = 1;

    while(1) {
        if (origem[indice] != comparado[indice]) {
            iguais = 0;
            break;
        }

        if (origem[indice] != comparado[indice])
            break;
        
        indice++;
    }
}

tVendedor RegistraVendedor(char nome[], float salario, float pcrt_comissao) {
    tVendedor vendedor;

    copiaString(nome, vendedor.nome);
    vendedor.salario = salario;
    vendedor.prct_comissao = pcrt_comissao;
    vendedor.valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[]) {
    return comparaString(vendedor.nome, nome);
}

tVendedor Contabiliza(tVendedor vendedor, float valor) {
    vendedor.valor_vendido += valor;

    return vendedor;
}

float GetSalario(tVendedor vendedor) {
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor) {
    return vendedor.prct_comissao;
}

float GetTotalVendido(tVendedor vendedor) {
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor) {
    return vendedor.salario + (vendedor.valor_vendido * vendedor.prct_comissao);
}

void ImprimeRelatorioVendedor(tVendedor vendedor) {
    printf("\t%s > Total vendido: R$%.2f\n");
    printf("\t\tTotal recebido: R$%.2f\n");
}
