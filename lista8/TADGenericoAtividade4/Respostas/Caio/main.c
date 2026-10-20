#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

#define ADICIONAR_AGENCIA 'A'
#define ADICIONAR_CONTA 'C'
#define FINALIZAR 'F'

/**
 * @brief Programa que Cria um banco, lê e insere ageências e contas nessas agências e por fim exibe um relatório dos dados do banco;
 * 
 * @return int Programa principal;
 */
int main() {
    tBanco *banco;
    char opcaoOperacao;

    banco = CriaBanco();
    
    LeBanco(banco);

    while (1) {
        scanf("%c\n", &opcaoOperacao);

        if (opcaoOperacao == FINALIZAR)
            break;

        switch(opcaoOperacao) {
            case ADICIONAR_AGENCIA:
                tAgencia *agencia;

                agencia = CriaAgencia();

                LeAgencia(agencia);

                AdicionaAgencia(banco, agencia);
                break;
            case ADICIONAR_CONTA:
                tConta *conta;
                unsigned int numeroAgencia;

                conta = CriaConta();

                LeConta(conta);

                scanf("%d\n", &numeroAgencia);

                InsereContaBanco(banco, numeroAgencia, conta);
                break;
            default:
                break;
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}