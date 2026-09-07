#include <stdio.h>>
#include <stdlib.h>

#include "loja.h"

#define SAIR 0
#define ABRIR_LOJA 1
#define CONTRATAR_VENDEDOR 2
#define REGISTRAR_VENDA 3
#define RELATORIO_GERAL 4

#define TAMANHO_NOME 50

/**
 * @brief Busca uma lojana lista/vetor/'array' de lojas;
 * 
 * @param lojas Tipos Abstratos de Dados (T.A.D.s) que representam a estrutura que contém as informações (atualizadas) das lojas; 
 * @param quantidadeLojas Quantidade de lojas na lista/vetor/'array' de lojas;
 * @param id ID (Identificador - único) da loja procurada;
 * @return int Índice da posição da loja na lista de lojas caso a loja seja encontrada ou -1, caso contrário;
 */
static int encontraPosicaoLoja(tLoja lojas[], int quantidadeLojas ,int id) {
    int l;
    int posicao = -1;

    for(l = 0; l < quantidadeLojas; l++) {
        if (VerificaIdLoja(lojas[l], id)) {
            posicao = l;
            break;
        }
    }
    return posicao;
}


/**
 * @brief Programa que resgistra uma série de lojas e seus vendedores e contabiliza as vendas de cada vendedor
 * de cada loja e ao fim imprime relatŕorios de cada vendedor de cada loja;
 * 
 * @return int Programa principal;
 */
int main() {
    int quantidadeLojas, operacao;
    int posicaoLoja = 0;
    int idLoja, posicaoBuscada;
    char nome[TAMANHO_NOME];

    scanf("%d\n", &quantidadeLojas);

    tLoja lojas[quantidadeLojas];
    
    do {
        scanf("%d\n", &operacao);

        switch(operacao) {
            case ABRIR_LOJA:
                int id;
                float aluguel;

                scanf("%d %f\n", &id, &aluguel);

                lojas[posicaoLoja++] = AbreLoja(id, aluguel);
                break;
            case CONTRATAR_VENDEDOR:
                float salario, porcentagemComissao;

                scanf("%s %f %f\n", nome, &salario, &porcentagemComissao);
                scanf("%d\n", &idLoja);

                posicaoBuscada = encontraPosicaoLoja(lojas, (posicaoLoja + 1), idLoja);
                
                if (posicaoBuscada >= 0)
                    lojas[posicaoBuscada] = ContrataVendedor(lojas[posicaoBuscada], RegistraVendedor(nome,salario, porcentagemComissao));
                
                break;
            case REGISTRAR_VENDA:
                float valorVenda;

                scanf("%d %s %f\n", &idLoja, nome, valorVenda);

                posicaoBuscada = encontraPosicaoLoja(lojas, (posicaoLoja + 1), idLoja);
                
                if (posicaoBuscada >= 0)
                    lojas[posicaoBuscada] = RegistraVenda(lojas[posicaoBuscada], nome, valorVenda);
                
                break;
            case RELATORIO_GERAL:
                int l;

                for(l = 0; l <= posicaoLoja; l++) {
                    lojas[l] = CalculaLucro(lojas[l]);
                    ImprimeRelatorioLoja(lojas[l]);
                }
                break;
            case SAIR:
               break;
            default:
                printf("Erro! Operacao invalida.");
                operacao = SAIR;
                break;
        }
    }while(operacao != SAIR);

    return 0;
}