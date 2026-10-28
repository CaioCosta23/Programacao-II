#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

#define ADICIONAR_CONTA 'A'
#define DEPOSITO 'D'
#define SAQUE 'S'
#define TRANSFERENCIA 'T'
#define RELATORIO 'R'
#define FINALIZAR 'F'

/**
 * @brief Programa que simula o funcionamento de um sistema de banco;
 * 
 * @return int Programa principal;
 */
int main() {
    char opcao;
    tBanco *banco;
    unsigned short int finalizar = 0; // Variáavel lógica para verificar se o prgrama deve ser encerrado;

    banco = CriaBanco();
    
    while(1) {
        scanf("%c\n", &opcao);

        switch(opcao) {
            case ADICIONAR_CONTA:
                AbreContaBanco(banco);
                break;
            case SAQUE:
                SaqueContaBanco(banco);
                break;
            case DEPOSITO:
                DepositoContaBanco(banco);
                break;
            case TRANSFERENCIA:
                TransferenciaContaBanco(banco);
                break;
            case FINALIZAR:
                finalizar = 1;
                break;
            case RELATORIO:
                ImprimeRelatorioBanco(banco);
                break;
            default:
                break;
        }

        if (finalizar)
            break;
    }
    DestroiBanco(banco);

    return 0;
}