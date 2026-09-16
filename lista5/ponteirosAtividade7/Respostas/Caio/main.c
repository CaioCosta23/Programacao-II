#include <stdio.h>
#include <stdlib.h>

#include "evento.h"

#define CADASTRAR 1
#define EXIBIR_EVENTOS 2
#define TROCAR_DATA 3
#define TROCAR_INDICES_POSICOES_LISTA_EVENTOS 4
#define SAIR 5

/**
 * @brief Exibe o menu de entrada do programa;
 * 
 */
void exibirMenu() {
    printf("===== Menu =====\n");
    printf("1 - Cadastrar um evento\n");
    printf("2 - Exibir todos os eventos\n");
    printf("3 - Trocar data de um evento\n");
    printf("4 - Trocar a posicao entre dois eventos\n");
    printf("5 - Sair\n");
}


/**
 * @brief Programa que lê as opções de menu para cadastrar eventos ou exibir lista/vetor/'array' de eventos
 * ou trocar data de eventos ou trocar posições de eventos na lista/vetor/'array' de eventos;
 * 
 * @return int Programa principal;
 */
int main() {
    unsigned short int opcao;
    unsigned short int sair = 0;
    int numeroEventos = 0;
    Evento eventos[MAX_EVENTOS];

    printf("\n");

    exibirMenu();

    while(1) {
        scanf("%hd", &opcao);

        switch (opcao) {
            case CADASTRAR:
                cadastrarEvento(eventos, &numeroEventos);
                break;
            case EXIBIR_EVENTOS:
                exibirEventos(eventos, &numeroEventos);
                break;
            case TROCAR_DATA:
                trocarDataEvento(eventos, &numeroEventos);
                break;
            case TROCAR_INDICES_POSICOES_LISTA_EVENTOS:
                int indice1, indice2;

                scanf("%d %d\n", &indice1, &indice2);
                trocarIndicesEventos(eventos, &indice1, &indice2, &numeroEventos);
                break;
            case SAIR:
                sair = 1;
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        if (sair)
            break;
    }
    return 0;
}