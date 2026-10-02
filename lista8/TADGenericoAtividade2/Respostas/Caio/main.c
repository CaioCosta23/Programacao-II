#include <stdio.h>
#include <stdlib.h>

#include "gerenciadorpacotes.h"

#define CADASTRAR 1
#define IMPRIMIR_PACOTE_ESPECIFICO 2
#define IMPRIMIR_LISTA_PACOTES 3

static void menu() {
    printf("Escolha uma opcao:\n");
    printf("(1) Cadastrar um novo pacote\n");
    printf("(2) Imprimir um pacote  especifico\n");
    printf("(3) Imprimir todos os pacotes e sair\n");
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


                scanf("%hd %d\n", &tipo, &numeroElementos);

                if ((opcao == INT) || (opcao == CHAR)) {
                    tPacote *pacote;

                    if (tipo == INT)
                        pacote = CriaPacote(INT, numeroElementos);
                    else
                        pacote = CriaPacote(CHAR, numeroElementos);

                    AdicionaPacoteNoGerenciador(gerenciador, pacote);
                }else {
                    printf("Erro! Opcao de tipo de pacote invalida.\n");
                    scanf("%*[^\n]\n");
                }
                break;
            case IMPRIMIR_PACOTE_ESPECIFICO:
                unsigned indicePosicao;

                scanf("%d\n", &indicePosicao);

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
    
    return 0;
}