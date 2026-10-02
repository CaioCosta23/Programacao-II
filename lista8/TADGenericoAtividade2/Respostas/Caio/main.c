#include <stdio.h>
#include <stdlib.h>

#include "gerenciadorpacotes.h"

#define CADASTRAR 1
#define IMPRIMIR_PACOTE_ESPECIFICO 2
#define IMPRIMIR_LISTA_PACOTES 3

static void menu() {
    printf("\nEscolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote  especifico\n");
    printf("\t(3) Imprimir todos os pacotes e sair\n");
}

int main() {
    tGerenciador *gerenciador;
    unsigned short int opcao;

    gerenciador = CriaGerenciador();

    do{
        menu();

        scanf("%hd", &opcao);

        switch(opcao) {
            case CADASTRAR:
                unsigned short int tipo;
                unsigned int numeroElementos;
                
                printf("Digite o tipo (0-char, 1-int) e o número de elementos do pacote/mensagem:");

                scanf("%hd %d", &tipo, &numeroElementos);

                if ((tipo == INT) || (tipo == CHAR)) {
                    tPacote *pacote;

                    if (tipo == INT)
                        pacote = CriaPacote(INT, numeroElementos);
                    else
                        pacote = CriaPacote(CHAR, numeroElementos);

                    LePacote(pacote);
                    AdicionaPacoteNoGerenciador(gerenciador, pacote);
                }else {
                    printf("Digite um tipo valido!\n");
                    scanf("%*c");
                }
                break;
            case IMPRIMIR_PACOTE_ESPECIFICO:
                unsigned int indicePosicao;

                scanf("%d", &indicePosicao);

                ImprimirPacoteNoIndice(gerenciador, indicePosicao);
                break;
            case IMPRIMIR_LISTA_PACOTES:
                ImprimirTodosPacotes(gerenciador);
                break;
            default:
                printf("Erro! Opcao invalida.\n");
                scanf("%*[^\n]\n");
                break;
        }
    } while(opcao != IMPRIMIR_LISTA_PACOTES);

    DestroiGerenciador(gerenciador);
    
    return 0;
}