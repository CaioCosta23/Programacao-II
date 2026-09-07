#include <stdio.h>
#include <stdlib.h>

#include "loja.h"

/**
 * @brief Verifica se um vendedor existe em uma lista de vendedores;
 * 
 * @param vendedores Lista/Vetor/'Array' de Tipos Abstratos de Dados (T.A.D.s) que represrntam as estruturas que contém as informações de um vendedores (com dados atuallizados);
 * @param totalVendedores Total da vendedores em uma loja;
 * @param vendedor Tipo Abstrato de Dado (T.A.D.) que representa a estrutura que contém as informações de um vendedor (com dados atuallizados);
 * @return unsigned short int 1 (vedadeiro) se o vendedor está presente na lista de vendedores ou 0 (falso), caso contrário;
 */
static unsigned short int encontraVendedor(tVendedor vendedores[], int totalVendedores, tVendedor vendedor) {
    unsigned short int encontrado = 0; // Variável lógica;
    int v;

    for(v = 0; v < totalVendedores; v++) {
        if (VerificaNomeVendedor(vendedores[v], vendedor.nome)){
            encontrado = 1;
            break;
        }
    }
    return encontrado;
}

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;
    loja.lucro = 0;
    loja.totalVendedores = 0;

    return loja;
}

int VerificaLoja(tLoja loja, int id) {
    return (loja.id == id);
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    if (!(encontraVendedor(loja.vendedores, loja.totalVendedores, vendedor)))
        loja.vendedores[loja.totalVendedores++] = vendedor;
    
    return loja;        
}

tLoja CalculaLucro(tLoja loja) {
    int v;

    loja.lucro -= loja.aluguel;

    for(v = 0; v < loja.totalVendedores; v++) {
        loja.lucro += (GetTotalVendido(loja.vendedores[v]) - GetTotalRecebido(loja.vendedores[v]));
    }
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    int v;

    loja = CalculaLucro(loja);

    printf("Loja %d: Lucro total: R$%.2f\n", loja.id, loja.lucro);
    for(v = 0; v < loja.totalVendedores; v++) {
        ImprimeRelatorioVendedor(loja.vendedores[v]);
    }
}