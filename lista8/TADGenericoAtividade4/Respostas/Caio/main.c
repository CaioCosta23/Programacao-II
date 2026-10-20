#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

/**
 * @brief Programa que Cria um banco, lê e insere ageências e contas nessas agências e por fim exibe um relatório dos dados do banco;
 * 
 * @return int Programa principal;
 */
int main() {
    tBanco *banco;
    char opcaoOperacao;
    const char ADICIONAR_AGENCIA = 'A', ADICIONAR_CONTA = 'C', FINALIZAR = 'F';

    banco = CriaBanco();

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
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}