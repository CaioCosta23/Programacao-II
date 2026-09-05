#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"

#define CADASTRAR 1
#define REMOVER 2
#define LISTAR 3

#define MAX_CARACTERES 50

void imprimeMenu() {
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");

    printf("\n");
}

int main() {
    int quantidadeOperacoes, o;
    unsigned short int opcao;
    tBiblioteca biblioteca;
    unsigned short int encerrar = 0; // Variável lógica que indica se o programa deve ser encerrado precocemente;

    biblioteca = inicializarBiblioteca();

    scanf("%d\n", &quantidadeOperacoes);

    imprimeMenu();

    for(o = 0; o < quantidadeOperacoes; o++) {

        scanf("%hd\n", &opcao);

        switch(opcao) {
            case CADASTRAR:
                biblioteca = adicionarLivroNaBiblioteca(biblioteca, lerLivro());
                break;
            case REMOVER:
                char titulo[MAX_CARACTERES];
                
                scanf("%[^\n]\n", titulo);
                
                biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
                break;
            case LISTAR:
                listarLivrosDaBiblioteca(biblioteca);
                break;
            default:
                printf("Operacao invalida!\n");
                encerrar = 1;
                break;
        }

        if (encerrar) {
            break;
        }
    }

    return 0;
}