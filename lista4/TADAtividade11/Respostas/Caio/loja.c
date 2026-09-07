#include <stdio.h>
#include <stdlib.h>

#include "loja.h"

/**
 * @brief Verifica se um vendedor existe em uma lista de vendedores;
 * 
 * @param vendedores Lista/Vetor/'Array' de Tipos Abstratos de Dados (T.A.D.s) que represrntam as estruturas que contém as informações de um vendedores (com dados atuallizados);
 * @param totalVendedores Total da vendedores em uma loja;
 * @param nome Nome do vendedor procurado na lista de vendedores da loja;
 * @return short int Índice da posição do vendedor se o mesmo estiver presente na lista de vendedores ou -1, caso contrário;
 */
static short int encontraPosicaoVendedor(tVendedor vendedores[], int totalVendedores, char nome[]) {
    short int posicao = -1;
    int v;

    for(v = 0; v < totalVendedores; v++) {
        if (VerificaNomeVendedor(vendedores[v], nome)){
            posicao = v;
            break;
        }
    }
    return posicao;
}

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;
    loja.lucro = 0;
    loja.totalVendedores = 0;

    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    return (loja.id == id);
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
    short int posicao;

     posicao = encontraPosicaoVendedor(loja.vendedores, loja.totalVendedores, nome);

    if (posicao >= 0)
        loja.vendedores[posicao] = ContabilizaVenda(loja.vendedores[posicao], valor);
    
    return loja;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    if (encontraPosicaoVendedor(loja.vendedores, loja.totalVendedores, vendedor.nome) >=1)
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